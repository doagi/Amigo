#include "common.h"
#include "inputStream.h"

void InputStream::SetInputPath(const string& path)
{
    input_stream.open(path);

    if (!input_stream.is_open())
    {
        throw invalid_argument("Can't open input stream");
    }
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

    int index = 0;
    Command result;

    auto tokens = split(str_line, ',');
    for (const string& token : tokens)
    {
        result.param[index++] = token;
    }

    result.is_valid = true;

    return result;
}