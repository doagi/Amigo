#pragma once

#include "inputStream.h"
#include "outputStream.h"
#include "common.h"
#include <map>
#include <string>

class IDatabase
{
public:
    virtual string Query() = 0;
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

    virtual string Query() override
    {
        return "";
    }

protected:
    unordered_map<unsigned int, Employee2> map_employees;

private:
    // 기구현된 func들 옮기면 될듯.
    string add();
    string del();
 
    string mod();

    //Search option에 따른 함수들 
    //TODO : 중복코드 제거, 다형성 적용 등 필요할 듯...
    vector<unsigned int> Search(string option2, string column, string target);
    vector<unsigned int> searchByCl(string target);
    vector<unsigned int> searchByCerti(string target);
    vector<unsigned int> searchByEmployeeNumber(string target);

    vector<unsigned int> searchByName(string option2, string target);
    vector<unsigned int> searchByFirstName(string target);
    vector<unsigned int> searchByLastName(string target);
    vector<unsigned int> searchByFullName(string target);

    vector<unsigned int> SearchByBirthday(string option2, string target);
    vector<unsigned int> SearchByYear(string target);
    vector<unsigned int> SearchByMonth(string target);
    vector<unsigned int> SearchByDate(string target);
    vector<unsigned int> SearchByFullBirthday(string target);

    vector<unsigned int> searchByPhoneNumber(string option2, string target);
    vector<unsigned int> searchByMiddlePhoneNumber(string target);
    vector<unsigned int> searchByLastPhoneNumber(string target);
    vector<unsigned int> searchByFullPhoneNumber(string target);
};

class AmigoDatabase2 : public AmigoDatabase
{
public:
    virtual string Query() override
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
        return database->Query(); // newFunc 함수구현에 맞는 param setting 필요
    }
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


class Client
{
public:
    Client()
    {
        amigo_db = new AmigoDatabase();

        map<string, int> SupportedCmdsFromAmigoDB = amigo_db->GetSupportedCmds();

        for (auto value : SupportedCmdsFromAmigoDB)
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
    
    ICommandHandler* cmd_handlers[CommandType::CommandType_end];
    IDatabase* amigo_db;
};