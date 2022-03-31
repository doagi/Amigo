#include "pch.h"
#include "../AmigoPJT/command/mod.cpp"

TEST(AmigoModTest, Found_1_Modify_Birthday_Success)
{
	/*
	ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO
	MOD, -p, , , name, FB NTAWR, birthday, 20050520
	MOD, 17112609, FB NTAWR, CL4, 010-5645-6122, 19861203, PRO
	*/

	vector<EmployeeData> found_data;
	found_data.emplace_back(EmployeeData{ "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" });

	string expect_result = "MOD, 17112609, FB NTAWR, CL4, 010-5645-6122, 19861203, PRO";

	vector<string> result = Mod(found_data, ConditonData{ Column::BIRTHDAY, "20050520" });

	EXPECT_EQ(1, result.size());
	EXPECT_STREQ(expect_result.c_str(), result[0].c_str());
}
