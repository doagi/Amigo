#include "pch.h"
#include <vector>

using std::vector;

#include "../../Amigo/AmigoPJT/searchByName.cpp"
#include "../../Amigo/AmigoPJT/searchByPhoneNumber.cpp"
#include "../../Amigo/AmigoPJT/common.h"

vector<Employee> testdata = {
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
	{"14130827", "RPO JK"        , "CL4", "010-3231-1698", "20090201", "ADV"},
	{"01122329", "DN WD"         , "CL4", "010-7174-5680", "20071117", "PRO"}
};

TEST(AmigoSearchTest, optionF_Name) {
	EXPECT_EQ(6, searchByFirstName("TWU", testdata));
}

TEST(AmigoSearchTest, optionL_Name) {
	EXPECT_EQ(2, searchByLastName("HBO", testdata));
}

TEST(AmigoSearchTest, optionM_Phone) {
	EXPECT_EQ(3, searchByMiddlePhoneNumber(4528, testdata));
}

TEST(AmigoSearchTest, optionL_Phone) {
	EXPECT_EQ(7, searchByLastPhoneNumber(5047, testdata));
}