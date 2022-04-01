#include "mod.h"

using namespace std;

vector<string> Mod(unordered_map<unsigned int, Employee2>& map_employees,
    vector<unsigned int>& found_data, const ModificationInfo& mod_info)
{
    if (mod_info.column == Column::EMPLOYEENUM)
    {
        throw invalid_argument("Can't modify Column::EMPLOYEENUM");
    }

    const string kTag = "MOD";

    vector<string> result;
    result.reserve(found_data.size());

    for (const auto& employee_num : found_data)
    {
        auto& employee = map_employees[employee_num];
        result.emplace_back(GenerateRecord(kTag, employee));
        ModifyColumnData(employee, mod_info);
    }

    return result;
}

string GenerateRecord(const std::string& cmd, Employee2& employee)
{
    string result = cmd + ", ";
    result += employee.str_employee_num + ", ";
    result += employee.full_name + ", ";
    result += employee.cl + ", ";
    result += employee.full_phone_number + ", ";
    result += employee.full_birthday + ", ";
    result += employee.certi;
    return result;
}

void ModifyColumnData(Employee2& employee, const ModificationInfo& mod_info)
{
    switch (mod_info.column)
    {
    case Column::EMPLOYEENUM:
        employee.str_employee_num = mod_info.value;
        // ToDo : set data.employee_num as numeric
        return;
    case Column::NAME:
        employee.full_name = mod_info.value;
        // ToDo : set data.first_name, data.last_name
        return;
    case Column::CL:
        employee.cl = mod_info.value;
        return;
    case Column::PHONENUM:
        employee.full_phone_number = mod_info.value;
        // ToDo : set data.middle_phone_num, data.last_phone_num as numeric
        return;
    case Column::BIRTHDAY:
        employee.full_birthday = mod_info.value;
        // ToDo : data.year_birthday, data.month_birthday, data.day_birthday as numeric
        return;
    case Column::CERTI:
        employee.certi = mod_info.value;
        return;
    }

    throw invalid_argument("Unknown Column : " + to_string((size_t)mod_info.column));
}
