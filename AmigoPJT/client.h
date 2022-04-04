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
        return SupportedCmds;
    }

protected:
    map<string, int> SupportedCmds;
};

class AmigoDatabase : public IDatabase
{
public:
    AmigoDatabase()
    {
        SupportedCmds.clear();
        SupportedCmds["ADD"] = (int)(CommandType::AddCommand);
        SupportedCmds["DEL"] = (int)(CommandType::DelCommand);
        SupportedCmds["MOD"] = (int)(CommandType::ModCommand);
        SupportedCmds["SCH"] = (int)(CommandType::SchCommand);
    }

    virtual string Query() override
    {
        return "";
    }

private:
    // �ⱸ���� func�� �ű�� �ɵ�.
    string add();
    string del();
    string sch();
    string mod();
};

class AmigoDatabase2 : public AmigoDatabase
{
public:
    virtual string Query() override
    {
        // ���� cmd�� AmigoDatabase::add() �䷱������ ó��.

        return newFunc();
    }

private:
    // �ⱸ���� func�� �ű�� �ɵ�.
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
        return database->Query(); // newFunc �Լ������� �´� param setting �ʿ�
    }
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


class Client
{
public:
    Client()
    {
        AmigoDB = new AmigoDatabase();

        map<string, int> SupportedCmdsFromAmigoDB = AmigoDB->GetSupportedCmds();

        for (auto value : SupportedCmdsFromAmigoDB)
        {
            switch (value.second)
            {
            case AddCommand:
                cmdHandlers[value.second] = new AddCommandHandler();
                cmdHandlers[value.second]->SetDatabase(AmigoDB);
                break;
            case DelCommand:
                cmdHandlers[value.second] = new DelCommandHandler();
                cmdHandlers[value.second]->SetDatabase(AmigoDB);
                break;
            case ModCommand:
                cmdHandlers[value.second] = new ModCommandHandler();
                cmdHandlers[value.second]->SetDatabase(AmigoDB);
                break;
            case SchCommand:
                cmdHandlers[value.second] = new SchCommandHandler();
                cmdHandlers[value.second]->SetDatabase(AmigoDB);
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
    
    ICommandHandler* cmdHandlers[CommandType::CommandType_end];
    IDatabase* AmigoDB;
};