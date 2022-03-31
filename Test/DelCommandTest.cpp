#include "pch.h"
#include "../AmigoPJT/DelCommand.cpp"
#include "../AmigoPJT/common.h"

vector<Employee> test = 
{
    {"15123099", "VXIHXOTH JHOP" , "CL3", "010-3112-2609", "19771211", "ADV"},
    {"17112609", "FB NTAWR"      , "CL4", "010-5645-6122", "19861203", "PRO"},
    {"18115040", "TTETHU HBO"    , "CL3", "010-4581-2050", "20080718", "ADV"},
    {"88114052", "NQ LVARW"      , "CL4", "010-4528-3059", "19911021", "PRO"},
    {"19129568", "SRERLALH HMEF" , "CL2", "010-3091-9521", "19640910", "PRO"},
    {"17111236", "VSID TVO"      , "CL1", "010-3669-1077", "20120718", "PRO"},
    {"18117906", "TWU QSOLT"     , "CL4", "010-6672-7186", "20030413", "PRO"},
    {"08123556", "WN XV"         , "CL1", "010-7986-5047", "20100614", "PRO"}
};


TEST(AmigoDelTest, DelCLTest) {
    vector<Employee> test1 = test;
    vector<Employee> test2 = test;
    vector<Employee> test3 = test;
    vector<Employee> test4 = test;
    EXPECT_EQ("DEL,3", Del(test1, cl, "CL4"));
    EXPECT_EQ("DEL,2", Del(test2, cl, "CL3"));
    EXPECT_EQ("DEL,1", Del(test3, cl, "CL2"));
    EXPECT_EQ("DEL,2", Del(test4, cl, "CL1"));
}

TEST(AmigoDelTest, DelEmployeeNumTest) {
    vector<Employee> test1 = test;
    vector<Employee> test2 = test;
    EXPECT_EQ("DEL,1", Del(test1, employeeNum, "19129568"));
    EXPECT_EQ("DEL,NONE", Del(test2, employeeNum, "111100000"));
}

TEST(AmigoDelTest, DelNameTest) {
    vector<Employee> test1 = test;
    vector<Employee> test2 = test;
    EXPECT_EQ("DEL,1", Del(test1, name, "SRERLALH HMEF"));
    EXPECT_EQ("DEL,NONE", Del(test2, name, "HAHAHAHA HA"));
}

TEST(AmigoDelTest, DelPhoneNumTest) {
    vector<Employee> test1 = test;
    vector<Employee> test2 = test;
    EXPECT_EQ("DEL,1", Del(test1, phoneNum, "010-3669-1077"));
    EXPECT_EQ("DEL,NONE", Del(test2, phoneNum, "010-0000-1111"));
}

TEST(AmigoDelTest, DelBirthdayTest) {
    vector<Employee> test1 = test;
    vector<Employee> test2 = test;
    EXPECT_EQ("DEL,1", Del(test1, birthday, "20100614"));
    EXPECT_EQ("DEL,NONE", Del(test2, birthday, "20100613"));
}

TEST(AmigoDelTest, DelCertiTest) {
    vector<Employee> test1 = test;
    vector<Employee> test2 = test;
    vector<Employee> test3 = test;
    EXPECT_EQ("DEL,2", Del(test1, certi, "ADV"));
    EXPECT_EQ("DEL,6", Del(test2, certi, "PRO"));
    EXPECT_EQ("DEL,NONE", Del(test3, certi, "EX"));
}