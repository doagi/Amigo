#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ToDo: Will remove or move to common
struct EmployeeData
{
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};

// ToDo: Will remove or move to common
enum class Column : unsigned int
{
	EMPLOYEENUM,
	NAME,
	CL,
	PHONENUM,
	BIRTHDAY,
	CERTI,
	SIZE
};

// ToDo: Will remove or move to common
struct ConditonData
{
	Column column;
	string value;
};

vector<string> Mod(vector<EmployeeData>& found_data, const ConditonData& condition);

string GenerateRecord(const std::string& cmd, EmployeeData& data);

void ModifyColumnData(const ConditonData& condition, EmployeeData& data);
