#pragma once

#include "common.h"
#include "iSearchEngine.h"


class AmigoSearchEngine : public ISearchEngine
{
public:
    AmigoSearchEngine(const unordered_map<unsigned int, Employee>& const map_employees_) : map_employees(map_employees_) {}
    virtual vector<unsigned int> Search(string option2, string column, string target) override;

private:
    vector<unsigned int> SearchByType(string& target, SearchType type);
    template <typename T> bool IsMatch(const Employee& employee, T target, SearchType type);
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

    const unordered_map<unsigned int, Employee>& const map_employees;
};
