#pragma once

#include <unordered_map>
#include <string>
#include "employee.h"
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
    SearchType_end
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