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
        supported_cmds_funcs["ADD"] = &AmigoDatabase::_Add;
        supported_cmds_funcs["DEL"] = &AmigoDatabase::_Del;
        supported_cmds_funcs["MOD"] = &AmigoDatabase::_Mod;
        supported_cmds_funcs["SCH"] = &AmigoDatabase::_Sch;

        amigo_search_engine = new AmigoSearchEngine(map_employees);
    }

    virtual string Query(Command cmd) override;

private:
    string _Add(Command& cmd);
    string _Del(Command& cmd);
    string _Mod(Command& cmd);
    string _Sch(Command& cmd);

    int __Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
    vector<unsigned int> __Search(string option, string column, string value);
    void __Del(const vector<unsigned int>& deleteList);
    void __Mod(const vector<unsigned int>& founds, string column, string value);
    void __ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);

    string __GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string __GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);
    
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