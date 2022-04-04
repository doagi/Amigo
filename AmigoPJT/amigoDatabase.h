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
    int Mod(const vector<unsigned int>& founds, string column, string value);

    string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
    string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);

    void Del(const vector<unsigned int>& deleteList);

    /*
    vector<string> Mod(unordered_map<unsigned int, Employee>& map_employees,
        const vector<unsigned int>& found_data, const ModificationInfo& condition);
        */

    void ModifyColumnData(Employee& employee, const ModificationInfo& mod_info);

    //Search option�� ���� �Լ��� 
    vector<unsigned int> Search(string option2, string column, string target);
    vector<unsigned int> SearchByType(string& target, SearchType type);
    template <typename T> bool IsMatch(const std::pair<int, Employee>& employee, T target, SearchType type);
    SearchType GetSearchType(string option, string column);
    //void isValidSearch(string target, SearchType type);
    //void checkIsValidEmployeeNumber(string target);
    //void checkIsValidName(string target);
    //void checkIsValidFirstName(string target);
    //void checkIsValidLastName(string target);
    //void checkIsValidCL(string target);
    //void checkIsValidPhoneNumber(string target);
    //void checkIsValidMiddlePhoneNumber(string target);
    //void checkIsValidLastPhoneNumber(string target);
    //void checkIsValidBirthday(string target);
    //void checkIsValidBirthdayYear(string target);
    //void checkIsValidBirthdayMonth(string target);
    //void checkIsValidBirthdayDay(string target);
    //void checkIsValidCerti(string target);
    unordered_map<unsigned int, Employee> map_employees;
};

class AmigoDatabase2 : public AmigoDatabase
{
public:
    virtual string Query(Command cmd) override
    {
        // ���� cmd�� AmigoDatabase::add() �䷱������ ó��.

        return newFunc();
    }

private:
    // �ⱸ���� func�� �ű�� �ɵ�.
    string newFunc();
};