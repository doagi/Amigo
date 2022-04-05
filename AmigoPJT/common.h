#pragma once

#include <unordered_map>
#include <string>
#include "command.h"

using namespace std;

enum SearchType
{
    SearchType_start = 0,
    EMPLOYEE_NUM = SearchType_start,
    NAME,
    FIRST_NAME,
    LAST_NAME,
    CL,
    PHONE_NUMBER,
    MIDDLE_PHONE_NUMBER,
    LAST_PHONE_NUMBER,
    BIRTHDAY,
    BIRTHDAY_YEAR,
    BIRTHDAY_MONTH,
    BIRTHDAY_DAY,
    CERTI,
    SearchType_end,
    UNKNOWN
};

static unordered_map<string, SearchType> kFieldName
{
    {"",             UNKNOWN},
    {"employeeNum ", EMPLOYEE_NUM},
    {"name ",        NAME},
    {"name-f",       FIRST_NAME},
    {"name-l",       LAST_NAME},
    {"cl ",          CL},
    {"phoneNum ",    PHONE_NUMBER},
    {"phoneNum-m",   MIDDLE_PHONE_NUMBER},
    {"phoneNum-l",   LAST_PHONE_NUMBER},
    {"birthday ",    BIRTHDAY},
    {"birthday-y",   BIRTHDAY_YEAR},
    {"birthday-m",   BIRTHDAY_MONTH},
    {"birthday-d",   BIRTHDAY_DAY},
    {"certi ",       CERTI}
};

enum class Column : unsigned int
{
    UNKNOWN,
    EMPLOYEENUM,
    NAME,
    CL,
    PHONENUM,
    BIRTHDAY,
    CERTI,
    SIZE
};

static unordered_map<string, Column> kColumnMap
{
    {"",            Column::UNKNOWN},
    {"employeeNum", Column::EMPLOYEENUM},
    {"name",        Column::NAME},
    {"cl",          Column::CL},
    {"phoneNum",    Column::PHONENUM},
    {"birthday",    Column::BIRTHDAY},
    {"certi",       Column::CERTI}
};

struct ModificationInfo
{
    Column column;
    string value;
};