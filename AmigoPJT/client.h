#pragma once

#include "inputStream.h"
#include "outputStream.h"

class Client
{
public:
    Client() {}
    ~Client() {}
    void Run();
private:
    InputStream iStream;
    OutputStream oStream;
};