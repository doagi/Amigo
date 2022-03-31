#include <iostream>
#include <fstream>

#include "common.h"
#include "cmd_parser.h"


using namespace std;

int main() 
{
	string Path = "input_20_20.txt";

	ParserFromTxt(Path);

	return 0;
}