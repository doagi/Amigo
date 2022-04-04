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
    // 기구현된 func들 옮기면 될듯.
    string add();
    string del();
 
    string mod();

    //Search option에 따른 함수들 
    //TODO : 중복코드 제거, 다형성 적용 등 필요할 듯...
    vector<unsigned int> Search(string option2, string column, string target);
    vector<unsigned int> searchByType(string target, SearchType type);
    template <typename T> bool isMatch(const std::pair<int, Employee2>& employee, T target, SearchType type);
    SearchType getSearchType(string option, string column);
    //void isValidSearch(string target, SearchType type);
    //void checkIsValidEmployeeNumber(string target);
    //void checkIsValidName(string target);
    //void checkIsValidFirstName(string target);
    //void checkIsValidLastName(string target);
    //void checkIsValidCL(string target);
    //void checkIsValidPhoneNumber(string target);
    //void checkIsValidMiddlePhoneNumber(string target);
    //void checkIsValidLastPhoneNumber(string target);
    //void checkIsValidBirthday(string target);
    //void checkIsValidBirthdayYear(string target);
    //void checkIsValidBirthdayMonth(string target);
    //void checkIsValidBirthdayDay(string target);
    //void checkIsValidCerti(string target);
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