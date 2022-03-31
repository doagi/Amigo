#include "mod.h"

using namespace std;

vector<string> Mod(vector<EmployeeData>& found_data, const ConditonData& condition)
{
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
		break;
	case Column::NAME:
		data.name = condition.value;
		break;
	case Column::CL:
		data.cl = condition.value;
		break;
	case Column::PHONENUM:
		data.phoneNum = condition.value;
		break;
	case Column::BIRTHDAY:
		data.birthday = condition.value;
		break;
	case Column::CERTI:
		data.certi = condition.value;
		break;
	default:
		cout << "Unknown Column : " << (int)condition.column << endl;
	}
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
