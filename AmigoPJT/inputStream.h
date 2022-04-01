#pragma once

#include <fstream>
#include "Command.h"

class InputStream
{
public:
    InputStream() {}
    ~InputStream()
    {
        input_stream.close();
    }

    void SetInputTxt(string src_txt_path);
    Command Input();

private:
    ifstream input_stream;
};