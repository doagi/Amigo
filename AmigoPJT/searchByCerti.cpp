#include "searchEtc.h"

vector<unsigned int> searchByCerti(string target, unordered_map<unsigned int, Employee2> data)
{
	if (target != "ADV" && target != "PRO" && target != "EX")
	{
		throw std::out_of_range("Invalid CL.\n");
	}
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.certi != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}