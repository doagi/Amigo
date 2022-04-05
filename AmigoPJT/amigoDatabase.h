#pragma once

#include "IDatabase.h"
#include "amigoSearchEngine.h"

class AmigoDatabase : public IDatabase
{
public:
    AmigoDatabase()
    {
#if 0
        supported_cmds.clear();
        supported_cmds["ADD"] = (int)(CommandType::AddCommand);
        supported_cmds["DEL"] = (int)(CommandType::DelCommand);
        supported_cmds["MOD"] = (int)(CommandType::ModCommand);
        supported_cmds["SCH"] = (int)(CommandType::SchCommand);
#endif
        amigo_search_engine = new AmigoSearchEngine(map_employees);
    }

    virtual string Query(Command cmd) override;

private:
    int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
    vector<unsigned int> Search(string option, string column, string value);
    int Mod(const vector<unsigned int>& founds, string column, string value);
    void ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);
    void Del(const vector<unsigned int>& deleteList);


    string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);


    /*
    vector<string> Mod(unordered_map<unsigned int, Employee>& map_employees,
        const vector<unsigned int>& found_data, const ModificationInfo& condition);
        */

        
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