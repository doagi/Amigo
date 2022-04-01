#include <iostream>
#include <fstream>
#include <map>

#include "common.h"
#include "cmd_parser.h"
#include "search1.h"
#include "command.h"

using namespace std;

vector<Employee> employees;
vector<Command> commands;
map<int, Employee2> map_employees;

int main(int argc, char** argv) 
{
	//TODO : main 함수의 argv[1]로 받아오도록 수정 필요
	string Path = "input_20_20.txt"; 
	int result;

	commands = ParserFromTxt(Path);

	CommandRun(commands);

	return 0;
}