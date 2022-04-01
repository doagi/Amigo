#include "searchByName.h"

vector<int> searchByName(string target, vector<Employee> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i].name != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}

vector<int> searchByFirstName(string target, vector<Employee> data) 
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		size_t position = data[i].name.find(" "); // TODO : 중복되는 코드 함수로 묶어내기
		string first_name = data[i].name.substr(0, position);
		if (first_name != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}

vector<int> searchByLastName(string target, vector<Employee> data) 
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		size_t position = data[i].name.find(" "); // TODO : 중복되는 코드 함수로 묶어내기
		string last_name = data[i].name.substr(position+1, string::npos);
		if (last_name != target) continue;
		result.emplace_back(i); // TODO : return 형식 논의하여 Sort 구현하기
	}
	return result;
}