
#include <map>
#include "amigoDatabase.h"
#include "search1.h"
#include "searchByName.h"
#include "searchByPhoneNumber.h"
#include "searchEtc.h"


string AmigoDatabase::Query(Command cmd)
{
    string command = cmd.param[0];
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
        search_result = Sch(cmd.param[1], cmd.param[2], cmd.param[4], cmd.param[5]);

        result = GenerateCommandRecord(command, (option1 == "-p"), search_result);
    }
    else if (command == "DEL")
    {
        search_result = Sch(cmd.param[1], cmd.param[2], cmd.param[4], cmd.param[5]);

        result = GenerateCommandRecord(command, (option1 == "-p"), search_result);

        Del(map_employees, search_result);
    }
    else if (command == "MOD")
    {
        search_result = Sch(cmd.param[1], cmd.param[2], cmd.param[4], cmd.param[5]);

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

vector<unsigned int> AmigoDatabase::Sch(string op1, string op2, string column, string value)
{
    vector<unsigned int> employees;
    if (column == "birthday")
    {
        employees = SearchByBirthday(op2, value, map_employees);
    }
    else if (column == "name")
    {
        if (op2 == "-f")
        {
            employees = searchByFirstName(value, map_employees);
        }
        else if (op2 == "-l")
        {
            employees = searchByLastName(value, map_employees);
        }
        else
        {
            employees = searchByName(value, map_employees);
        }
    }
    else if (column == "phoneNum")
    {
        if (op2 == "-m")
        {
            employees = searchByMiddlePhoneNumber(stoi(value), map_employees);
        }
        else if (op2 == "-l")
        {
            employees = searchByLastPhoneNumber(stoi(value), map_employees);
        }
        else
        {
            employees = searchByPhoneNumber(value, map_employees);
        }
    }
    else if (column == "employeeNum")
    {
        employees = searchByEmployeeNumber(value, map_employees);
    }
    else if (column == "certi")
    {
        employees = searchByCerti(value, map_employees);
    }
    else if (column == "cl")
    {
        employees = searchByCl(value, map_employees);
    }
    return employees;
}

string AmigoDatabase::Del(unordered_map<unsigned int, Employee>& employee, vector<unsigned int> deleteList)
{

    int numTarget = 0;
    for (int i = 0; i < deleteList.size(); i++)
    {
        employee.erase(deleteList[i]);
    }

    if (deleteList.size() == 0)
    {
        return "DEL,NONE";
    }
    else
    {
        return "DEL," + to_string(deleteList.size());
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

    auto result = Mod(map_employees, founds, ModificationInfo{ column_map[column], value });

    return result.size();
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