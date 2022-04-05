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
        supported_cmds.clear();
        supported_cmds["ADD"] = Command::Type::AddCommand;
        supported_cmds["DEL"] = Command::Type::DelCommand;
        supported_cmds["MOD"] = Command::Type::ModCommand;
        supported_cmds["SCH"] = Command::Type::SchCommand;

        cmd_func_ptrs[Command::Type::AddCommand] = &AmigoDatabase::_Add;
        cmd_func_ptrs[Command::Type::DelCommand] = &AmigoDatabase::_Del;
        cmd_func_ptrs[Command::Type::ModCommand] = &AmigoDatabase::_Mod;
        cmd_func_ptrs[Command::Type::SchCommand] = &AmigoDatabase::_Sch;

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
    
    function<string(AmigoDatabase&, Command&)> cmd_func_ptrs[Command::Type::CommandType_count];
    unordered_map<string, Command::Type> supported_cmds;

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