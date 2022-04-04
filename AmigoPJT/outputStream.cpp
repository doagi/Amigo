#include "outputStream.h"

void OutputStream::SetOutputPath(string path)
{
    output_stream.open(path);

    if (!output_stream.is_open())
    {
        throw invalid_argument("Can't open output stream");
    }
}

void OutputStream::Output(string str)
{
    if (output_stream.is_open())
    {
        output_stream << str << endl;
    }
    else
    {
        cout << str << endl;
    }
}