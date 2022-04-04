#pragma once

#include "inputStream.h"
#include "outputStream.h"


class IDatabase
{
public:
    virtual string Query() = 0;
};

class AmigoDatabase : public IDatabase
{
public:
    virtual string Query() override
    {

    }

private:
    // 기구현된 func들 옮기면 될듯.
    string add();
    string del();
    string sch();
    string mod();
};

class ICommandHandler
{
public:
    virtual string Process(Command cmd) = 0;

protected:
    IDatabase* database;
};

class AddCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // add 함수구현에 맞는 param setting 필요
    }
};

class DelCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // del 함수구현에 맞는 param setting 필요
    }
};

class SchCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // sch 함수구현에 맞는 param setting 필요
    }
};

class ModCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // mod 함수구현에 맞는 param setting 필요
    }
};

enum CommandType
{
    CommandType_start = 0,
    AddCommand = CommandType_start,
    DelCommand,
    SchCommand,
    ModCommand,
    CommandType_end,
};

class Client
{
public:
    Client() {}
    ~Client() {}
    void Run();
private:
    InputStream iStream;
    OutputStream oStream;
    
    ICommandHandler* Commands[CommandType_end];
};