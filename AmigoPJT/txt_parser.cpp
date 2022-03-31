#include "cmd_parser.h"

vector<Command> ParserFromTxt(string src_txt_path)
{
	vector<Command> vect_cmds;

	string Path = src_txt_path;

	ifstream readFile(Path);
	if (readFile.is_open())
	{
		string str_line;
		while (!readFile.eof())
		{
			getline(readFile, str_line);

			if (str_line.length() <= 1)
			{
				break;
			}

			string delimiter = ",";

			size_t pos = 0;
			string token;
			int idx = 0;
			Command cur_cmd;

			while ((pos = str_line.find(delimiter)) != string::npos) {
				token = str_line.substr(0, pos);
				str_line.erase(0, pos + delimiter.length());
				cur_cmd.param[idx] = token;
				idx++;
			}

			cur_cmd.param[idx] = str_line;

			vect_cmds.push_back(cur_cmd);
			//cout << str_line << endl;
		}
		readFile.close();
	}

	return vect_cmds;
}
