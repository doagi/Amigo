#include "pch.h"
#include "../AmigoPJT/search1.cpp"

TEST(AmigoSCH1Test, TestByYear) 
{
    employees.push_back({ "15123099","VXASDGH","J","CL3","010-2049-2609","19771211","ADV" });
    employees.push_back({ "19126099","AB","JHOP","CL2","010-3112-4290","20120903","ADV" });
    employees.push_back({ "17123099","VXDDOTH","CHOI","CL1","010-1234-5678","20030405","ADV" });
    employees.push_back({ "15229299","GGGXOTH","JH","CL4","010-9483-0592","20121011","ADV" });
    employees.push_back({ "15127564","HXOTH","OP","CL3","010-2839-1234","19690918","ADV" });

    EXPECT_EQ(SearchByBirthday("y", "1977"), 1);
    EXPECT_EQ(SearchByBirthday("y", "1987"), 0);
    EXPECT_EQ(SearchByBirthday("y", "2000"), 0);
    EXPECT_EQ(SearchByBirthday("y", "2012"), 2);
    EXPECT_EQ(SearchByBirthday("y", "1923"), 0);
}
TEST(AmigoSCH1Test, TestByMonth) 
{
    EXPECT_EQ(SearchByBirthday("m", "12"), 1);
    EXPECT_EQ(SearchByBirthday("m", "09"), 2);
    EXPECT_EQ(SearchByBirthday("m", "05"), 0);
    EXPECT_EQ(SearchByBirthday("m", "04"), 1);
    EXPECT_EQ(SearchByBirthday("m", "10"), 1);
 }
TEST(AmigoSCH1Test, TestByDate) 
{
    EXPECT_EQ(SearchByBirthday("d", "11"), 2);
    EXPECT_EQ(SearchByBirthday("d", "18"), 1);
    EXPECT_EQ(SearchByBirthday("d", "30"), 0);
    EXPECT_EQ(SearchByBirthday("d", "05"), 1);
    EXPECT_EQ(SearchByBirthday("d", "03"), 1);
}