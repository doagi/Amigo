#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "common.h"

using namespace std;

class InputStream
{
public:
    InputStream() {}

    InputStream(const string& path)
    {
        SetInputPath(path);
    }

    ~InputStream()
    {
        input_stream.close();
    }

    void SetInputPath(const string& path);

    Command Input();

private:
    ifstream input_stream;
};