#include <map>
#include "command.h"
#include "common.h"

int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi)
{
    Employee2 newEmployee = Employee2(employee_num, name, cl, phoneNum, birthday, certi);
    map_employees[newEmployee.employee_num] = newEmployee;

    return map_employees.size();
}

vector<unsigned int> Sch(string op1, string op2, string column, string value, unordered_map<unsigned int, Employee2> employees)
{
    vector<unsigned int> result;
    if(column == "birthday")
    {
        return SearchByBirthday(op2, value, employees);
    }
    else if(column == "name")
    {
        if(op2 == "-f")
        {
            return searchByFirstName(value, employees);
        }
        else if(op2 == "-l")
        {
            return searchByLastName(value, employees);
        }
        else
        {
            return searchByName(value, employees);
        }
    }
    else if(column == "phoneNum")
    {
        if (op2 == "-m")
        {
            return searchByMiddlePhoneNumber(stoi(value), employees);
        }
        else if (op2 == "-l")
        {
            return searchByLastPhoneNumber(stoi(value), employees);
        }
        else
        {
            return searchByPhoneNumber(value, employees);
        }
    }
    else if(column == "employeeNum")
    {
    
    }

    return result;
}

int Del(string op2, string column, string value) {
    // ToDo(한수용) : 구현

    return 0;
}

int Mod(const vector<unsigned int>& founds, string column, string value)
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

string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets)
{
    if (detail_print)
    {
        return GenerateDetailRecord(command, targets);
    }

    return GenerateSimpleRecord(command, targets.size());
}

string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& targets)
{
    string result = "";

    if (targets.size() > 0)
    {
        for (const auto& num : targets)
        {
            result += GenerateRecord(command, map_employees[num]) + "\n";
        }
    }
    else
    {
        result = command + ",NONE";
    }

    return result;
}

string GenerateSimpleRecord(const std::string& command, const size_t count)
{
    return command + "," + to_string(count);
}

void CommandRun(vector<Command> commands)
{
    int result = 0;
    vector<unsigned int> search_result;
    vector<string> output_records;

    for (auto& a_command : commands)
    {
        string command = a_command.param[0];
        string option1 = a_command.param[1];
        string option2 = a_command.param[2];

        if (command == "ADD")
        {
            result = Add(a_command.param[4], a_command.param[5], a_command.param[6],
                a_command.param[7], a_command.param[8], a_command.param[9]);
        }
        else if (command == "SCH")
        {
            search_result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5], map_employees);

            output_records.emplace_back(GenerateCommandRecord(command, (option1 == "-p"), search_result));
        }
        else if (command == "DEL")
        {
            search_result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5], map_employees);

            output_records.emplace_back(GenerateCommandRecord(command, (option1 == "-p"), search_result));

            result = Del(option2, a_command.param[4], a_command.param[5]);
        }
        else if (command == "MOD")
        {
            search_result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5], map_employees);

            output_records.emplace_back(GenerateCommandRecord(command, (option1 == "-p"), search_result));

            result = Mod(search_result, a_command.param[6], a_command.param[7]);
        }
        else
        {
            throw runtime_error("Unsupported Command : " + command);
        }
    }

    //ToDo(최인수) : 파일로 저장
    for (const string& record : output_records)
    {
        cout << record << endl;
    }
}

// from DelCommand.cpp

bool employeeNum(string a, Employee2 b)
{
    return a == b.str_employee_num;
}

bool name(string a, Employee2 b)
{
    return a == b.full_name;
}

bool cl(string a, Employee2 b)
{
    return a == b.cl;
}

bool phoneNum(string a, Employee2 b)
{
    return a == b.full_phone_number;
}

bool birthday(string a, Employee2 b)
{
    return a == b.full_birthday;
}

bool certi(string a, Employee2 b)
{
    return a == b.certi;
}

string Del(vector<Employee2>& employee, bool (*compare)(string, Employee2), string targetValue)
{

    int numTarget = 0;
    for (int i = 0; i < employee.size();)
    {
        if (compare(targetValue, employee[i]))
        {
            numTarget++;
            employee.erase(employee.begin() + i);
        }
        else
        {
            i++;
        }
    }

    if (numTarget == 0)
    {
        return "DEL,NONE";
    }
    else
    {
        return "DEL," + to_string(numTarget);
    }
}
