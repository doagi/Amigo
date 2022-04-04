#include <iostream>
#include <fstream>

#include "common.h"
#include "cmd_parser.h"
#include "command.h"

#include "client.h"

#define USE_ARGC_ARGV (0)

using namespace std;

//unordered_map<unsigned int, Employee> employees;
vector<Command> commands;
unordered_map<unsigned int, Employee2> map_employees;

int main(int argc, char** argv)
{
#if 0
    // Will enable to the code of client app
    Client amigo_client;

    amigo_client.Run();

#else

#if USE_ARGC_ARGV
    string Path = string(argv[1]);
#else
    string Path = "input_20_20.txt";
#endif

    commands = ParserFromTxt(Path);

    vector<string> result = CommandRun(commands);

    ofstream fout;
#if USE_ARGC_ARGV
    fout.open(string(argv[2]));
#else
    fout.open("output_20_20.txt");
#endif

    for (const string& outputTxt : result)
    {
        fout << outputTxt << endl;
    }
    fout.close();

#endif

#if _DEBUG
    Compare("output_20_20_ref.txt", "output_20_20.txt");
#endif

    return 0;
}
