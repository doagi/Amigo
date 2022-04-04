#include "searchEtc.h"

vector<unsigned int> searchByCerti(string target, unordered_map<unsigned int, Employee> data)
{
	if (target != "ADV" && target != "PRO" && target != "EX")
	{
		printf("Invalid CL.\n");
		exit(EXIT_FAILURE);
	}
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.certi != target) continue;
		result.emplace_back(aData.first);
	}
	return result;
}