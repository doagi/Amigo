#pragma once

#include <fstream>
#include "Command.h"

class OutputStream
{
public:
    OutputStream() {}
    ~OutputStream()
    {
        output_stream.close();
    }

    void SetOutputTxt(string src_txt_path);
    void Output(string str);

private:
    ofstream output_stream;
};