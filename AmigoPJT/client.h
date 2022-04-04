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