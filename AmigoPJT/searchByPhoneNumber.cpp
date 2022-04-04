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
		employees = searchByMiddlePhoneNumber(target, data);
	}
	else if (op2 == "-l")
	{
		employees = searchByLastPhoneNumber(target, data);
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
	if (target.length() != 13)
	{
		printf("Invalid Phone Number length.\n");
		exit(EXIT_FAILURE);
	}
	if (target.substr(0, 4) != "010-")
	{
		printf("Invalid Phone Number. Phone Number must start with 010-.\n");
		exit(EXIT_FAILURE);
	}
	if (target.substr(8, 1) != "-")
	{
		printf("Invalid Phone Number. Phone Number format must be 010-XXXX-XXXX.\n");
		exit(EXIT_FAILURE);
	}
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.full_phone_number != target) 
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByMiddlePhoneNumber(string target, unordered_map<unsigned int, Employee2> data)
{
	if (target.length() != 4)
	{
		printf("Invalid Middle Phone Number length.\n");
		exit(EXIT_FAILURE);
	}
	int target_int = stoi(target);
	vector<unsigned int> result;
	for (auto aData : data)
	{
		if (aData.second.middle_phone_num != target_int) 
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}

vector<unsigned int> searchByLastPhoneNumber(string target, unordered_map<unsigned int, Employee2> data)
{
	if (target.length() != 4)
	{
		printf("Invalid Middle Phone Number length.\n");
		exit(EXIT_FAILURE);
	}
	int target_int = stoi(target);
	vector<unsigned int> result;
	for (auto aData : data) 
	{
		if (aData.second.last_phone_num != target_int) 
		{
			continue;
		}
		result.emplace_back(aData.first);
	}
	return result;
}