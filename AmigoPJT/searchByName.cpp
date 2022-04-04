#include "searchByName.h"

vector <unsigned int> searchByName(string op2, string target, unordered_map<unsigned int, Employee2> data) {
	if (target.length() > 13)
	{
		printf("Too long name.\n");
		exit(EXIT_FAILURE);
	}
	vector<unsigned int> employees;
	if (op2 == " ")
	{
		employees = searchByFullName(target, data);
	}
	else if (op2 == "-f")
	{
		employees = searchByFirstName(target, data);
	}
	else if (op2 == "-l")
	{
		employees = searchByLastName(target, data);
	}
	else
	{
		printf("Invalid name option. Only -l or -f are available\n");
		exit(EXIT_FAILURE);
	}
	return employees;
}

vector<unsigned int> searchByFullName(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.full_name != target) 
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByFirstName(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.first_name != target) 
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByLastName(string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.last_name != target)
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}