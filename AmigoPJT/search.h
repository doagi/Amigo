#pragma once

#include "client.h"

vector<unsigned int> AmigoDatabase::SearchByYear(string target)
{
    vector<unsigned int> result;
    for (const auto& an_employee : map_employees)
    {
        if (an_employee.second.year_birthday == stoi(target))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

vector<unsigned int> AmigoDatabase::SearchByMonth(string target)
{
    vector<unsigned int> result;

    for (const auto& an_employee : map_employees)
    {
        if (an_employee.second.month_birthday == stoi(target))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}
vector<unsigned int> AmigoDatabase::SearchByDate(string target)
{
    vector<unsigned int> result;
    for (const auto& an_employee : map_employees)
    {
        if (an_employee.second.day_birthday == stoi(target))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

vector<unsigned int> AmigoDatabase::SearchByFullBirthday(string target)
{
    vector<unsigned int> result;
    for (const auto& an_employee : map_employees)
    {
        if (an_employee.second.full_birthday == target)
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

vector<unsigned int> AmigoDatabase::SearchByBirthday(string op2, string target)
{
    if (target.length() != 8)
    {
        printf("Invalid birthday length.\n");
        exit(EXIT_FAILURE);
    }

    if (op2 == "-y")
    {
        return SearchByYear(target);
    }
    else if (op2 == "-m")
    {
        return SearchByMonth(target);
    }
    else if (op2 == "-d")
    {
        return SearchByDate(target);
    }
    else if(op2 == " ")
    {
        return SearchByFullBirthday(target);
    }
    else
    {
        printf("Invalid birthday option. Only -d, -y or -m are available\n");
        exit(EXIT_FAILURE);
    }
}


vector<unsigned int> AmigoDatabase::searchByFullPhoneNumber(string target)
{
    if (target.length() != 13)
    {
        throw std::length_error("Invalid Phone Number length.\n");
    }
    if (target.substr(0, 4) != "010-")
    {
        throw std::out_of_range("Invalid Phone Number. Phone Number must start with 010-.\n");
    }
    if (target.substr(8, 1) != "-")
    {
        throw std::out_of_range("Invalid Phone Number. Phone Number format must be 010-XXXX-XXXX.\n");
    }
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.full_phone_number != target) continue;
        result.emplace_back(aData.first);
    }
    return result;
}

vector<unsigned int> AmigoDatabase::searchByMiddlePhoneNumber(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Middle Phone Number length.\n");
    }
    int target_int = stoi(target);
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.middle_phone_num != target_int) continue;
        result.emplace_back(aData.first);
    }
    return result;
}

vector<unsigned int> AmigoDatabase::searchByLastPhoneNumber(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Last Phone Number length.\n");
    }
    int target_int = stoi(target);
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.last_phone_num != target_int) continue;
        result.emplace_back(aData.first);
    }
    return result;
}
vector<unsigned int> AmigoDatabase::searchByPhoneNumber(string op2, string target)
{
    vector<unsigned int> employees;
    if (op2 == " ")
    {
        employees = searchByFullPhoneNumber(target);
    }
    else if (op2 == "-m")
    {
        employees = searchByMiddlePhoneNumber(target);
    }
    else if (op2 == "-l")
    {
        employees = searchByLastPhoneNumber(target);
    }
    else
    {
        throw std::out_of_range("Invalid PhoneNum option. Only -m or -l are available\n");
    }
    return employees;
}

vector<unsigned int> AmigoDatabase::searchByFullName(string target)
{
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.full_name != target) continue;
        result.emplace_back(aData.first);
    }
    return result;
}

vector<unsigned int> AmigoDatabase::searchByFirstName(string target)
{
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.first_name != target) continue;
        result.emplace_back(aData.first);
    }
    return result;
}

vector<unsigned int> AmigoDatabase::searchByLastName(string target)
{
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.last_name != target) continue;
        result.emplace_back(aData.first);
    }
    return result;
}
vector <unsigned int> AmigoDatabase::searchByName(string op2, string target) {
    if (target.length() > 13)
    {
        throw std::length_error("Too long name.\n");
    }
    vector<unsigned int> employees;
    if (op2 == " ")
    {
        employees = searchByFullName(target);
    }
    else if (op2 == "-f")
    {
        employees = searchByFirstName(target);
    }
    else if (op2 == "-l")
    {
        employees = searchByLastName(target);
    }
    else
    {
        printf("Invalid name option. Only -l or -f are available\n");
        exit(EXIT_FAILURE);
    }
    return employees;
}
vector<unsigned int> AmigoDatabase::searchByEmployeeNumber(string target)
{
    int entry_year = stoi(target.substr(0, 2));
    if (target.length() != 8)
    {
        printf("Invalid Employee Number length.\n");
        exit(EXIT_FAILURE);
    }
    if (entry_year > 21 && entry_year < 69)
    {
        throw std::out_of_range("Invalid name option. Only -l or -f are available\n");
    }
    vector<unsigned int> result;
    unsigned int find_key = entry_year > 68 ? stoi("19" + target) : stoi("20" + target);
    auto aData = map_employees.find(find_key);
    if (aData != map_employees.end())
    {
        result.emplace_back(find_key);
    }
    return result;
}
vector<unsigned int> AmigoDatabase::searchByCerti(string target)
{
    if (target != "ADV" && target != "PRO" && target != "EX")
    {
        throw std::out_of_range("Invalid CL.\n");
    }
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.certi != target) continue;
        result.emplace_back(aData.first);
    }
    return result;
}
vector<unsigned int> AmigoDatabase::searchByCl(string target)
{
    if (target != "CL1" && target != "CL2" && target != "CL3" && target != "CL4")
    {
        throw std::out_of_range("Invalid CL.\n");
    }
    vector<unsigned int> result;
    for (auto aData : map_employees)
    {
        if (aData.second.cl != target) continue;
        result.emplace_back(aData.first);
    }
    return result;
}
vector<unsigned int> AmigoDatabase::Search(string op2, string column, string value)
{
    vector<unsigned int> employees;
    if (column == "birthday")
    {
        employees = SearchByBirthday(op2, value);
    }
    else if (column == "name")
    {
        employees = searchByName(op2, value);
    }
    else if (column == "phoneNum")
    {
        employees = searchByPhoneNumber(op2, value);
    }
    else if (column == "employeeNum")
    {
        employees = searchByEmployeeNumber(value);
    }
    else if (column == "certi")
    {
        employees = searchByCerti(value);
    }
    else if (column == "cl")
    {
        employees = searchByCl(value);
    }
    return employees;
}
