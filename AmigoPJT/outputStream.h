#pragma once

#include <fstream>
#include "Command.h"

class OutputStream
{
public:
    OutputStream() {}

    OutputStream(string path)
    {
        SetOutputPath(path);
    }

    ~OutputStream()
    {
        output_stream.close();
    }

    void SetOutputPath(string file_path);

    void Output(string str);

private:
    ofstream output_stream;
};