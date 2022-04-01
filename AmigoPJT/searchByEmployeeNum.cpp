#include "searchEtc.h"

vector<unsigned int> searchByEmployeeNumber(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.str_employee_num != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}