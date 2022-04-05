#pragma once

#include <string>

using namespace std;

struct Command
{
    enum
    {
        param_start = 0,
        cmd_type = param_start,
        op1,
        op2,
        op3,
        value1,
        value2,
        value3,
        value4,
        value5,
        value6,
        param_end,
        param_count = param_end - param_start
    };

    //enum Type
    //{
    //    CommandType_start = 0,
    //    AddCommand = CommandType_start,
    //    DelCommand,
    //    SchCommand,
    //    ModCommand,
    //    CommandType_end,
    //    CommandType_count = CommandType_end - CommandType_start
    //};

    Command()
    {
        is_valid = false;
        for (auto entry : param)
        {
            entry = "";
        }
    }

    bool IsValid()
    {
        return is_valid;
    }

    string GetCommandType()
    {
        return param[cmd_type];
    }

    string param[param_count];
    bool is_valid;
};