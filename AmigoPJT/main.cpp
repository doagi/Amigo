#include <iostream>
#include <fstream>
#include "common.h"
#include "cmd_parser.h"
#include "search1.h"
#include "command.h"

using namespace std;

unordered_map<unsigned int, Employee> employees;
vector<Command> commands;

int main(int argc, char** argv) 
{
	//TODO : main �Լ��� argv[1]�� �޾ƿ����� ���� �ʿ�
	string Path = "input_20_20.txt"; 
	int result;

	commands = ParserFromTxt(Path);

	CommandRun(commands, employees);

	return 0;
}