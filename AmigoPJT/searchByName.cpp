#include "searchByName.h"

vector<int> searchByName(string target, unordered_map<int, Employee2> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i].full_name != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}

vector<int> searchByFirstName(string target, unordered_map<int, Employee2> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		if (data[i].first_name != target) continue;
		result.emplace_back(i);
	}
	return result;
}

vector<int> searchByLastName(string target, unordered_map<int, Employee2> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		if (data[i].last_name != target) continue;
		result.emplace_back(i);
	}
	return result;
}