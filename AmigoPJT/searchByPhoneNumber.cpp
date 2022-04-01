#include "searchByPhoneNumber.h"

vector<int> searchByPhoneNumber(string target, vector<Employee> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i].phone_num != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}

vector<int> searchByMiddlePhoneNumber(int target, vector<Employee> data) 
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		string middle_number = data[i].phone_num.substr(4, 4);
		if (stoi(middle_number) != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}

vector<int> searchByLastPhoneNumber(int target, vector<Employee> data) 
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		string last_number = data[i].phone_num.substr(9, 4);
		if (stoi(last_number) != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}