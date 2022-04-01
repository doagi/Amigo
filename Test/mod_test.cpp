#include "pch.h"
#include "../AmigoPJT/command/mod.cpp"

/**
* Sample)
* Command1: ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO
* Command2: MOD, -p, , , name, FB NTAWR, birthday, 20050520
* Record  : MOD, 17112609, FB NTAWR, CL4, 010-5645-6122, 19861203, PRO
*/

TEST(AmigoModTest, Found_0_Record_0_Modify_Nothing)
{
	vector<EmployeeData> found_data;

	vector<string> result = Mod(found_data, ConditonData{ Column::BIRTHDAY, "20050520" });

	EXPECT_EQ(0, result.size());
}

TEST(AmigoModTest, Found_1_Throw_Exception_Unknown_Column)
{
	vector<EmployeeData> found_data;
	found_data.emplace_back(EmployeeData{ "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" });

	EXPECT_THROW(
	{
		vector<string> result = Mod(found_data, ConditonData{ Column::SIZE, "20050520" });
	}, invalid_argument);
}

TEST(AmigoModTest, Found_1_Throw_Exception_Modify_EmployeeNum)
{
	vector<EmployeeData> found_data;
	found_data.emplace_back(EmployeeData{ "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" });

	EXPECT_THROW(
	{
		vector<string> result = Mod(found_data, ConditonData{ Column::EMPLOYEENUM, "88114052" });
	}, invalid_argument);
}

TEST(AmigoModTest, Found_1_Record_1_Modify_Birthday)
{
	vector<EmployeeData> found_data;
	found_data.emplace_back(EmployeeData{ "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" });

	vector<string> result = Mod(found_data, ConditonData{ Column::BIRTHDAY, "20050520" });

	string expect_result = "MOD, 17112609, FB NTAWR, CL4, 010-5645-6122, 19861203, PRO";

	EXPECT_EQ(1, result.size());
	EXPECT_STREQ(expect_result.c_str(), result[0].c_str());
}
