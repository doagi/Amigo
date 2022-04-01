#include "mod.h"

using namespace std;

vector<string> Mod(unordered_map<unsigned int, Employee2>& map_employees,
    const vector<unsigned int>& found_data, const ModificationInfo& mod_info)
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

void ModifyColumnData(Employee2& employee, const ModificationInfo& mod_info)
{
    switch (mod_info.column)
    {
    case Column::EMPLOYEENUM:
        employee.SetEmployeeNumber(mod_info.value);
        return;
    case Column::NAME:
        employee.SetName(mod_info.value);
        return;
    case Column::CL:
        employee.SetCareeLevel(mod_info.value);
        return;
    case Column::PHONENUM:
        employee.SetPhoneNumber(mod_info.value);
        return;
    case Column::BIRTHDAY:
        employee.SetBirthDay(mod_info.value);
        return;
    case Column::CERTI:
        employee.SetCerti(mod_info.value);
        return;
    }

    throw invalid_argument("Unknown Column : " + to_string((size_t)mod_info.column));
}
