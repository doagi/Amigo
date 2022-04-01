#pragma once

#include "inputStream.h"

class Client
{
public:
    Client() {}
    ~Client() {}
    void Run();
private:
    InputStream iStream;

};