#include "searchEtc.h"

vector<unsigned int> searchByCl(string target, unordered_map<unsigned int, Employee2> data)
{
	if (target != "CL1" && target != "CL2" && target != "CL3" && target != "CL4")
	{
		throw std::out_of_range("Invalid CL.\n");
	}
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.cl != target)
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}