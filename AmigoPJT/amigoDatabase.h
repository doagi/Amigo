#pragma once

#include "IDatabase.h"

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
    }

    virtual string Query(Command cmd) override;

private:
    int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
    vector<unsigned int> Sch(string op1, string op2, string column, string value);
    int Mod(const vector<unsigned int>& founds, string column, string value);

    string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);

    string Del(unordered_map<unsigned int, Employee>& employee, vector<unsigned int> deleteList);

    vector<string> Mod(unordered_map<unsigned int, Employee>& map_employees,
        const vector<unsigned int>& found_data, const ModificationInfo& condition);

    void ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);

    unordered_map<unsigned int, Employee> map_employees;
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