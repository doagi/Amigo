#pragma once

#include <unordered_map>
#include <functional>
#include "IDatabase.h"
#include "command.h"
#include "employee.h"
#include "common.h"
#include "amigoSearchEngine.h"

class AmigoDatabase : public IDatabase
{
public:
    AmigoDatabase()
    {
        supported_cmds_funcs["ADD"] = &AmigoDatabase::Add;
        supported_cmds_funcs["DEL"] = &AmigoDatabase::Del;
        supported_cmds_funcs["MOD"] = &AmigoDatabase::Mod;
        supported_cmds_funcs["SCH"] = &AmigoDatabase::Sch;

        amigo_search_engine = new AmigoSearchEngine(map_employees);
    }

    virtual string Query(Command cmd) override;

private:
    string Add(Command& cmd);
    string Del(Command& cmd);
    string Mod(Command& cmd);
    string Sch(Command& cmd);

    int AddImpl(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
    vector<unsigned int> SearchImpl(string option, string column, string value);
    void DelImpl(const vector<unsigned int>& deleteList);
    void ModImpl(const vector<unsigned int>& founds, string column, string value);
    void ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);

    string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);
    
    unordered_map<string, function<string(AmigoDatabase&, Command&)>> supported_cmds_funcs;
    unordered_map<unsigned int, Employee> map_employees;
    ISearchEngine* amigo_search_engine;
};

class AmigoDatabase2 : public AmigoDatabase
{
public:
    virtual string Query(Command cmd) override
    {
        // 기존 cmd는 AmigoDatabase::add() 요런식으로 처리.

        return Swap();
    }

private:
    string Swap() { return ""; }
};