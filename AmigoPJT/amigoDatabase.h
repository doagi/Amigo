#pragma once

#include <unordered_map>
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
#if 0
        supported_cmds.clear();
        supported_cmds["ADD"] = (int)(Command::Type::AddCommand);
        supported_cmds["DEL"] = (int)(Command::Type::DelCommand);
        supported_cmds["MOD"] = (int)(Command::Type::ModCommand);
        supported_cmds["SCH"] = (int)(Command::Type::SchCommand);
#endif
        amigo_search_engine = new AmigoSearchEngine(map_employees);
    }

    virtual string Query(Command cmd) override;

private:
    int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
    vector<unsigned int> Search(string option, string column, string value);
    void Del(const vector<unsigned int>& deleteList);
    void Mod(const vector<unsigned int>& founds, string column, string value);
    void ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);

    string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);

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