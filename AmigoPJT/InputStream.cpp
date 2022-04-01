#include "inputStream.h"

void InputStream::SetInputTxt(string src_txt_path)
{
    input_stream.open(src_txt_path);
}

Command InputStream::Input()
{
    string str_line;

    if (input_stream.is_open())
    {
        getline(input_stream, str_line);
    }
    else
    {
        getline(cin, str_line);
    }

    if (str_line.length() <= 1)
    {
        return Command();
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

    return cur_cmd;
}