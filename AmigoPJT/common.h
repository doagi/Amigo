#pragma once

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
    EMPLOYEENUM,
    NAME,
    CL,
    PHONENUM,
    BIRTHDAY,
    CERTI,
    SIZE
};

struct ModificationInfo
{
    Column column;
    string value;
};

static string GenerateRecord(const std::string& cmd, Employee& employee)
{
    return (cmd + "," + employee.ToString(','));
}
