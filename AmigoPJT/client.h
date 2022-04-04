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