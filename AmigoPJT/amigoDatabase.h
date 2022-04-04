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