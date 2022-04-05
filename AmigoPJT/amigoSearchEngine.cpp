#include "amigoSearchEngine.h"


vector<unsigned int> AmigoSearchEngine::Search(string option, string column, string value)
{
    //isValidSearch(value, getSearchType(option, column));
    return SearchByType(value, GetSearchType(option, column));
}

template <typename T>
bool AmigoSearchEngine::IsMatch(const std::pair<int, Employee>& employee, T target, SearchType type) {
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



vector<unsigned int> AmigoSearchEngine::SearchByType(string& target, SearchType type) {
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

SearchType AmigoSearchEngine::GetSearchType(string option, string column)
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

void AmigoSearchEngine::isValidSearch(string target, SearchType type) {
    switch (type)
    {
    case EMPLOYEE_NUM:
        checkIsValidEmployeeNumber(target);
    case NAME:
        checkIsValidName(target);
    case FIRST_NAME:
        checkIsValidFirstName(target);
    case LAST_NAME:
        checkIsValidLastName(target);
    case CL:
        checkIsValidCL(target);
    case PHONE_NUMBER:
        checkIsValidPhoneNumber(target);
    case MIDDLE_PHONE_NUMBER:
        checkIsValidMiddlePhoneNumber(target);
    case LAST_PHONE_NUMBER:
        checkIsValidLastPhoneNumber(target);
    case BIRTHDAY:
        checkIsValidBirthday(target);
    case BIRTHDAY_YEAR:
        checkIsValidBirthdayYear(target);
    case BIRTHDAY_MONTH:
        checkIsValidBirthdayMonth(target);
    case BIRTHDAY_DAY:
        checkIsValidBirthdayDay(target);
    case CERTI:
        checkIsValidCerti(target);
    }
}
void AmigoSearchEngine::checkIsValidEmployeeNumber(string target)
{
    if (target.length() != 8)
    {
        throw std::length_error("Invalid Employee Number length.\n");
    }
    int entry_year = stoi(target.substr(0, 2));
    if (entry_year > 21 && entry_year < 69)
    {
        throw std::out_of_range("Invalid Employee Number. Entry year should be between 1969 and 2021.\n");
    }
}
bool isAllCapitalLetter(string target)
{
    for (int i = 0; i < target.length(); i++) {
        if (!isupper(target[i]) && !isspace(target[i]))
        {
            return false;
        }
        return true;
    }
}
void AmigoSearchEngine::checkIsValidName(string target)
{
    if (target.length() > 13)
    {
        throw std::length_error("Too long name.\n");
    }
    if (target.find(" ") == target.npos)
    {
        throw std::out_of_range("Name should be splitted by First name and Last name.\n");
    }
}
void AmigoSearchEngine::checkIsValidFirstName(string target)
{
    if (isAllCapitalLetter(target))
    {
        throw std::out_of_range("Name should be capital letter.\n");
    }
}
void AmigoSearchEngine::checkIsValidLastName(string target)
{
    if (isAllCapitalLetter(target))
    {
        throw std::out_of_range("Name should be capital letter.\n");
    }
}
void AmigoSearchEngine::checkIsValidCL(string target)
{
    if (target != "CL1" && target != "CL2" && target != "CL3" && target != "CL4")
    {
        throw std::out_of_range("Invalid CL.\n");
    }
}
void AmigoSearchEngine::checkIsValidPhoneNumber(string target)
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
}
void AmigoSearchEngine::checkIsValidMiddlePhoneNumber(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Phone Number length.\n");
    }
}
void AmigoSearchEngine::checkIsValidLastPhoneNumber(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Phone Number length.\n");
    }
}
void AmigoSearchEngine::checkIsValidBirthday(string target)
{
    if (target.length() != 8)
    {
        throw std::length_error("Invalid Birthday length.\n");
    }
    if (stoi(target.substr(0, 2)) != 19 && stoi(target.substr(0, 2)) != 20)
    {
        throw std::length_error("Invalid Birthday year.\n");
    }
}
void AmigoSearchEngine::checkIsValidBirthdayYear(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Birthday length.\n");
    }
    if (stoi(target.substr(0, 2)) != 19 && stoi(target.substr(0, 2)) != 20)
    {
        throw std::length_error("Invalid Birthday year.\n");
    }
}
void AmigoSearchEngine::checkIsValidBirthdayMonth(string target)
{
    if (target.length() != 2)
    {
        throw std::length_error("Invalid Birthday Month length.\n");
    }
    if (stoi(target.substr(0, 2)) > 0 && stoi(target.substr(0, 2)) < 13)
    {
        throw std::length_error("Invalid Birthday month.\n");
    }
}
void AmigoSearchEngine::checkIsValidBirthdayDay(string target)
{
    if (target.length() != 2)
    {
        throw std::length_error("Invalid Birthday Day length.\n");
    }
    if (stoi(target.substr(0, 2)) > 0 && stoi(target.substr(0, 2)) < 13)
    {
        throw std::length_error("Invalid Birthday date.\n");
    }
}
void AmigoSearchEngine::checkIsValidCerti(string target)
{
    if (target != "ADV" && target != "PRO" && target != "EX")
    {
        throw std::out_of_range("Invalid CL.\n");
    }
}