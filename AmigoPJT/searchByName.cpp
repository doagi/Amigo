#include "searchByName.h"

vector<int> searchByName(string target, vector<Employee> data)
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i].name != target) continue;
		result.emplace_back(i); // TODO : return ���� �����Ͽ� Sort �����ϱ�
	}
	return result;
}

vector<int> searchByFirstName(string target, vector<Employee> data) 
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		size_t position = data[i].name.find(" "); // TODO : �ߺ��Ǵ� �ڵ� �Լ��� �����
		string first_name = data[i].name.substr(0, position);
		if (first_name != target) continue;
		result.emplace_back(i); // TODO : return ���� �����Ͽ� Sort �����ϱ�
	}
	return result;
}

vector<int> searchByLastName(string target, vector<Employee> data) 
{
	vector<int> result;
	for (size_t i = 0; i < data.size(); i++) 
	{
		size_t position = data[i].name.find(" "); // TODO : �ߺ��Ǵ� �ڵ� �Լ��� �����
		string last_name = data[i].name.substr(position+1, string::npos);
		if (last_name != target) continue;
		result.emplace_back(i); // TODO : return ���� �����Ͽ� Sort �����ϱ�
	}
	return result;
}