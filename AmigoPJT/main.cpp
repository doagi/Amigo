#include <iostream>
#include <fstream>

#include "common.h"
#include "cmd_parser.h"
#include "search1.h"
#include "command.h"

#include "client.h"

using namespace std;

//unordered_map<unsigned int, Employee> employees;
vector<Command> commands;
unordered_map<unsigned int, Employee2> map_employees;

int main(int argc, char** argv) 
{
#if 0
	// App 진입 코드. 추후 enable
	Client amigo_client;

	amigo_client.Run();
#endif
	//TODO : main 함수의 argv[1]로 받아오도록 수정 필요
	string Path = "input_20_20.txt"; 
	int result;

	commands = ParserFromTxt(Path);

	CommandRun(commands);

	return 0;
}