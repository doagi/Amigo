#include "searchEtc.h"

vector<unsigned int> searchByEmployeeNumber(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	unsigned int find_key = stoi(target.substr(0, 2)) > 68 ? stoi("19" + target) : stoi("20" + target);
	auto aData = data.find(find_key);
	if (aData != data.end())
	{
		result.emplace_back(find_key);
	}
	return result;
}