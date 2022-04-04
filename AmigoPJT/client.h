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

            Del(search_result);
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

protected:
    unordered_map<unsigned int, Employee2> map_employees;

private:
    // �ⱸ���� func�� �ű�� �ɵ�.
    string add();
    string del();
 
    string mod();

    //Search option�� ���� �Լ��� 
    //TODO : �ߺ��ڵ� ����, ������ ���� �� �ʿ��� ��...
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
    virtual string Query(Command cmd) override
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


class Client
{
public:
    Client();

    Client(const string& input_path, const string& output_path);

    ~Client() = default;

    void Run(const bool& debug_print = false);

    void Run(const string & input_path, const string & output_path, const bool& debug_print = false);

private:    
    ICommandHandler* cmd_handlers[CommandType::CommandType_count];
    IDatabase* amigo_db;
    string input_path;
    string output_path;
};