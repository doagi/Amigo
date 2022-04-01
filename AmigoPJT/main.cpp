#include <iostream>
#include <fstream>
#include <unordered_map>

#include "common.h"
#include "cmd_parser.h"
#include "search1.h"
#include "command.h"

using namespace std;

vector<Employee> employees;
vector<Command> commands;
unordered_map<unsigned int, Employee2> map_employees;

int main(int argc, char** argv) 
{
	//TODO : main �Լ��� argv[1]�� �޾ƿ����� ���� �ʿ�
	string Path = "input_20_20.txt"; 
	int result;

	commands = ParserFromTxt(Path);

	CommandRun(commands);

	return 0;
}