#include "searchByPhoneNumber.h"

vector<unsigned int> searchByPhoneNumber(string op2, string target, unordered_map<unsigned int, Employee2> data)
{
	vector<unsigned int> employees;
	if (op2 == " ")
	{
		employees = searchByFullPhoneNumber(target, data);
	}
	else if (op2 == "-m")
	{
		employees = searchByMiddlePhoneNumber(stoi(target), data);
	}
	else if (op2 == "-l")
	{
		employees = searchByLastPhoneNumber(stoi(target), data);
	}
	else
	{
		printf("Invalid PhoneNum option. Only -m or -l are available\n");
		exit(EXIT_FAILURE);
	}
	return employees;
}

vector<unsigned int> searchByFullPhoneNumber(string target, unordered_map<unsigned int, Employee2> data)
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