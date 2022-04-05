#pragma once

#include <string>
#include "command.h"

class IDatabase
{
public:
    virtual string Query(Command cmd) = 0;
};
