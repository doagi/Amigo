#include "amigoSearchEngine.h"


vector<unsigned int> AmigoSearchEngine::Search(string option, string column, string value)
{
    IsValidSearch(value, GetSearchType(option, column));
    return SearchByType(value, GetSearchType(option, column));
}

bool AmigoSearchEngine::IsMatch(Employee employee, string target, SearchType type)
{
    return (target == employee.GetFieldValue(type));
}

vector<unsigned int> AmigoSearchEngine::SearchByType(string& target, SearchType type) 
{
    vector<unsigned int> result;
    for (auto an_employee : map_employees)
    {
        if (IsMatch(an_employee.second, target, type))
        {
            result.push_back(an_employee.second.GetEmployeeNum());
        }
    }
    return result;
}

SearchType AmigoSearchEngine::GetSearchType(string option, string column)
{
    return kFieldName[column.append(option)];
}

void AmigoSearchEngine::IsValidSearch(string target, SearchType type) {
    switch (type)
    {
    case EMPLOYEE_NUM:
        CheckIsValidEmployeeNumber(target);
        break;
    case NAME:
        CheckIsValidName(target);
        break;
    case FIRST_NAME:
        CheckIsValidFirstName(target);
        break;
    case LAST_NAME:
        CheckIsValidLastName(target);
        break;
    case CL:
        CheckIsValidCL(target);
        break;
    case PHONE_NUMBER:
        CheckIsValidPhoneNumber(target);
        break;
    case MIDDLE_PHONE_NUMBER:
        CheckIsValidMiddlePhoneNumber(target);
        break;
    case LAST_PHONE_NUMBER:
        CheckIsValidLastPhoneNumber(target);
        break;
    case BIRTHDAY:
        CheckIsValidBirthday(target);
        break;
    case BIRTHDAY_YEAR:
        CheckIsValidBirthdayYear(target);
        break;
    case BIRTHDAY_MONTH:
        CheckIsValidBirthdayMonth(target);
        break;
    case BIRTHDAY_DAY:
        CheckIsValidBirthdayDay(target);
        break;
    case CERTI:
        CheckIsValidCerti(target);
        break;

    default:
        throw invalid_argument("Invalid Column");
    }
}
void AmigoSearchEngine::CheckIsValidEmployeeNumber(string target)
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
void AmigoSearchEngine::CheckIsValidName(string target)
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
void AmigoSearchEngine::CheckIsValidFirstName(string target)
{
    if (!isAllCapitalLetter(target))
    {
        throw std::out_of_range("Name should be capital letter.\n");
    }
}
void AmigoSearchEngine::CheckIsValidLastName(string target)
{
    if (!isAllCapitalLetter(target))
    {
        throw std::out_of_range("Name should be capital letter.\n");
    }
}
void AmigoSearchEngine::CheckIsValidCL(string target)
{
    if (target != "CL1" && target != "CL2" && target != "CL3" && target != "CL4")
    {
        throw std::out_of_range("Invalid CL.\n");
    }
}
void AmigoSearchEngine::CheckIsValidPhoneNumber(string target)
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
void AmigoSearchEngine::CheckIsValidMiddlePhoneNumber(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Phone Number length.\n");
    }
}
void AmigoSearchEngine::CheckIsValidLastPhoneNumber(string target)
{
    if (target.length() != 4)
    {
        throw std::length_error("Invalid Phone Number length.\n");
    }
}
void AmigoSearchEngine::CheckIsValidBirthday(string target)
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
void AmigoSearchEngine::CheckIsValidBirthdayYear(string target)
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
void AmigoSearchEngine::CheckIsValidBirthdayMonth(string target)
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
void AmigoSearchEngine::CheckIsValidBirthdayDay(string target)
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
void AmigoSearchEngine::CheckIsValidCerti(string target)
{
    if (target != "ADV" && target != "PRO" && target != "EX")
    {
        throw std::out_of_range("Invalid Certi.\n");
    }
}