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
    // �ⱸ���� func�� �ű�� �ɵ�.
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
        return database->Query(); // add �Լ������� �´� param setting �ʿ�
    }
};

class DelCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // del �Լ������� �´� param setting �ʿ�
    }
};

class SchCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // sch �Լ������� �´� param setting �ʿ�
    }
};

class ModCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(); // mod �Լ������� �´� param setting �ʿ�
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