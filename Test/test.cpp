#include "pch.h"

#include "../AmigoPJT/command.cpp"
#include "../AmigoPJT/txt_parser.cpp"
#include "../AmigoPJT/command/mod.cpp"
#include "../AmigoPJT/search1.cpp"
#include "../AmigoPJT/searchByName.cpp"
#include "../AmigoPJT/searchByPhoneNumber.cpp"
#include "../AmigoPJT/searchByCl.cpp"
#include "../AmigoPJT/searchByCerti.cpp"
#include "../AmigoPJT/searchByEmployeeNum.cpp"

#include <unordered_map>
#include <iostream>
#include <utility>

vector<Employee> employees;
unordered_map<unsigned int, Employee2> map_employees;

void Init()
{
    map_employees.clear();
}

void makeDataforSearch()
{
    map_employees.clear();
    Employee2 example_data00{ "15123099", "VXIHXOTH JHOP" , "CL3", "010-3112-2609", "19771211", "ADV" };
    Employee2 example_data01{ "17112609", "FB NTAWR"      , "CL4", "010-5645-6122", "19861203", "PRO" };
    Employee2 example_data02{ "18115040", "TTETHU HBO"    , "CL3", "010-4581-2050", "20080718", "ADV" };
    Employee2 example_data03{ "88114052", "NQ LVARW"      , "CL4", "010-4528-3059", "19911021", "PRO" };
    Employee2 example_data04{ "19129568", "SRERLALH HMEF" , "CL2", "010-3091-9521", "19640910", "PRO" };
    Employee2 example_data05{ "17111236", "VSID TVO"      , "CL1", "010-3669-1077", "20120718", "PRO" };
    Employee2 example_data06{ "18117906", "TWU QSOLT"     , "CL4", "010-6672-7186", "20030413", "PRO" };
    Employee2 example_data07{ "08123556", "WN XV"         , "CL1", "010-7986-5047", "20100614", "PRO" };
    Employee2 example_data08{ "02117175", "SBILHUT LDEXRI", "CL4", "010-2814-1699", "19950704", "ADV" };
    Employee2 example_data09{ "03113260", "HH LTUPF"      , "CL2", "010-5798-5383", "19791018", "PRO" };
    Employee2 example_data10{ "14130827", "RPO JK"        , "CL4", "010-4528-1698", "20090201", "ADV" };
    Employee2 example_data11{ "01122329", "TWU WD"        , "CL4", "010-7174-5680", "20071117", "PRO" };
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2015123099, example_data00));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2017112609, example_data01));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2018115040, example_data02));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)1988114052, example_data03));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2019129568, example_data04));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2017111236, example_data05));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2018117906, example_data06));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2008123556, example_data07));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2002117175, example_data08));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2003113260, example_data09));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2014130827, example_data10));
    map_employees.insert(std::pair<unsigned int, Employee2>( (unsigned int)2001122329, example_data11));
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

namespace CommandTest
{
    TEST(AmigoCommandTest, Unsupported_Command)
    {
        vector<string> raw_command
        {
            "SWAP","op1","op2","op3","employeeNum", "name", "cl", "phoneNum", "birthday", "certi"
        };

        int i = 0;
        Command command;
        for (const string param : raw_command)
        {
            command.param[i++] = param;
        }

        vector<Command> commands{ command };

        EXPECT_THROW(CommandRun(commands), runtime_error);
    }

