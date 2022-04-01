#include "pch.h"

#include "../AmigoPJT/command.cpp"
#include "../AmigoPJT/txt_parser.cpp"
#include "../AmigoPJT/command/mod.cpp"
#include "../AmigoPJT/search1.cpp"
#include "../AmigoPJT/searchByName.cpp"
#include "../AmigoPJT/searchByPhoneNumber.cpp"



void Init()
{
    employees.clear();
 
}

namespace IntergrationTest
{
    TEST(AmigoIntergtaionTest, Sample_TC_Test) {

        vector<Command> vect_tc_inputs = ParserFromTxt("../../Amigo/AmigoPJT/input_20_20.txt");

        // TODO : 추구 구현된 feature로 output 얻어옴

        // 아래 TC output과 비교
        vector<Command> vect_tc_outputs = ParserFromTxt("../../Amigo/AmigoPJT/output_20_20.txt");
        //vector<Command> vect_amigo_outputs = 

        // EXPECT_EQ(vect_outputs, vect_amigo_outputs);
    }
}

namespace AddTest 
{
    TEST(AmigoADDTest, ADD_Test) {
        // employees 초기화
        Init();
        // ADD
        EXPECT_EQ(1, Add("15123099", "VXIHXOTH JHOP", "CL3", "010 - 3112 - 2609", "19771211", "ADV"));
        EXPECT_EQ(2, Add("17112609", "FB NTAWR", "CL4", "010 - 5645 - 6122", "19861203", "PRO"));
        EXPECT_EQ(3, Add("18115040", "TTETHU HBO", "CL3", "010 - 4581 - 2050", "20080718", "ADV"));
        EXPECT_EQ(4, Add("88114052", "NQ LVARW", "CL4", "010 - 4528 - 3059", "19911021", "PRO"));
    }
}

namespace DelTest
{
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
}

namespace ModTest
{
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
}

namespace SeachTest
{
    unordered_map<unsigned int, Employee> testdata1 = {
     { 2015123099, {2015123099, "15123099", "VXIHXOTH JHOP" , "010-3112-2609", "19771211", "CL3", "VXIHXOTH", "JHOP"  , 3112, 2609, 1977, 12, 11, "ADV"}},
     { 2017112609, {2017112609, "17112609", "FB NTAWR"      , "010-5645-6122", "19861203", "CL4", "FB"      , "NTAWR" , 5645, 6122, 1986, 12,  3, "PRO"}},
     { 2018115040, {2018115040, "18115040", "TTETHU HBO"    , "010-4581-2050", "20080718", "CL3", "TTETHU"  , "HBO"   , 4581, 2050, 2008,  7, 18, "ADV"}},
     { 1988114052, {1988114052, "88114052", "NQ LVARW"      , "010-4528-3059", "19911021", "CL4", "NQ"      , "LVARW" , 4528, 3059, 1991, 10, 21, "PRO"}},
     { 2019129568, {2019129568, "19129568", "SRERLALH HMEF" , "010-3091-9521", "19640910", "CL2", "SRERLALH", "HMEF"  , 3091, 9521, 1964,  9, 10, "PRO"}},
     { 2017111236, {2017111236, "17111236", "VSID TVO"      , "010-3669-1077", "20120718", "CL1", "VSID"    , "TVO"   , 3669, 1077, 2012,  7, 18, "PRO"}},
     { 2018117906, {2018117906, "18117906", "TWU QSOLT"     , "010-6672-7186", "20030413", "CL4", "TWU"     , "QSOLT" , 6672, 7186, 2003,  4, 13, "PRO"}},
     { 2008123556, {2008123556, "08123556", "WN XV"         , "010-7986-5047", "20100614", "CL1", "WN"      , "XV"    , 7986, 5047, 2010,  6, 14, "PRO"}},
     { 2002117175, {2002117175, "02117175", "SBILHUT LDEXRI", "010-2814-1699", "19950704", "CL4", "SBILHUT" , "LDEXRI", 2814, 1699, 1995,  7,  4, "ADV"}},
     { 2003113260, {2003113260, "03113260", "HH LTUPF"      , "010-5798-5383", "19791018", "CL2", "HH"      , "LTUPF" , 5798, 5383, 1979, 10, 18, "PRO"}},
     { 2014130827, {2014130827, "14130827", "RPO JK"        , "010-4528-1698", "20090201", "CL4", "RPO"     , "JK"    , 4528, 1698, 2009,  2,  1, "ADV"}},
     { 2001122329, {2001122329, "01122329", "TWU WD"        , "010-7174-5680", "20071117", "CL4", "TWU"     , "WD"    , 7174, 5680, 2007, 11, 17, "PRO"}}
    };
    TEST(AmigoSCH1Test, TestByFullBirth)
    {
        vector<unsigned int> answer = { testdata1[2003113260].employee_num };
        vector<unsigned int> myResult = SearchByFullBirthday("19791018", testdata1);
        for (size_t i = 0; i < answer.size(); i++)
        {
            EXPECT_EQ(answer[i], myResult[i]);
        }
    }
    TEST(AmigoSCH1Test, TestByYear)
    {
        vector<unsigned int> answer = { testdata1[2015123099].employee_num };
        vector<unsigned int> myResult = SearchByBirthday("-y", "1977", testdata1);
        for (size_t i = 0; i < answer.size(); i++)
        {
            EXPECT_EQ(answer[i], myResult[i]);
        }
    }
    TEST(AmigoSCH1Test, TestByMonth)
    {
        vector<unsigned int> answer = { testdata1[2015123099].employee_num, testdata1[2017112609].employee_num };
        vector<unsigned int> myResult = SearchByBirthday("-m", "12", testdata1);
        for (size_t i = 0; i < answer.size(); i++)
        {
            EXPECT_EQ(answer[i], myResult[i]);
        }
    }
    TEST(AmigoSCH1Test, TestByDate)
    {
        vector<unsigned int> answer = { testdata1[2018115040].employee_num, testdata1[2017111236].employee_num, testdata1[2003113260].employee_num };
        for (size_t i = 0; i < answer.size(); i++)
        {
            EXPECT_EQ(answer[i], SearchByBirthday("-d", "18", testdata1)[i]);
        }
    }




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

}




