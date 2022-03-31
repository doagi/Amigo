#include "mod.h"

using namespace std;

vector<string> Mod(vector<EmployeeData>& found_data, const ConditonData& condition)
{
	if (condition.column == Column::EMPLOYEENUM)
	{
		throw invalid_argument("Can't modify Column::EMPLOYEENUM");
	}

	const string kTag = "MOD";

	vector<string> result;

	for (auto& data : found_data)
	{
		result.emplace_back(GenerateRecord(kTag, data));

		ModifyColumnData(condition, data);
	}

	return result;
}

void ModifyColumnData(const ConditonData& condition, EmployeeData& data)
{
	switch (condition.column)
	{
	case Column::EMPLOYEENUM:
		data.employeeNum = condition.value;
		return;
	case Column::NAME:
		data.name = condition.value;
		return;
	case Column::CL:
		data.cl = condition.value;
		return;
	case Column::PHONENUM:
		data.phoneNum = condition.value;
		return;
	case Column::BIRTHDAY:
		data.birthday = condition.value;
		return;
	case Column::CERTI:
		data.certi = condition.value;
		return;
	}

	throw invalid_argument("Unknown Column : " + to_string((size_t)condition.column));
}

string GenerateRecord(const std::string& cmd, EmployeeData& data)
{
	string result = cmd + ", ";
	result += data.employeeNum + ", ";
	result += data.name + ", ";
	result += data.cl + ", ";
	result += data.phoneNum + ", ";
	result += data.birthday + ", ";
	result += data.certi;
	return result;
}
