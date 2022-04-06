#pragma once

#include "common.h"
#include "iSearchEngine.h"
#include "employee.h"


class AmigoSearchEngine : public ISearchEngine
{
public:
    AmigoSearchEngine(const unordered_map<unsigned int, Employee>& const map_employees_) : map_employees(map_employees_) {}
    virtual vector<unsigned int> Search(string option2, string column, string target) override;

private:
    vector<unsigned int> SearchByType(string& target, SearchType type);
    bool IsMatch(Employee employee, string target, SearchType type);
    SearchType GetSearchType(string option, string column);
    void IsValidSearch(string target, SearchType type);
    void CheckIsValidEmployeeNumber(string target);
    void CheckIsValidName(string target);
    void CheckIsValidFirstName(string target);
    void CheckIsValidLastName(string target);
    void CheckIsValidCL(string target);
    void CheckIsValidPhoneNumber(string target);
    void CheckIsValidMiddlePhoneNumber(string target);
    void CheckIsValidLastPhoneNumber(string target);
    void CheckIsValidBirthday(string target);
    void CheckIsValidBirthdayYear(string target);
    void CheckIsValidBirthdayMonth(string target);
    void CheckIsValidBirthdayDay(string target);
    void CheckIsValidCerti(string target);

    const unordered_map<unsigned int, Employee>& const map_employees;
};
