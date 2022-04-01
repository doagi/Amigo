#include "searchByPhoneNumber.h"

vector<int> searchByPhoneNumber(string target, unordered_map<int, Employee2> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i].full_phone_number != target) continue;
		result.emplace_back(i);
	}
	return result;
}

vector<int> searchByMiddlePhoneNumber(int target, unordered_map<int, Employee2> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		if (data[i].middle_phone_num != target) continue;
		result.emplace_back(i);
	}
	return result;
}

vector<int> searchByLastPhoneNumber(int target, unordered_map<int, Employee2> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		if (data[i].last_phone_num != target) continue;
		result.emplace_back(i);
	}
	return result;
}