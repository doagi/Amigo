#include <map>
#include "amigoDatabase.h"
#include "search.h"

string AmigoDatabase::Query(Command cmd)
{
    string command = cmd.GetCommandType();

    auto cmd_type = supported_cmds.find(command);

    if (cmd_type != supported_cmds.end())
    {
        return cmd_func_ptrs[cmd_type->second](*this, cmd);
    }
    else
    {
        throw runtime_error("Unsupported Command : " + command);
    }
}

string AmigoDatabase::_Add(Command& cmd)
{
    __Add(cmd.param[4], cmd.param[5], cmd.param[6],
        cmd.param[7], cmd.param[8], cmd.param[9]);

    return string();
}

string AmigoDatabase::_Del(Command& cmd)
{
    string option1 = cmd.param[1];
    string option2 = cmd.param[2];
    vector<unsigned int> search_result;
    string result;

    search_result = __Search(option2, cmd.param[4], cmd.param[5]);

    result = __GenerateCommandRecord("DEL", (option1 == "-p"), search_result);

    __Del(search_result);

    return result;
}

string AmigoDatabase::_Mod(Command& cmd)
{
    string option1 = cmd.param[1];
    string option2 = cmd.param[2];
    vector<unsigned int> search_result;
    string result;

    search_result = __Search(option2, cmd.param[4], cmd.param[5]);

    result = __GenerateCommandRecord("MOD", (option1 == "-p"), search_result);

    __Mod(search_result, cmd.param[6], cmd.param[7]);

    return result;
}

string AmigoDatabase::_Sch(Command& cmd)
{
    string option1 = cmd.param[1];
    string option2 = cmd.param[2];
    vector<unsigned int> search_result;
    string result;

    search_result = __Search(option2, cmd.param[4], cmd.param[5]);

    result = __GenerateCommandRecord("SCH", (option1 == "-p"), search_result);

    return result;
}

int AmigoDatabase::__Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi)
{
    Employee newEmployee = Employee(employee_num, name, cl, phoneNum, birthday, certi);
    map_employees[newEmployee.employee_num] = newEmployee;

    return map_employees.size();
}

vector<unsigned int> AmigoDatabase::__Search(string option, string column, string value)
{
    return amigo_search_engine->Search(option, column, value);
}


void AmigoDatabase::__Del(const vector<unsigned int>& deleteList)
{
    for (int i = 0; i < deleteList.size(); i++)
    {
        map_employees.erase(deleteList[i]);
    }
}

void AmigoDatabase::__Mod(const vector<unsigned int>& founds, string column, string value)
{
    if (column == "employeeNum")
    {
        throw invalid_argument("Can't modify Column::EMPLOYEENUM");
    }

    for (const auto& employee_num : founds)
    {
        auto& employee = map_employees[employee_num];
        __ModifyColumnData(employee, ModificationInfo{ kColumnMap[column], value });
    }
}

void AmigoDatabase::__ModifyColumnData(Employee& employee, const ModificationInfo& mod_info)
{
    switch (mod_info.column)
    {
    case Column::EMPLOYEENUM:
        employee.SetEmployeeNumber(mod_info.value);
        return;
    case Column::NAME:
        employee.SetName(mod_info.value);
        return;
    case Column::CL:
        employee.SetCareerLevel(mod_info.value);
        return;
    case Column::PHONENUM:
        employee.SetPhoneNumber(mod_info.value);
        return;
    case Column::BIRTHDAY:
        employee.SetBirthDay(mod_info.value);
        return;
    case Column::CERTI:
        employee.SetCerti(mod_info.value);
        return;
    }

    throw invalid_argument("Unknown Column");
}

// ToDo(jbjempire): extract to other file or class
static string GenerateRecord(const std::string& cmd, Employee& employee)
{
    return (cmd + "," + employee.ToString(','));
}

string AmigoDatabase::__GenerateCommandRecord(const std::string& command, const bool& is_print_list, const vector<unsigned int>& targets)
{
    if (targets.size() < 1)
    {
        return command + ",NONE";
    }

    if (!is_print_list)
    {
        return command + "," + to_string(targets.size());
    }

    return __GenerateDetailRecord(command, targets);
}

string AmigoDatabase::__GenerateDetailRecord(const std::string& command, const vector<unsigned int>& targets)
{
    string result = "";
    map<unsigned int, Employee> sorted_results;
    const int kMaxPrintNum = 5;

    for (const auto& num : targets)
    {
        sorted_results.insert(pair<unsigned int, Employee>(num, map_employees[num]));
    }

    int num_data = 0;
    int max_iter = kMaxPrintNum;
    if (max_iter > sorted_results.size())
    {
        max_iter = sorted_results.size();
    }

    for (auto it = sorted_results.begin(); ((it != sorted_results.end()) && (num_data < kMaxPrintNum)); it++, num_data++)
    {
        result += GenerateRecord(command, it->second);
        result += (num_data < (max_iter - 1)) ? "\n" : "";
    }

    return result;
}