    TEST(AmigoCommandTest, Supported_All_Command)
    {
        vector<vector<string>> raw_commands
        {
            { "ADD", "", "", "", "15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV" },
            { "ADD", "", "", "", "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" },
            { "ADD", "", "", "", "18115040", "TTETHU HBO", "CL3", "010-4581-2050", "20080718", "ADV" },
            { "SCH", "-p", "-d", "", "birthday", "04" },
            { "MOD", "-p", "", "", "name", "FB NTAWR", "birthday", "20050520" },
            { "DEL", "", "", "", "employeeNum", "18115040" }
        };

        vector<Command> commands;
        commands.reserve(raw_commands.size());

        for (const auto& raw_command : raw_commands)
        {
            int i = 0;
            Command command;
            for (const string param : raw_command)
            {
                command.param[i++] = param;
            }
            commands.emplace_back(command);
        }

        EXPECT_NO_THROW(CommandRun(commands));
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
    Employee2 testdata[8] =
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
    
    TEST(AmigoDelTest, DelCLTest)
    {
        unordered_map<unsigned int, Employee2> test1, test2, test3, test4, test5;
        vector<unsigned int> deleteVecCL1, deleteVecCL2, deleteVecCL3, deleteVecCL4, deleteVecNone;
        for (int i = 0; i < 8; i++) {
            test1[(unsigned int)testdata[i].employee_num] = testdata[i];
            test2[(unsigned int)testdata[i].employee_num] = testdata[i];
            test3[(unsigned int)testdata[i].employee_num] = testdata[i];
            test4[(unsigned int)testdata[i].employee_num] = testdata[i];
            test5[(unsigned int)testdata[i].employee_num] = testdata[i];
        }
        deleteVecCL4 = { testdata[1].employee_num,  testdata[3].employee_num, testdata[6].employee_num };
        deleteVecCL3 = { testdata[0].employee_num,  testdata[2].employee_num };
        deleteVecCL2 = { testdata[4].employee_num };
        deleteVecCL1 = { testdata[5].employee_num,  testdata[7].employee_num };
        deleteVecNone = {};
        EXPECT_EQ("DEL,3", Del(test1, deleteVecCL4));
        EXPECT_EQ("DEL,2", Del(test2, deleteVecCL3));
        EXPECT_EQ("DEL,1", Del(test3, deleteVecCL2));
        EXPECT_EQ("DEL,2", Del(test4, deleteVecCL1));
        EXPECT_EQ("DEL,NONE", Del(test5, deleteVecNone));

        EXPECT_EQ(5, test1.size());
        EXPECT_EQ(6, test2.size());
        EXPECT_EQ(7, test3.size());
        EXPECT_EQ(6, test4.size());
        EXPECT_EQ(8, test5.size());

        for (int i = 0; i < 8; i++)
        {
            if (i == 1 || i == 3 || i == 6)
            {
                EXPECT_NE(testdata[i].str_employee_num, test1[testdata[i].employee_num].str_employee_num);
                EXPECT_NE(testdata[i].full_name, test1[testdata[i].employee_num].full_name);
                EXPECT_NE(testdata[i].full_phone_number, test1[testdata[i].employee_num].full_phone_number);
                EXPECT_NE(testdata[i].full_birthday, test1[testdata[i].employee_num].full_birthday);
                EXPECT_NE(testdata[i].cl, test1[testdata[i].employee_num].cl);
                EXPECT_NE(testdata[i].first_name, test1[testdata[i].employee_num].first_name);
                EXPECT_NE(testdata[i].last_name, test1[testdata[i].employee_num].last_name);
                EXPECT_NE(testdata[i].middle_phone_num, test1[testdata[i].employee_num].middle_phone_num);
                EXPECT_NE(testdata[i].last_phone_num, test1[testdata[i].employee_num].last_phone_num);
                EXPECT_NE(testdata[i].year_birthday, test1[testdata[i].employee_num].year_birthday);
                EXPECT_NE(testdata[i].month_birthday, test1[testdata[i].employee_num].month_birthday);
                EXPECT_NE(testdata[i].day_birthday, test1[testdata[i].employee_num].day_birthday);
                EXPECT_NE(testdata[i].certi, test1[testdata[i].employee_num].certi);
            }
            else
            {
                EXPECT_EQ(testdata[i].str_employee_num, test1[testdata[i].employee_num].str_employee_num);
                EXPECT_EQ(testdata[i].full_name, test1[testdata[i].employee_num].full_name);
                EXPECT_EQ(testdata[i].full_phone_number, test1[testdata[i].employee_num].full_phone_number);
                EXPECT_EQ(testdata[i].full_birthday, test1[testdata[i].employee_num].full_birthday);
                EXPECT_EQ(testdata[i].cl, test1[testdata[i].employee_num].cl);
                EXPECT_EQ(testdata[i].first_name, test1[testdata[i].employee_num].first_name);
                EXPECT_EQ(testdata[i].last_name, test1[testdata[i].employee_num].last_name);
                EXPECT_EQ(testdata[i].middle_phone_num, test1[testdata[i].employee_num].middle_phone_num);
                EXPECT_EQ(testdata[i].last_phone_num, test1[testdata[i].employee_num].last_phone_num);
                EXPECT_EQ(testdata[i].year_birthday, test1[testdata[i].employee_num].year_birthday);
                EXPECT_EQ(testdata[i].month_birthday, test1[testdata[i].employee_num].month_birthday);
                EXPECT_EQ(testdata[i].day_birthday, test1[testdata[i].employee_num].day_birthday);
                EXPECT_EQ(testdata[i].certi, test1[testdata[i].employee_num].certi);
            }
        }

        for (int i = 0; i < 8; i++)
        {
            if (i == 0 || i == 2)
            {
                EXPECT_NE(testdata[i].str_employee_num, test2[testdata[i].employee_num].str_employee_num);
                EXPECT_NE(testdata[i].full_name, test2[testdata[i].employee_num].full_name);
                EXPECT_NE(testdata[i].full_phone_number, test2[testdata[i].employee_num].full_phone_number);
                EXPECT_NE(testdata[i].full_birthday, test2[testdata[i].employee_num].full_birthday);
                EXPECT_NE(testdata[i].cl, test2[testdata[i].employee_num].cl);
                EXPECT_NE(testdata[i].first_name, test2[testdata[i].employee_num].first_name);
                EXPECT_NE(testdata[i].last_name, test2[testdata[i].employee_num].last_name);
                EXPECT_NE(testdata[i].middle_phone_num, test2[testdata[i].employee_num].middle_phone_num);
                EXPECT_NE(testdata[i].last_phone_num, test2[testdata[i].employee_num].last_phone_num);
                EXPECT_NE(testdata[i].year_birthday, test2[testdata[i].employee_num].year_birthday);
                EXPECT_NE(testdata[i].month_birthday, test2[testdata[i].employee_num].month_birthday);
                EXPECT_NE(testdata[i].day_birthday, test2[testdata[i].employee_num].day_birthday);
                EXPECT_NE(testdata[i].certi, test2[testdata[i].employee_num].certi);
            }
            else
            {
                EXPECT_EQ(testdata[i].str_employee_num, test2[testdata[i].employee_num].str_employee_num);
                EXPECT_EQ(testdata[i].full_name, test2[testdata[i].employee_num].full_name);
                EXPECT_EQ(testdata[i].full_phone_number, test2[testdata[i].employee_num].full_phone_number);
                EXPECT_EQ(testdata[i].full_birthday, test2[testdata[i].employee_num].full_birthday);
                EXPECT_EQ(testdata[i].cl, test2[testdata[i].employee_num].cl);
                EXPECT_EQ(testdata[i].first_name, test2[testdata[i].employee_num].first_name);
                EXPECT_EQ(testdata[i].last_name, test2[testdata[i].employee_num].last_name);
                EXPECT_EQ(testdata[i].middle_phone_num, test2[testdata[i].employee_num].middle_phone_num);
                EXPECT_EQ(testdata[i].last_phone_num, test2[testdata[i].employee_num].last_phone_num);
                EXPECT_EQ(testdata[i].year_birthday, test2[testdata[i].employee_num].year_birthday);
                EXPECT_EQ(testdata[i].month_birthday, test2[testdata[i].employee_num].month_birthday);
                EXPECT_EQ(testdata[i].day_birthday, test2[testdata[i].employee_num].day_birthday);
                EXPECT_EQ(testdata[i].certi, test2[testdata[i].employee_num].certi);
            }
        }

        for (int i = 0; i < 8; i++)
        {
            if (i == 4)
            {
                EXPECT_NE(testdata[i].str_employee_num, test3[testdata[i].employee_num].str_employee_num);
                EXPECT_NE(testdata[i].full_name, test3[testdata[i].employee_num].full_name);
                EXPECT_NE(testdata[i].full_phone_number, test3[testdata[i].employee_num].full_phone_number);
                EXPECT_NE(testdata[i].full_birthday, test3[testdata[i].employee_num].full_birthday);
                EXPECT_NE(testdata[i].cl, test3[testdata[i].employee_num].cl);
                EXPECT_NE(testdata[i].first_name, test3[testdata[i].employee_num].first_name);
                EXPECT_NE(testdata[i].last_name, test3[testdata[i].employee_num].last_name);
                EXPECT_NE(testdata[i].middle_phone_num, test3[testdata[i].employee_num].middle_phone_num);
                EXPECT_NE(testdata[i].last_phone_num, test3[testdata[i].employee_num].last_phone_num);
                EXPECT_NE(testdata[i].year_birthday, test3[testdata[i].employee_num].year_birthday);
                EXPECT_NE(testdata[i].month_birthday, test3[testdata[i].employee_num].month_birthday);
                EXPECT_NE(testdata[i].day_birthday, test3[testdata[i].employee_num].day_birthday);
                EXPECT_NE(testdata[i].certi, test3[testdata[i].employee_num].certi);
            }
            else
            {
                EXPECT_EQ(testdata[i].str_employee_num, test3[testdata[i].employee_num].str_employee_num);
                EXPECT_EQ(testdata[i].full_name, test3[testdata[i].employee_num].full_name);
                EXPECT_EQ(testdata[i].full_phone_number, test3[testdata[i].employee_num].full_phone_number);
                EXPECT_EQ(testdata[i].full_birthday, test3[testdata[i].employee_num].full_birthday);
                EXPECT_EQ(testdata[i].cl, test3[testdata[i].employee_num].cl);
                EXPECT_EQ(testdata[i].first_name, test3[testdata[i].employee_num].first_name);
                EXPECT_EQ(testdata[i].last_name, test3[testdata[i].employee_num].last_name);
                EXPECT_EQ(testdata[i].middle_phone_num, test3[testdata[i].employee_num].middle_phone_num);
                EXPECT_EQ(testdata[i].last_phone_num, test3[testdata[i].employee_num].last_phone_num);
                EXPECT_EQ(testdata[i].year_birthday, test3[testdata[i].employee_num].year_birthday);
                EXPECT_EQ(testdata[i].month_birthday, test3[testdata[i].employee_num].month_birthday);
                EXPECT_EQ(testdata[i].day_birthday, test3[testdata[i].employee_num].day_birthday);
                EXPECT_EQ(testdata[i].certi, test3[testdata[i].employee_num].certi);
            }
        }

        for (int i = 0; i < 8; i++)
        {
            if (i == 5 || i == 7)
            {
                EXPECT_NE(testdata[i].str_employee_num, test4[testdata[i].employee_num].str_employee_num);
                EXPECT_NE(testdata[i].full_name, test4[testdata[i].employee_num].full_name);
                EXPECT_NE(testdata[i].full_phone_number, test4[testdata[i].employee_num].full_phone_number);
                EXPECT_NE(testdata[i].full_birthday, test4[testdata[i].employee_num].full_birthday);
                EXPECT_NE(testdata[i].cl, test4[testdata[i].employee_num].cl);
                EXPECT_NE(testdata[i].first_name, test4[testdata[i].employee_num].first_name);
                EXPECT_NE(testdata[i].last_name, test4[testdata[i].employee_num].last_name);
                EXPECT_NE(testdata[i].middle_phone_num, test4[testdata[i].employee_num].middle_phone_num);
                EXPECT_NE(testdata[i].last_phone_num, test4[testdata[i].employee_num].last_phone_num);
                EXPECT_NE(testdata[i].year_birthday, test4[testdata[i].employee_num].year_birthday);
                EXPECT_NE(testdata[i].month_birthday, test4[testdata[i].employee_num].month_birthday);
                EXPECT_NE(testdata[i].day_birthday, test4[testdata[i].employee_num].day_birthday);
                EXPECT_NE(testdata[i].certi, test4[testdata[i].employee_num].certi);
            }
            else
            {
                EXPECT_EQ(testdata[i].str_employee_num, test4[testdata[i].employee_num].str_employee_num);
                EXPECT_EQ(testdata[i].full_name, test4[testdata[i].employee_num].full_name);
                EXPECT_EQ(testdata[i].full_phone_number, test4[testdata[i].employee_num].full_phone_number);
                EXPECT_EQ(testdata[i].full_birthday, test4[testdata[i].employee_num].full_birthday);
                EXPECT_EQ(testdata[i].cl, test4[testdata[i].employee_num].cl);
                EXPECT_EQ(testdata[i].first_name, test4[testdata[i].employee_num].first_name);
                EXPECT_EQ(testdata[i].last_name, test4[testdata[i].employee_num].last_name);
                EXPECT_EQ(testdata[i].middle_phone_num, test4[testdata[i].employee_num].middle_phone_num);
                EXPECT_EQ(testdata[i].last_phone_num, test4[testdata[i].employee_num].last_phone_num);
                EXPECT_EQ(testdata[i].year_birthday, test4[testdata[i].employee_num].year_birthday);
                EXPECT_EQ(testdata[i].month_birthday, test4[testdata[i].employee_num].month_birthday);
                EXPECT_EQ(testdata[i].day_birthday, test4[testdata[i].employee_num].day_birthday);
                EXPECT_EQ(testdata[i].certi, test4[testdata[i].employee_num].certi);
            }
        }

        for (int i = 0; i < 8; i++)
        {
            EXPECT_EQ(testdata[i].str_employee_num, test5[testdata[i].employee_num].str_employee_num);
            EXPECT_EQ(testdata[i].full_name, test5[testdata[i].employee_num].full_name);
            EXPECT_EQ(testdata[i].full_phone_number, test5[testdata[i].employee_num].full_phone_number);
            EXPECT_EQ(testdata[i].full_birthday, test5[testdata[i].employee_num].full_birthday);
            EXPECT_EQ(testdata[i].cl, test5[testdata[i].employee_num].cl);
            EXPECT_EQ(testdata[i].first_name, test5[testdata[i].employee_num].first_name);
            EXPECT_EQ(testdata[i].last_name, test5[testdata[i].employee_num].last_name);
            EXPECT_EQ(testdata[i].middle_phone_num, test5[testdata[i].employee_num].middle_phone_num);
            EXPECT_EQ(testdata[i].last_phone_num, test5[testdata[i].employee_num].last_phone_num);
            EXPECT_EQ(testdata[i].year_birthday, test5[testdata[i].employee_num].year_birthday);
            EXPECT_EQ(testdata[i].month_birthday, test5[testdata[i].employee_num].month_birthday);
            EXPECT_EQ(testdata[i].day_birthday, test5[testdata[i].employee_num].day_birthday);
            EXPECT_EQ(testdata[i].certi, test5[testdata[i].employee_num].certi);
        }
    }
}


namespace ModTest
{
    class AmigoModTest : public ::testing::Test
    {
    protected:
        void SetUp()
        {
            string raw_data[][6]
            {
                { "17112609", "FB NTAWR",       "CL4", "010-5645-6122", "19861203", "PRO" },
                { "02117175", "SBILHUT LDEXRI", "CL4", "010-2814-1699", "19950704", "ADV" },
                { "08123556", "WN XV",          "CL1", "010-7986-5047", "20100614", "PRO" },
                { "85125741", "FBAH RTIJ",      "CL1", "010-8900-1478", "19780228", "ADV" },
                { "11109136", "QKAHCEX LTODDO", "CL4", "010-2627-8566", "19640130", "PRO" }
            };

            mod_test_db.reserve(5);
            found_5_data.reserve(5);

            for (int i = 0; i < 5; i++)
            {
                Employee2 employee = Employee2(raw_data[i][0], raw_data[i][1], raw_data[i][2],
                    raw_data[i][3], raw_data[i][4], raw_data[i][5]);
                mod_test_db[employee.employee_num] = employee;
                found_5_data.emplace_back(employee.employee_num);
            }

            found_1_data.emplace_back(found_5_data[0]);
        }

