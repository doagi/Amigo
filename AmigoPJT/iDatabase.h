#pragma once

#include <string>
#include "command.h"

class IDatabase
{
public:
    virtual string Query(Command cmd) = 0;
#if 0
    map<string, int> GetSupportedCmds()
    {
        return supported_cmds;
    }
#endif

protected:
    //map<string, int> supported_cmds;
};
