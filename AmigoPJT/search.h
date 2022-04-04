#pragma once

#include "client.h"

template <typename T>
bool AmigoDatabase::IsMatch(const std::pair<int, Employee>& employee, T target, SearchType type) {
    switch (type)
    {
        case EMPLOYEE_NUM:
            return employee.second.str_employee_num == target;
        case NAME:
            return employee.second.full_name == target;
        case FIRST_NAME:
            return employee.second.first_name == target;
        case LAST_NAME:
            return employee.second.last_name == target;
        case CL:
            return employee.second.cl == target;
        case PHONE_NUMBER:
            return employee.second.full_phone_number == target;
        case MIDDLE_PHONE_NUMBER:
            return employee.second.middle_phone_num == stoi(target);
        case LAST_PHONE_NUMBER:
            return employee.second.last_phone_num == stoi(target);
        case BIRTHDAY:
            return employee.second.full_birthday == target;
        case BIRTHDAY_YEAR:
            return employee.second.year_birthday == stoi(target);
        case BIRTHDAY_MONTH:
            return employee.second.month_birthday == stoi(target);
        case BIRTHDAY_DAY:
            return employee.second.day_birthday == stoi(target);
        case CERTI:
            return employee.second.certi == target;

        default:
            return false;
    }
}

vector<unsigned int> AmigoDatabase::SearchByType(string& target, SearchType type) {
    vector<unsigned int> result;
    for (const auto& an_employee : map_employees)
    {
        if (IsMatch(an_employee, target, type))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

SearchType AmigoDatabase::GetSearchType(string option, string column) 
{
    if (column == "employeeNum") 
    {
        return EMPLOYEE_NUM;
    }
    else if (column == "birthday") 
    {
        if (option == " ")
        {
            return BIRTHDAY;
        }
        else if (option == "-y")
        {
            return BIRTHDAY_YEAR;
        }
        else if (option == "-m")
        {
            return BIRTHDAY_MONTH;
        }
        else if (option == "-d")
        {
            return BIRTHDAY_DAY;
        }
        else
        {
            throw invalid_argument("Invalid Column");
        }
    }
    else if (column == "name")
    {
        if (option == " ")
        {
            return NAME;
        }
        else if (option == "-f")
        {
            return FIRST_NAME;
        }
        else if (option == "-l")
        {
            return LAST_NAME;
        }
        else
        {
            throw invalid_argument("Invalid Column");
        }
    }
    else if (column == "phoneNum")
    {
        if (option == " ")
        {
            return PHONE_NUMBER;
        }
        else if (option == "-m")
        {
            return MIDDLE_PHONE_NUMBER;
        }
        else if (option == "-l")
        {
            return LAST_PHONE_NUMBER;
        }
        else
        {
            throw invalid_argument("Invalid Column");
        }
    }
    else if (column == "certi")
    {
        return CERTI;
    }
    else if (column == "cl")
    {
        return CL;
    }
    else
    {
        throw invalid_argument("Invalid Column");
    }
}

//void AmigoDatabase::isValidSearch(string target, SearchType type) {
//    switch (type)
//    {
//    case EMPLOYEE_NUM:
//        checkIsValidEmployeeNumber(target);
//    case NAME:
//        checkIsValidName(target);
//    case FIRST_NAME:
//        checkIsValidFirstName(target);
//    case LAST_NAME:
//        checkIsValidLastName(target);
//    case CL:
//        checkIsValidCL(target);
//    case PHONE_NUMBER:
//        checkIsValidPhoneNumber(target);
//    case MIDDLE_PHONE_NUMBER:
//        checkIsValidMiddlePhoneNumber(target);
//    case LAST_PHONE_NUMBER:
//        checkIsValidLastPhoneNumber(target);
//    case BIRTHDAY:
//        checkIsValidBirthday(target);
//    case BIRTHDAY_YEAR:
//        checkIsValidBirthdayYear(target);
//    case BIRTHDAY_MONTH:
//        checkIsValidBirthdayMonth(target);
//    case BIRTHDAY_DAY:
//        checkIsValidBirthdayDay(target);
//    case CERTI:
//        checkIsValidCerti(target);
//    }
//}
//void AmigoDatabase::checkIsValidEmployeeNumber(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidName(string target) 
//{
//
//}
//void AmigoDatabase::checkIsValidFirstName(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidLastName(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidCL(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidPhoneNumber(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidMiddlePhoneNumber(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidLastPhoneNumber(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidBirthday(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidBirthdayYear(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidBirthdayMonth(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidBirthdayDay(string target)
//{
//
//}
//void AmigoDatabase::checkIsValidCerti(string target)
//{
//
//}