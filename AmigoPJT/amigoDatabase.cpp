#include <map>
#include "amigoDatabase.h"
#include "search.h"

string AmigoDatabase::Query(Command cmd)
{
    string command = cmd.GetCommandType();
    string option1 = cmd.param[1];
    string option2 = cmd.param[2];
    vector<unsigned int> search_result;
    string result;

    if (command == "ADD")
    {
        Add(cmd.param[4], cmd.param[5], cmd.param[6],
            cmd.param[7], cmd.param[8], cmd.param[9]);
    }
    else if (command == "SCH")
    {
        search_result = Search(option2, cmd.param[4], cmd.param[5]);

        result = GenerateCommandRecord(command, (option1 == "-p"), search_result);
    }
    else if (command == "DEL")
    {
        search_result = Search(option2, cmd.param[4], cmd.param[5]);

        result = GenerateCommandRecord(command, (option1 == "-p"), search_result);

        Del(search_result);
    }
    else if (command == "MOD")
    {
        search_result = Search(option2, cmd.param[4], cmd.param[5]);

        result = GenerateCommandRecord(command, (option1 == "-p"), search_result);

        Mod(search_result, cmd.param[6], cmd.param[7]);
    }
    else
    {
        throw runtime_error("Unsupported Command : " + command);
    }

    return result;
}

int AmigoDatabase::Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi)
{
    Employee newEmployee = Employee(employee_num, name, cl, phoneNum, birthday, certi);
    map_employees[newEmployee.employee_num] = newEmployee;

    return map_employees.size();
}

vector<unsigned int> AmigoDatabase::Search(string option, string column, string value)
{
    //isValidSearch(value, getSearchType(option, column));
    return SearchByType(value, GetSearchType(option, column));
}

void AmigoDatabase::Del(const vector<unsigned int>& deleteList)
{
    for (int i = 0; i < deleteList.size(); i++)
    {
        map_employees.erase(deleteList[i]);
    }
}

int AmigoDatabase::Mod(const vector<unsigned int>& founds, string column, string value)
{
    static map<string, Column> column_map
    {
        {"employeeNum", Column::EMPLOYEENUM},
        {"name",        Column::NAME},
        {"cl",          Column::CL},
        {"phoneNum",    Column::PHONENUM},
        {"birthday",    Column::BIRTHDAY},
        {"certi",       Column::CERTI}
    };

    if (column == "employeeNum")
    {
        throw invalid_argument("Can't modify Column::EMPLOYEENUM");
    }

    for (const auto& employee_num : founds)
    {
        auto& employee = map_employees[employee_num];
        ModifyColumnData(employee, ModificationInfo{ column_map[column], value });
    }

    return founds.size();
}

string AmigoDatabase::GenerateCommandRecord(const std::string& command, const bool& is_print_list, const vector<unsigned int>& targets)
{
    if (targets.size() < 1)
    {
        return command + ",NONE";
    }

    if (!is_print_list)
    {
        return command + "," + to_string(targets.size());
    }

    return GenerateDetailRecord(command, targets);
}

string AmigoDatabase::GenerateDetailRecord(const std::string& command, const vector<unsigned int>& targets)
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

/* 없애도 될 것 같음 : 위에 있는 Mod 함수에서 처리 하도록 함
vector<string> AmigoDatabase::Mod(unordered_map<unsigned int, Employee>& map_employees,
    const vector<unsigned int>& found_data, const ModificationInfo& mod_info)
{
    if (mod_info.column == Column::EMPLOYEENUM)
    {
        throw invalid_argument("Can't modify Column::EMPLOYEENUM");
    }

    const string kTag = "MOD";

    vector<string> result;
    result.reserve(found_data.size());

    for (const auto& employee_num : found_data)
    {
        auto& employee = map_employees[employee_num];
        result.emplace_back(GenerateRecord(kTag, employee));
        ModifyColumnData(employee, mod_info);
    }

    return result;
}
*/

void AmigoDatabase::ModifyColumnData(Employee& employee, const ModificationInfo& mod_info)
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

    throw invalid_argument("Unknown Column : " + to_string((size_t)mod_info.column));
}