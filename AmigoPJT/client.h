#pragma once

#include "amigoDatabase.h"
#include "inputStream.h"
#include "outputStream.h"
#include <string>

#if 0
#include "command.h"

class ICommandHandler
{
public:
    virtual string Process(Command cmd) = 0;
    void SetDatabase(IDatabase* database_)
    {
        database = database_;
    }

protected:
    IDatabase* database;
};

class NewCmdHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // newFunc �Լ������� �´� param setting �ʿ�
    }
};

class AddCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // add �Լ������� �´� param setting �ʿ�
    }
};

class DelCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // del �Լ������� �´� param setting �ʿ�
    }
};

class SchCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // sch �Լ������� �´� param setting �ʿ�
    }
};

class ModCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // mod �Լ������� �´� param setting �ʿ�
    }
};
#endif

class Client
{
public:
    Client();

    Client(const string& input_path, const string& output_path);

    ~Client() = default;

    void Run(const bool& debug_print = false);

    void Run(const string & input_path, const string & output_path, const bool& debug_print = false);

private:    
    //ICommandHandler* cmd_handlers[Command::Type::CommandType_count];
    IDatabase* amigo_db;
    string input_path;
    string output_path;
};