#include "outputStream.h"

void OutputStream::SetOutputTxt(string src_txt_path)
{
    output_stream.open(src_txt_path);
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