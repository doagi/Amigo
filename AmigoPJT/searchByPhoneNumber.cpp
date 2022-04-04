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
		throw std::out_of_range("Invalid PhoneNum option. Only -m or -l are available\n");
	}
	return employees;
}

vector<unsigned int> searchByFullPhoneNumber(string target, unordered_map<unsigned int, Employee2> data)
{
	if (target.length() != 13)
	{
		throw std::length_error("Invalid Phone Number length.\n");
	}
	if (target.substr(0, 4) != "010-")
	{
		throw std::out_of_range("Invalid Phone Number. Phone Number must start with 010-.\n");
	}
	if (target.substr(8, 1) != "-")
	{
		throw std::out_of_range("Invalid Phone Number. Phone Number format must be 010-XXXX-XXXX.\n");
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
		throw std::length_error("Invalid Middle Phone Number length.\n");
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
		throw std::length_error("Invalid Last Phone Number length.\n");
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