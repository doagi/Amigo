#include "pch.h"
#include <vector>

using std::vector;

#include "../../Amigo/AmigoPJT/searchByName.cpp"
#include "../../Amigo/AmigoPJT/searchByPhoneNumber.cpp"
#include "../../Amigo/AmigoPJT/common.h"

vector<Employee> testdata = 
{
	{"15123099", "VXIHXOTH JHOP" , "CL3", "010-3112-2609", "19771211", "ADV"},
	{"17112609", "FB NTAWR"      , "CL4", "010-5645-6122", "19861203", "PRO"},
	{"18115040", "TTETHU HBO"    , "CL3", "010-4581-2050", "20080718", "ADV"},
	{"88114052", "NQ LVARW"      , "CL4", "010-4528-3059", "19911021", "PRO"},
	{"19129568", "SRERLALH HMEF" , "CL2", "010-3091-9521", "19640910", "PRO"},
	{"17111236", "VSID TVO"      , "CL1", "010-3669-1077", "20120718", "PRO"},
	{"18117906", "TWU QSOLT"     , "CL4", "010-6672-7186", "20030413", "PRO"},
	{"08123556", "WN XV"         , "CL1", "010-7986-5047", "20100614", "PRO"},
	{"02117175", "SBILHUT LDEXRI", "CL4", "010-2814-1699", "19950704", "ADV"},
	{"03113260", "HH LTUPF"      , "CL2", "010-5798-5383", "19791018", "PRO"},
	{"14130827", "RPO JK"        , "CL4", "010-4528-1698", "20090201", "ADV"},
	{"01122329", "TWU WD"         , "CL4", "010-7174-5680", "20071117", "PRO"}
};

TEST(AmigoSearchTest, Name)
{
	vector<int> answer = { 0 };
	for (size_t i = 0; i < answer.size(); i++)
	{
		EXPECT_EQ(answer[i], searchByName("VXIHXOTH JHOP", testdata)[i]);
	}

}

TEST(AmigoSearchTest, optionF_Name) 
{
	vector<int> answer = { 6, 11 };
	for (size_t i = 0; i < answer.size(); i++) 
	{
		EXPECT_EQ(answer[i], searchByFirstName("TWU", testdata)[i]);
	}

}

TEST(AmigoSearchTest, optionL_Name) 
{
	vector<int> answer = { 2 };
	for (size_t i = 0; i < answer.size(); i++) 
	{
		EXPECT_EQ(answer[i], searchByLastName("HBO", testdata)[i]);
	}
}

TEST(AmigoSearchTest, PhoneNumber)
{
	vector<int> answer = { 1 };
	for (size_t i = 0; i < answer.size(); i++)
	{
		EXPECT_EQ(answer[i], searchByPhoneNumber("010-5645-6122", testdata)[i]);
	}
}

TEST(AmigoSearchTest, optionM_Phone) 
{
	vector<int> answer = { 3, 10 };
	for (size_t i = 0; i < answer.size(); i++) 
	{
		EXPECT_EQ(answer[i], searchByMiddlePhoneNumber(4528, testdata)[i]);
	}
}

TEST(AmigoSearchTest, optionL_Phone) 
{
	vector<int> answer = { 7 };
	for (size_t i = 0; i < answer.size(); i++) 
	{
		EXPECT_EQ(answer[i], searchByLastPhoneNumber(5047, testdata)[i]);
	}
}