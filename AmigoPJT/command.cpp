#include "command.h"


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi)
{
    Employee newEmployee = Employee(employee_num, name, cl, phoneNum, birthday, certi);
    employees.push_back(newEmployee);

    return employees.size();
}

int Mod(string op1, string op2, string targetColumn, string targetValue, string srcColumn, string srcValue)
{
    return 0;
}

int Del(string op1, string op2, string column, string value)
{
    return 0;
}

int Sch(string op1, string op2, string column, string value)
{
    if(column == "birthday")
    {
        return SearchByBirthday(op2, value);
    }
    return 0;
}

void CommandRun(vector<Command> commands)
{
	int result;

	for (auto& a_command : commands)
	{
		if (a_command.param[0] == "ADD")
		{
			result = Add(a_command.param[4], a_command.param[5], a_command.param[6], a_command.param[7], a_command.param[8], a_command.param[9]);
		}
		else if (a_command.param[0] == "SCH")
		{
			result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5]);

		}
		else if (a_command.param[0] == "DEL")
		{
			result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5]);

			Del(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5]);

		}
		else if (a_command.param[0] == "MOD")
		{
			result = Sch(a_command.param[1], a_command.param[2], a_command.param[4], a_command.param[5]);

		}
		else
		{
			//exception case
		}
		//일단 갯수만 출력하도록 함
		if (a_command.param[0] != "ADD")
		{
			cout << a_command.param[0] << ", " << result << endl;
		}
	}
}