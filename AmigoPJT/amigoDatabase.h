#pragma once

#include <unordered_map>
#include "IDatabase.h"
#include "command.h"
#include "employee.h"
#include "common.h"

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
    }

    virtual string Query(Command cmd) override;

private:
    int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
    void Del(const vector<unsigned int>& deleteList);
    void Mod(const vector<unsigned int>& founds, string column, string value);
    void ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);

    string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);

    //Search option에 따른 함수들 
    vector<unsigned int> Search(string option2, string column, string target);
    vector<unsigned int> SearchByType(string& target, SearchType type);
    template <typename T> bool IsMatch(const std::pair<int, Employee>& employee, T target, SearchType type);
    SearchType GetSearchType(string option, string column);
    void isValidSearch(string target, SearchType type);
    void checkIsValidEmployeeNumber(string target);
    void checkIsValidName(string target);
    void checkIsValidFirstName(string target);
    void checkIsValidLastName(string target);
    void checkIsValidCL(string target);
    void checkIsValidPhoneNumber(string target);
    void checkIsValidMiddlePhoneNumber(string target);
    void checkIsValidLastPhoneNumber(string target);
    void checkIsValidBirthday(string target);
    void checkIsValidBirthdayYear(string target);
    void checkIsValidBirthdayMonth(string target);
    void checkIsValidBirthdayDay(string target);
    void checkIsValidCerti(string target);

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