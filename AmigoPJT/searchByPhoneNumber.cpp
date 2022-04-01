#include "searchByPhoneNumber.h"

vector<unsigned int> searchByPhoneNumber(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.full_phone_number != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByMiddlePhoneNumber(unsigned int target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.middle_phone_num != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByLastPhoneNumber(unsigned int target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data) 
	{
		if (aData.second.last_phone_num != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}