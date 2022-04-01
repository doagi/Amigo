#include "searchByName.h"

vector<unsigned int> searchByName(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.full_name != target) continue;
		result.emplace_back(aData.first); // TODO : return ���� �����Ͽ� Sort �����ϱ�
	}
	return result;
}

vector<unsigned int> searchByFirstName(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.first_name != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByLastName(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.last_name != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}