        void TearDown()
        {
            found_1_data.clear();
            found_5_data.clear();
            mod_test_db.clear();
        }

        vector<unsigned int> found_0_data;
        vector<unsigned int> found_1_data;
        vector<unsigned int> found_5_data;

        unordered_map<unsigned int, Employee2> mod_test_db;
    };

    TEST_F(AmigoModTest, Found_0_Record_0_Modify_Nothing)
    {
        vector<string> result = Mod(mod_test_db, found_0_data, ModificationInfo{ Column::BIRTHDAY, "20050520" });

        EXPECT_EQ(0, result.size());
    }

    TEST_F(AmigoModTest, Found_1_Throw_Exception_Unknown_Column)
    {
        EXPECT_THROW(
        {
            vector<string> result = Mod(mod_test_db, found_1_data, ModificationInfo{ Column::SIZE, "20050520" });
        }, invalid_argument);
    }

    TEST_F(AmigoModTest, Found_1_Throw_Exception_Modify_EmployeeNum)
    {
        EXPECT_THROW(
        {
            vector<string> result = Mod(mod_test_db, found_1_data, ModificationInfo{ Column::EMPLOYEENUM, "88114052" });
        }, invalid_argument);
    }

    TEST_F(AmigoModTest, Found_1_Record_1_Modify_Birthday)
    {
        vector<string> result = Mod(mod_test_db, found_1_data, ModificationInfo{ Column::BIRTHDAY, "20050520" });

        const string expect_result = "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO";

        EXPECT_EQ(1, result.size());
        EXPECT_STREQ(expect_result.c_str(), result[0].c_str());
    }

