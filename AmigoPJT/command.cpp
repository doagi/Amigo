#include "command.h"

int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi)
{
//    Employee newEmployee = Employee(employee_num, name, cl, phoneNum, birthday, certi);
//   employees.push_back(newEmployee);

//    return employees.size();
    return 0;
}

int Mod(string op1, string op2, string targetColumn, string targetValue, string srcColumn, string srcValue)
{
    return 0;
}

int Del(string op1, string op2, string column, string value) {
	return 0;
}

vector<unsigned int> Sch(string op1, string op2, string column, string value, unordered_map<unsigned int, Employee> employees)
{
    if(column == "birthday")
    {
        return SearchByBirthday(op2, value, employees);
    }

}


void CommandRun(vector<Command> commands, unordered_map<unsigned int, Employee> employees)
{
    vector<unsigned int> search_result;

    for (auto& a_command : commands)
    {
        if (a_command.param[0] == "ADD")
        {
            Add(a_command.param[4], a_command.param[5], a_command.param[6], a_command.param[7], a_command.param[8], a_command.param[9]);
        }
        else if (a_command.param[0] == "SCH")
        {
            search_result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5], employees);

        }
        else if (a_command.param[0] == "DEL")
        {
            search_result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5], employees);

            //Del(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5]);

        }
        else if (a_command.param[0] == "MOD")
        {
            search_result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5], employees);

        }
        else
        {
            //exception case
        }
        //일단 갯수만 출력하도록 함
        if (a_command.param[0] != "ADD")
        {
            cout << a_command.param[0] << ", " << search_result.size() << endl;
        }
    }
}

// from DelCommand.cpp

bool employeeNum(string a, Employee b)
{
    return a == b.str_employee_num;
}

bool name(string a, Employee b)
{
    return a == b.full_name;
}

bool cl(string a, Employee b)
{
    return a == b.cl;
}

bool phoneNum(string a, Employee b)
{
    return a == b.full_phone_number;
}

bool birthday(string a, Employee b)
{
    return a == b.full_birthday;
}

bool certi(string a, Employee b)
{
    return a == b.certi;
}

string Del(vector<Employee>& employee, bool (*compare)(string, Employee), string targetValue)
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
