#pragma once

#include "inputStream.h"
#include "outputStream.h"
#include "common.h"
#include <map>
#include <string>

class IDatabase
{
public:
    virtual string Query(Command cmd) = 0;
    map<string, int> GetSupportedCmds()
    {
        return supported_cmds;
    }

protected:
    map<string, int> supported_cmds;
};

class AmigoDatabase : public IDatabase
{
public:
    AmigoDatabase()
    {
        supported_cmds.clear();
        supported_cmds["ADD"] = (int)(CommandType::AddCommand);
        supported_cmds["DEL"] = (int)(CommandType::DelCommand);
        supported_cmds["MOD"] = (int)(CommandType::ModCommand);
        supported_cmds["SCH"] = (int)(CommandType::SchCommand);
    }

    virtual string Query(Command cmd) override
    {
        string command = cmd.param[0];
        string option1 = cmd.param[1];
        string option2 = cmd.param[2];
        vector<unsigned int> search_result;
        string result;

        if (command == "ADD")
        {
            Add(cmd.param[4], cmd.param[5], cmd.param[6],
                cmd.param[7], cmd.param[8], cmd.param[9]);
        }
        else if (command == "SCH")
        {
            search_result = Sch(cmd.param[1], cmd.param[2], cmd.param[4], cmd.param[5]);

            result = GenerateCommandRecord(command, (option1 == "-p"), search_result);
        }
        else if (command == "DEL")
        {
            search_result = Sch(cmd.param[1], cmd.param[2], cmd.param[4], cmd.param[5]);

            result = GenerateCommandRecord(command, (option1 == "-p"), search_result);

            Del(map_employees, search_result);
        }
        else if (command == "MOD")
        {
            search_result = Sch(cmd.param[1], cmd.param[2], cmd.param[4], cmd.param[5]);

            result = GenerateCommandRecord(command, (option1 == "-p"), search_result);

            Mod(search_result, cmd.param[6], cmd.param[7]);
        }
        else
        {
            throw runtime_error("Unsupported Command : " + command);
        }

        return result;
    }

private:
    // 기구현된 func들 옮기면 될듯.
    string add();
    string del();
    string sch();
    string mod();
};

class AmigoDatabase2 : public AmigoDatabase
{
public:
    virtual string Query(Command cmd) override
    {
        // 기존 cmd는 AmigoDatabase::add() 요런식으로 처리.

        return newFunc();
    }

private:
    // 기구현된 func들 옮기면 될듯.
    string newFunc();
};


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
        return database->Query(cmd); // newFunc 함수구현에 맞는 param setting 필요
    }
};

class AddCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // add 함수구현에 맞는 param setting 필요
    }
};

class DelCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // del 함수구현에 맞는 param setting 필요
    }
};

class SchCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // sch 함수구현에 맞는 param setting 필요
    }
};

class ModCommandHandler : public ICommandHandler
{
    virtual string Process(Command cmd) override
    {
        return database->Query(cmd); // mod 함수구현에 맞는 param setting 필요
    }
};


class Client
{
public:
    Client()
    {
        amigo_db = new AmigoDatabase();

        map<string, int> supported_cmds_amigo_db = amigo_db->GetSupportedCmds();

        for (auto value : supported_cmds_amigo_db)
        {
            switch (value.second)
            {
            case AddCommand:
                cmd_handlers[value.second] = new AddCommandHandler();
                cmd_handlers[value.second]->SetDatabase(amigo_db);
                break;
            case DelCommand:
                cmd_handlers[value.second] = new DelCommandHandler();
                cmd_handlers[value.second]->SetDatabase(amigo_db);
                break;
            case ModCommand:
                cmd_handlers[value.second] = new ModCommandHandler();
                cmd_handlers[value.second]->SetDatabase(amigo_db);
                break;
            case SchCommand:
                cmd_handlers[value.second] = new SchCommandHandler();
                cmd_handlers[value.second]->SetDatabase(amigo_db);
                break;
            default:
                break;
            }
        }
    }
    ~Client() {}
    void Run();
private:
    InputStream iStream;
    OutputStream oStream;
    
    ICommandHandler* cmd_handlers[CommandType::CommandType_count];
    IDatabase* amigo_db;
};