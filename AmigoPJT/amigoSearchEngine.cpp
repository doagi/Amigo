#include "amigoSearchEngine.h"


vector<unsigned int> AmigoSearchEngine::Search(string option, string column, string value)
{
    isValidSearch(value, GetSearchType(option, column));
    return SearchByType(value, GetSearchType(option, column));
}

bool AmigoSearchEngine::IsMatch(Employee employee, string target, SearchType type)
{
    return (target == employee.GetFieldValue(type));
}

vector<unsigned int> AmigoSearchEngine::SearchByType(string& target, SearchType type) {
    vector<unsigned int> result;
    for (const auto& an_employee : map_employees)
    {
        if (IsMatch(an_employee.second, target, type))
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
        break;
    case NAME:
        checkIsValidName(target);
        break;
    case FIRST_NAME:
        checkIsValidFirstName(target);
        break;
    case LAST_NAME:
        checkIsValidLastName(target);
        break;
    case CL:
        checkIsValidCL(target);
        break;
    case PHONE_NUMBER:
        checkIsValidPhoneNumber(target);
        break;
    case MIDDLE_PHONE_NUMBER:
        checkIsValidMiddlePhoneNumber(target);
        break;
    case LAST_PHONE_NUMBER:
        checkIsValidLastPhoneNumber(target);
        break;
    case BIRTHDAY:
        checkIsValidBirthday(target);
        break;
    case BIRTHDAY_YEAR:
        checkIsValidBirthdayYear(target);
        break;
    case BIRTHDAY_MONTH:
        checkIsValidBirthdayMonth(target);
        break;
    case BIRTHDAY_DAY:
        checkIsValidBirthdayDay(target);
        break;
    case CERTI:
        checkIsValidCerti(target);
        break;
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
    }
    return true;
}
void AmigoSearchEngine::checkIsValidName(string target)
{
    if (target.length() > 16)
    {
        throw std::length_error("Too long name.\n");
    }
    if (target.find(" ") == target.npos)
    {
        throw std::out_of_range("Name should be splitted by First name and Last name.\n");
    }
    if (!isAllCapitalLetter(target))
    {
        throw std::out_of_range("Name should be capital letter.\n");
    }
}
void AmigoSearchEngine::checkIsValidFirstName(string target)
{
    if (!isAllCapitalLetter(target))
    {
        throw std::out_of_range("Name should be capital letter.\n");
    }
}
void AmigoSearchEngine::checkIsValidLastName(string target)
{
    if (!isAllCapitalLetter(target))
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
    for (size_t i = 0; i < target.size(); i++) {
        if (i == 3 || i == 8) 
        {
            continue;
        }
        if (target.substr(i, 1) == "-")
        {
            throw std::out_of_range("Invalid Phone Number. Phone Number format must be 010-****-****.\n");
        }
    }
    if (target.substr(3, 1) != "-")
    {
        throw std::out_of_range("Invalid Phone Number. Phone Number format must be 010-XXXX-****.\n");
    }
    if (target.substr(8, 1) != "-")
    {
        throw std::out_of_range("Invalid Phone Number. Phone Number format must be 010-****-XXXX.\n");
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
        throw std::invalid_argument("Invalid Birthday length.\n");
    }
    if (stoi(target.substr(4, 2)) == 0 || stoi(target.substr(4, 2)) > 12)
    {
        throw std::invalid_argument("Invalid Birthday month.\n");
    }
    if (stoi(target.substr(6, 2)) == 0 || stoi(target.substr(6, 2)) > 31)
    {
        throw std::invalid_argument("Invalid Birthday date.\n");
    }
    for (size_t i = 0; i < target.size(); i++)
    {
        if (!isdigit(target[i]))
        {
            throw std::invalid_argument("Birthday is not number.\n");
        }
    }
}
void AmigoSearchEngine::checkIsValidBirthdayYear(string target)
{
    if (target.length() != 4)
    {
        throw std::invalid_argument("Invalid Birthday length.\n");
    }
    for (size_t i = 0; i < target.size(); i++) 
    {
        if (!isdigit(target[i]))
        {
            throw std::invalid_argument("Birthday is not number.\n");
        }
    }
 }
void AmigoSearchEngine::checkIsValidBirthdayMonth(string target)
{
    if (target.length() != 2)
    {
        throw std::invalid_argument("Invalid Birthday Month length.\n");
    }
    if (stoi(target.substr(0, 2)) == 0 || stoi(target.substr(0, 2)) > 13)
    {
        throw std::invalid_argument("Invalid Birthday month.\n");
    }
    for (size_t i = 0; i < target.size(); i++)
    {
        if (!isdigit(target[i]))
        {
            throw std::invalid_argument("Birthday is not number.\n");
        }
    }
}
void AmigoSearchEngine::checkIsValidBirthdayDay(string target)
{
    if (target.length() != 2)
    {
        throw std::invalid_argument("Invalid Birthday Day length.\n");
    }
    if (stoi(target.substr(0, 2)) == 0 || stoi(target.substr(0, 2)) > 31)
    {
        throw std::invalid_argument("Invalid Birthday date.\n");
    }
    for (size_t i = 0; i < target.size(); i++)
    {
        if (!isdigit(target[i]))
        {
            throw std::invalid_argument("Birthday is not number.\n");
        }
    }
}
void AmigoSearchEngine::checkIsValidCerti(string target)
{
    if (target != "ADV" && target != "PRO" && target != "EX")
    {
        throw std::out_of_range("Invalid Certi.\n");
    }
}