    TEST_F(AmigoModTest, Found_1_Record_1_Modify_Birthday_Updated)
    {
        // 1st try and then updated
        Mod(mod_test_db, found_1_data, ModificationInfo{ Column::BIRTHDAY, "20050520" });

        vector<string> result = Mod(mod_test_db, found_1_data, ModificationInfo{ Column::BIRTHDAY, "20050520" });

        const string expect_result = "MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO";

        EXPECT_EQ(1, result.size());
        EXPECT_STREQ(expect_result.c_str(), result[0].c_str());
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_Name_Updated)
    {
        // 1st try and then updated
        Mod(mod_test_db, found_5_data, ModificationInfo{ Column::NAME, "Anonymous" });

        vector<string> result = Mod(mod_test_db, found_5_data, ModificationInfo{ Column::NAME, "Anonymous" });

        const string expect_result[]
        {
            "MOD,17112609,Anonymous,CL4,010-5645-6122,19861203,PRO",
            "MOD,02117175,Anonymous,CL4,010-2814-1699,19950704,ADV",
            "MOD,08123556,Anonymous,CL1,010-7986-5047,20100614,PRO",
            "MOD,85125741,Anonymous,CL1,010-8900-1478,19780228,ADV",
            "MOD,11109136,Anonymous,CL4,010-2627-8566,19640130,PRO"
        };

        EXPECT_EQ(5, result.size());

        for (int i = 0; i < 5; i++)
        {
            EXPECT_STREQ(expect_result[i].c_str(), result[i].c_str());
        }
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_CL_Updated)
    {
        // 1st try and then updated
        Mod(mod_test_db, found_5_data, ModificationInfo{ Column::CL, "CL3" });

        vector<string> result = Mod(mod_test_db, found_5_data, ModificationInfo{ Column::CL, "CL3" });

        const string expect_result[]
        {
            "MOD,17112609,FB NTAWR,CL3,010-5645-6122,19861203,PRO",
            "MOD,02117175,SBILHUT LDEXRI,CL3,010-2814-1699,19950704,ADV",
            "MOD,08123556,WN XV,CL3,010-7986-5047,20100614,PRO",
            "MOD,85125741,FBAH RTIJ,CL3,010-8900-1478,19780228,ADV",
            "MOD,11109136,QKAHCEX LTODDO,CL3,010-2627-8566,19640130,PRO"
        };

        EXPECT_EQ(5, result.size());

        for (int i = 0; i < 5; i++)
        {
            EXPECT_STREQ(expect_result[i].c_str(), result[i].c_str());
        }
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_PhoneNum_Updated)
    {
        // 1st try and then updated
        Mod(mod_test_db, found_5_data, ModificationInfo{ Column::PHONENUM, "010-1234-0000" });

        vector<string> result = Mod(mod_test_db, found_5_data, ModificationInfo{ Column::PHONENUM, "010-1234-0000" });

        const string expect_result[]
        {
            "MOD,17112609,FB NTAWR,CL4,010-1234-0000,19861203,PRO",
            "MOD,02117175,SBILHUT LDEXRI,CL4,010-1234-0000,19950704,ADV",
            "MOD,08123556,WN XV,CL1,010-1234-0000,20100614,PRO",
            "MOD,85125741,FBAH RTIJ,CL1,010-1234-0000,19780228,ADV",
            "MOD,11109136,QKAHCEX LTODDO,CL4,010-1234-0000,19640130,PRO"
        };

        EXPECT_EQ(5, result.size());

        for (int i = 0; i < 5; i++)
        {
            EXPECT_STREQ(expect_result[i].c_str(), result[i].c_str());
        }
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_Birthday_Updated)
    {
        // 1st try and then updated
        Mod(mod_test_db, found_5_data, ModificationInfo{ Column::BIRTHDAY, "20050520" });

        vector<string> result = Mod(mod_test_db, found_5_data, ModificationInfo{ Column::BIRTHDAY, "20050520" });

        const string expect_result[]
        {
            "MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO",
            "MOD,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,20050520,ADV",
            "MOD,08123556,WN XV,CL1,010-7986-5047,20050520,PRO",
            "MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,20050520,ADV",
            "MOD,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,20050520,PRO"
        };

        EXPECT_EQ(5, result.size());

        for (int i = 0; i < 5; i++)
        {
            EXPECT_STREQ(expect_result[i].c_str(), result[i].c_str());
        }
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_Certi_Updated)
    {
        // 1st try and then updated
        Mod(mod_test_db, found_5_data, ModificationInfo{ Column::CERTI, "EX" });

        vector<string> result = Mod(mod_test_db, found_5_data, ModificationInfo{ Column::CERTI, "EX" });

        const string expect_result[]
        {
            "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,EX",
            "MOD,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,EX",
            "MOD,08123556,WN XV,CL1,010-7986-5047,20100614,EX",
            "MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,EX",
            "MOD,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,EX"
        };

        EXPECT_EQ(5, result.size());

        for (int i = 0; i < 5; i++)
        {
            EXPECT_STREQ(expect_result[i].c_str(), result[i].c_str());
        }
    }
}

namespace SeachTest
{
    TEST(AmigoSCH1Test, TestByFullBirth)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2015123099].employee_num };
        vector<unsigned int> ret = SearchByBirthday(" ", "19771211", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }
    TEST(AmigoSCH1Test, TestByYear)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2015123099].employee_num };
        vector<unsigned int> ret = SearchByBirthday("-y","1977", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }
    TEST(AmigoSCH1Test, TestByMonth)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2018117906].employee_num };
        vector<unsigned int> ret = SearchByBirthday("-m", "04", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }
    TEST(AmigoSCH1Test, TestByDate)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2018115040].employee_num, map_employees[2017111236].employee_num ,map_employees[2003113260].employee_num };
        vector<unsigned int> ret = SearchByBirthday("-d", "18", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    
    
    TEST(AmigoSearchTest, Name)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2015123099].employee_num };
        vector<unsigned int> ret = searchByName("VXIHXOTH JHOP", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }

    }

    TEST(AmigoSearchTest, optionF_Name) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2018117906].employee_num, map_employees[2001122329].employee_num };
        vector<unsigned int> ret = searchByFirstName("TWU", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, optionL_Name) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2018115040].employee_num };
        vector<unsigned int> ret = searchByLastName("HBO", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, PhoneNumber)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2017112609].employee_num };
        vector<unsigned int> ret = searchByPhoneNumber("010-5645-6122", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, optionM_Phone) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[1988114052].employee_num, map_employees[2014130827].employee_num };
        vector<unsigned int> ret = searchByMiddlePhoneNumber(4528, map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, optionL_Phone) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2008123556].employee_num };
        vector<unsigned int> ret = searchByLastPhoneNumber(5047, map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, Certi) {
        makeDataforSearch();
        vector<unsigned int> answer = { 
            map_employees[2015123099].employee_num,
            map_employees[2018115040].employee_num,
            map_employees[2014130827].employee_num,
            map_employees[2002117175].employee_num
        };
        vector<unsigned int> ret = searchByCerti("ADV", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, Cl) {
        makeDataforSearch();
        vector<unsigned int> answer = { 
            map_employees[2019129568].employee_num,
            map_employees[2003113260].employee_num
        };
        vector<unsigned int> ret = searchByCl("CL2", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, EmployeeNumber) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2001122329].employee_num };
        vector<unsigned int> ret = searchByEmployeeNumber("01122329", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }
}
