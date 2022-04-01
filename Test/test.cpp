#include "pch.h"

#include "../AmigoPJT/command.cpp"
#include "../AmigoPJT/txt_parser.cpp"
#include "../AmigoPJT/command/mod.cpp"
#include "../AmigoPJT/search1.cpp"
#include "../AmigoPJT/searchByName.cpp"
#include "../AmigoPJT/searchByPhoneNumber.cpp"

#include <map>

vector<Employee> employees;
map<int, Employee2> map_employees;

void Init()
{
    map_employees.clear();
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
        EXPECT_EQ(1, Add("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV"));
        EXPECT_EQ(2, Add("17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO"));
        EXPECT_EQ(3, Add("18115040", "TTETHU HBO", "CL3", "010-4581-2050", "20080718", "ADV"));
        EXPECT_EQ(4, Add("88114052", "NQ LVARW", "CL4", "010-4528-3059", "19911021", "PRO"));
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

    TEST(AmigoSCH1Test, TestByYear)
    {
        employees.push_back({ "15123099","VXASDGH J","CL3","010-2049-2609","19771211","ADV" });
        employees.push_back({ "19126099","AB JHOP","CL2","010-3112-4290","20120903","ADV" });
        employees.push_back({ "17123099","VXDDOTH CHOI","CL1","010-1234-5678","20030405","ADV" });
        employees.push_back({ "15229299","GGGXOTH JH","CL4","010-9483-0592","20121011","ADV" });
        employees.push_back({ "15127564","HXOTH OP","CL3","010-2839-1234","19690918","ADV" });

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




