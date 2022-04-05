#include "pch.h"

#include "../AmigoPJT/client.cpp"
#include "../AmigoPJT/inputStream.cpp"
#include "../AmigoPJT/outputStream.cpp"
#include "../AmigoPJT/amigoDatabase.cpp"
#include "../AmigoPJT/util.h"

#include <unordered_map>
#include <iostream>
#include <utility>

vector<Employee> employees;

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
    TEST(AmigoIntergtaionTest, Sample_TC_Test)
    {
        string input_path = "..\\AmigoPJT\\input_20_20.txt";
        string refer_path = "..\\AmigoPJT\\output_20_20_ref.txt";
        string output_path = "output_20_20.txt";

        Client amigo_client{ input_path, output_path };
        amigo_client.Run(true);

        EXPECT_EQ(0, Util::Compare(refer_path, output_path));
    }
}

namespace CommandTest
{
    class AmigoCommandTest : public ::testing::Test
    {
    protected:
        static const int MAX_COUNT = 500;
        char RAND_STR_LIST[MAX_COUNT][8] = { 0, };
        char RAND_NUM_LIST[MAX_COUNT][5] = { 0, };

        void make_string()
        {
            srand((unsigned int)time(NULL));
            for (int i = 0; i < MAX_COUNT; i++)
            {
                const unsigned int len = 1 + rand() % 6;
                for (int c = 0; c < len; c++)
                {
                    RAND_STR_LIST[i][c] = 'A' + rand() % 26;
                }
                RAND_STR_LIST[i][len] = NULL;
            }
        }

        void make_number()
        {
            srand((unsigned int)time(NULL));
            for (int i = 0; i < MAX_COUNT; i++)
            {
                for (int c = 0; c < 4; c++)
                {
                    RAND_NUM_LIST[i][c] = '0' + rand() % 10;
                }
                RAND_NUM_LIST[i][5] = NULL;
            }
        }

        string make_date(const int max)
        {
            unsigned int XX = rand() % max + 1;
            if (XX < 10)
            {
                return "0" + to_string(XX);
            }
            return to_string(XX);
        }

        string make_employee_num()
        {
            char front[5] = { 0, };
            unsigned int YY = rand() % 100;
            if (YY > 21 && YY < 69)
            {
                YY = 21;
            }
            sprintf(front, "%02d%02d", YY, rand() % 100);
            return string(front) + RAND_NUM_LIST[rand() % MAX_COUNT];
        }

        void QueryCommand(const vector<Command>& commands)
        {
            auto amigo_db = new AmigoDatabase();
            for (size_t i = 0; i < commands.size(); i++)
            {
                string result = amigo_db->Query(commands[i]);
                if (result.length() > 1)
                {
                    cout << result << endl;
                }
            }
            delete amigo_db;
        }

        Command GenerateCommand(const vector<string>& raw_command)
        {
            int i = 0;
            Command command;
            for (const string param : raw_command)
            {
                command.param[i++] = param;
            }
            command.is_valid = true;
            return command;
        }
    };

    TEST_F(AmigoCommandTest, Unsupported_Command)
    {
        vector<string> raw_command
        {
            "SWAP","op1","op2","op3","employeeNum", "name", "cl", "phoneNum", "birthday", "certi"
        };

        vector<Command> commands{ GenerateCommand(raw_command) };

        EXPECT_THROW(QueryCommand(commands), runtime_error);
    }

    TEST_F(AmigoCommandTest, Supported_All_Command)
    {
        vector<vector<string>> raw_commands
        {
            { "ADD", " ", " ", " ", "15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV" },
            { "ADD", " ", " ", " ", "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" },
            { "ADD", " ", " ", " ", "18115040", "TTETHU HBO", "CL3", "010-4581-2050", "20080718", "ADV" },
            { "SCH", "-p", "-d", " ", "birthday", "04" },
            { "MOD", "-p", " ", " ", "name", "FB NTAWR", "birthday", "20050520" },
            { "DEL", " ", " ", " ", "employeeNum", "18115040" }
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

        EXPECT_NO_THROW(QueryCommand(commands));
    }    

    TEST_F(AmigoCommandTest, DISABLED_Heavy_Command_List)
    {
        const unsigned int add_count = 200000;
        const unsigned int cmd_count = 100000;

        vector<Command> commands;
        commands.reserve(add_count + cmd_count);

        make_string();
        make_number();

        const string certi[] = { "ADV", "PRO", "EX" };
        //const string cmd_list[] = { "SCH","DEL","MOD" };  // DEL로 자료가 너무 금방 지워져서
        const string cmd_list[] = { "SCH","SCH","MOD" };    // SCH로 대체
        const string col_list[] = { "employeeNum", "name", "cl", "phoneNum", "birthday", "certi" };
        const string op2_list[][4]
        {
            { " ",  " ",  " ",  " "},
            { "-f", "-l", " ",  " "},
            { " ",  " ",  " ",  " "},
            { "-m", "-l", " ",  " "},
            { "-y", "-m", "-d", " "},
            { " ",  " ",  " ",  " "}
        };

        srand((unsigned int)time(NULL));

        auto PickRandomData = [&](const int& col, const int& op2 = 0) {
            switch (col)
            {
            case 0:
                return make_employee_num();
            case 1:
                if (op2 >= 2) // Full name
                {
                    return RAND_STR_LIST[rand() % MAX_COUNT] + string(" ") + RAND_STR_LIST[rand() % MAX_COUNT];
                }
                return RAND_STR_LIST[rand() % MAX_COUNT] + string("");
            case 2:
                return "CL" + to_string(rand() % 4 + 1);
            case 3:
                if (op2 >= 2) // Full number
                {
                    return string("010-") + RAND_NUM_LIST[rand() % MAX_COUNT] + string("-") + RAND_NUM_LIST[rand() % MAX_COUNT];
                }
                return RAND_NUM_LIST[rand() % MAX_COUNT] + string("");
            case 4:
                if (op2 >= 3) // Full date
                {
                    return to_string(1960 + rand() % 100) + make_date(12) + make_date(31);
                }
                return (op2 == 0) ? to_string(1960 + rand() % 100) : (op2 == 1) ? make_date(12) : make_date(31);
            case 5:
                return certi[rand() % 3];
            }
            return string(" ");
        };

        for (int i = 0; i < add_count; i++)
        {
            Command command;
            command.param[0] = "ADD";
            command.param[1] = " ";
            command.param[2] = " ";
            command.param[3] = " ";
            command.param[4] = PickRandomData(0);
            command.param[5] = PickRandomData(1, 2);
            command.param[6] = PickRandomData(2);
            command.param[7] = PickRandomData(3, 2);
            command.param[8] = PickRandomData(4, 3);
            command.param[9] = PickRandomData(5);
            command.is_valid = true;
            commands.emplace_back(command);
        }

        for (int i = 0; i < cmd_count; i++)
        {
            Command command;
            unsigned int cmd = rand() % 3;
            unsigned int op2 = rand() % 3;
            unsigned int col = rand() % 6;
            command.param[0] = cmd_list[cmd];
            command.param[1] = (i % 2) == 0 ? " " : "-p";
            command.param[2] = op2_list[col][op2];
            command.param[3] = " ";
            command.param[4] = col_list[col];
            command.param[5] = PickRandomData(col, op2);
            if (cmd == 2)
            {
                unsigned int op2 = rand() % 3;
                unsigned int col = rand() % 5 + 1;
                command.param[6] = col_list[col];
                command.param[7] = PickRandomData(col, op2);
            }
            command.is_valid = true;
            commands.emplace_back(command);
        }

        EXPECT_NO_THROW(QueryCommand(commands));
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
    vector<vector<string>> testData =
    {
        { "ADD", " ", " ", " ", "15123099", "VXIHXOTH JHOP" , "CL3", "010-3112-2609", "19771211", "ADV"},
        { "ADD", " ", " ", " ", "17112609", "FB NTAWR"      , "CL4", "010-5645-6122", "19861203", "PRO"},
        { "ADD", " ", " ", " ", "18115040", "TTETHU HBO"    , "CL3", "010-4581-2050", "20080718", "ADV"},
        { "ADD", " ", " ", " ", "88114052", "NQ LVARW"      , "CL4", "010-4528-3059", "19911021", "PRO"},
        { "ADD", " ", " ", " ", "19129568", "SRERLALH HMEF" , "CL2", "010-3091-9521", "19640910", "PRO"},
        { "ADD", " ", " ", " ", "17111236", "VSID TVO"      , "CL1", "010-3669-1077", "20120718", "PRO"},
        { "ADD", " ", " ", " ", "18117906", "TWU QSOLT"     , "CL4", "010-6672-7186", "20030413", "EX"},
        { "ADD", " ", " ", " ", "08123556", "WN XV"         , "CL1", "010-7986-5047", "20100614", "PRO"}
    };

    Command GenerateCommand(const vector<string>& raw_command)
    {
        int i = 0;
        Command command;
        for (const string param : raw_command)
        {
            command.param[i++] = param;
        }
        command.is_valid = true;
        return command;
    }


    TEST(AmigoDelTest, DelCLTest)
    {
        AmigoDatabase newdata1, newdata2, newdata3, newdata4;
        for (const auto& rawData : testData)
        {
            newdata1.Query(GenerateCommand(rawData));
            newdata2.Query(GenerateCommand(rawData));
            newdata3.Query(GenerateCommand(rawData));
            newdata4.Query(GenerateCommand(rawData));
        }
        Command command1 = GenerateCommand({ "DEL", " ", " ", " ", "cl", "CL4" });
        Command command2 = GenerateCommand({ "DEL", " ", " ", " ", "cl", "CL3" });
        Command command3 = GenerateCommand({ "DEL", " ", " ", " ", "cl", "CL2" });
        Command command4 = GenerateCommand({ "DEL", " ", " ", " ", "cl", "CL1" });

        EXPECT_EQ("DEL,3", newdata1.Query(command1));
        EXPECT_EQ("DEL,2", newdata2.Query(command2));
        EXPECT_EQ("DEL,1", newdata3.Query(command3));
        EXPECT_EQ("DEL,2", newdata4.Query(command4));
    }

    TEST(AmigoDelTest, DelNameTest)
    {
        AmigoDatabase newdata1, newdata2;
        for (const auto& rawData : testData)
        {
            newdata1.Query(GenerateCommand(rawData));
            newdata2.Query(GenerateCommand(rawData));
        }
        Command command1 = GenerateCommand({ "DEL", " ", " ", " ", "name", "TWU QSOLT" });
        Command command2 = GenerateCommand({ "DEL", " ", " ", " ", "name", "ASDF" });

        EXPECT_EQ("DEL,1", newdata1.Query(command1));
        EXPECT_EQ("DEL,NONE", newdata2.Query(command2));
    }

    TEST(AmigoDelTest, DelEmployNumTest)
    {
        AmigoDatabase newdata1, newdata2;
        for (const auto& rawData : testData)
        {
            newdata1.Query(GenerateCommand(rawData));
            newdata2.Query(GenerateCommand(rawData));
        }
        Command command1 = GenerateCommand({ "DEL", " ", " ", " ", "employeeNum", "17112609" });
        Command command2 = GenerateCommand({ "DEL", " ", " ", " ", "employeeNum", "12312312" });

        EXPECT_EQ("DEL,1", newdata1.Query(command1));
        EXPECT_EQ("DEL,NONE", newdata2.Query(command2));
    }

    TEST(AmigoDelTest, DelPhoneNumTest)
    {
        AmigoDatabase newdata1, newdata2;
        for (const auto& rawData : testData)
        {
            newdata1.Query(GenerateCommand(rawData));
            newdata2.Query(GenerateCommand(rawData));
        }
        Command command1 = GenerateCommand({ "DEL", " ", " ", " ", "phoneNum", "010-4528-3059" });
        Command command2 = GenerateCommand({ "DEL", " ", " ", " ", "phoneNum", "010-1111-0000" });

        EXPECT_EQ("DEL,1", newdata1.Query(command1));
        EXPECT_EQ("DEL,NONE", newdata2.Query(command2));
    }

    TEST(AmigoDelTest, DelBirthdayTest)
    {
        AmigoDatabase newdata1, newdata2;
        for (const auto& rawData : testData)
        {
            newdata1.Query(GenerateCommand(rawData));
            newdata2.Query(GenerateCommand(rawData));
        }
        Command command1 = GenerateCommand({ "DEL", " ", " ", " ", "birthday", "19640910" });
        Command command2 = GenerateCommand({ "DEL", " ", " ", " ", "birthday", "10101010" });

        EXPECT_EQ("DEL,1", newdata1.Query(command1));
        EXPECT_EQ("DEL,NONE", newdata2.Query(command2));
    }

    TEST(AmigoDelTest, DelCertiTest)
    {
        AmigoDatabase newdata1, newdata2, newdata3;
        for (const auto& rawData : testData)
        {
            newdata1.Query(GenerateCommand(rawData));
            newdata2.Query(GenerateCommand(rawData));
            newdata3.Query(GenerateCommand(rawData));
        }
        Command command1 = GenerateCommand({ "DEL", " ", " ", " ", "certi", "ADV" });
        Command command2 = GenerateCommand({ "DEL", " ", " ", " ", "certi", "PRO" });
        Command command3 = GenerateCommand({ "DEL", " ", " ", " ", "certi", "EX" });

        EXPECT_EQ("DEL,2", newdata1.Query(command1));
        EXPECT_EQ("DEL,5", newdata2.Query(command2));
        EXPECT_EQ("DEL,1", newdata3.Query(command3));
    }
}

namespace ModTest
{
    class AmigoModTest : public ::testing::Test
    {
    protected:
        void SetUp()
        {
            vector<vector<string>> raw_commands
            {
                { "ADD", " ", " ", " ", "17112609", "FB NTAWR",       "CL4", "010-5645-6122", "19861203", "PRO" },
                { "ADD", " ", " ", " ", "02117175", "SBILHUT LDEXRI", "CL4", "010-2814-1699", "19950704", "ADV" },
                { "ADD", " ", " ", " ", "08123556", "WN XV",          "CL1", "010-7986-5047", "20100614", "PRO" },
                { "ADD", " ", " ", " ", "85125741", "FBAH RTIJ",      "CL1", "010-8900-1478", "19780228", "ADV" },
                { "ADD", " ", " ", " ", "11109136", "QKAHCEX LTODDO", "CL4", "010-2627-8566", "19640130", "PRO" },
                { "ADD", " ", " ", " ", "08108827", "RTAH VNUP",      "CL4", "010-9031-2726", "19780417", "ADV" },
                { "ADD", " ", " ", " ", "05101762", "VCUHLE HMU",     "CL4", "010-3988-9289", "20030819", "PRO" }
            };

            for (const auto& raw_command : raw_commands)
            {
                amigo_db.Query(GenerateCommand(raw_command));
            }
        }

        Command GenerateCommand(const vector<string>& raw_command)
        {
            int i = 0;
            Command command;
            for (const string param : raw_command)
            {
                command.param[i++] = param;
            }
            command.is_valid = true;
            return command;
        }

        AmigoDatabase amigo_db;
    };

    TEST_F(AmigoModTest, Found_0_Record_0_Modify_Nothing)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "name", "NO ONE", "birthday", "20050520" });

        string result = amigo_db.Query(command);

        EXPECT_STREQ("MOD,NONE", result.c_str());
    }

    TEST_F(AmigoModTest, Found_1_Throw_Exception_Unknown_Column)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "name", "FB NTAWR", "holiday", "20050520" });

        EXPECT_THROW(amigo_db.Query(command), invalid_argument);
    }

    TEST_F(AmigoModTest, Found_1_Throw_Exception_Modify_EmployeeNum)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "name", "FB NTAWR", "employeeNum", "88114052" });

        EXPECT_THROW(amigo_db.Query(command), invalid_argument);
    }

    TEST_F(AmigoModTest, Found_1_Record_1_Modify_Birthday)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "name", "FB NTAWR", "birthday", "20050520" });

        const string expect_result = "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO";

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }

    TEST_F(AmigoModTest, Found_1_Record_1_Modify_Birthday_Updated)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "name", "FB NTAWR", "birthday", "20050520" });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result = "MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO";

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_Name_Updated)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "cl", "CL4", "name", "Anonymous" });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "MOD,02117175,Anonymous,CL4,010-2814-1699,19950704,ADV\n"\
            "MOD,05101762,Anonymous,CL4,010-3988-9289,20030819,PRO\n"\
            "MOD,08108827,Anonymous,CL4,010-9031-2726,19780417,ADV\n"\
            "MOD,11109136,Anonymous,CL4,010-2627-8566,19640130,PRO\n"\
            "MOD,17112609,Anonymous,CL4,010-5645-6122,19861203,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_CL_Updated)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "cl", "CL4", "cl", "CL3" });

        // 1st try and then updated
        amigo_db.Query(command);

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ("MOD,NONE", actual_result.c_str());
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_PhoneNum_Updated)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "cl", "CL4", "phoneNum", "010-1234-0000" });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "MOD,02117175,SBILHUT LDEXRI,CL4,010-1234-0000,19950704,ADV\n"\
            "MOD,05101762,VCUHLE HMU,CL4,010-1234-0000,20030819,PRO\n"\
            "MOD,08108827,RTAH VNUP,CL4,010-1234-0000,19780417,ADV\n"\
            "MOD,11109136,QKAHCEX LTODDO,CL4,010-1234-0000,19640130,PRO\n"\
            "MOD,17112609,FB NTAWR,CL4,010-1234-0000,19861203,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_Birthday_Updated)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "cl", "CL4", "birthday", "20050520" });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "MOD,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,20050520,ADV\n"\
            "MOD,05101762,VCUHLE HMU,CL4,010-3988-9289,20050520,PRO\n"\
            "MOD,08108827,RTAH VNUP,CL4,010-9031-2726,20050520,ADV\n"\
            "MOD,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,20050520,PRO\n"\
            "MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }

    TEST_F(AmigoModTest, Found_5_Record_5_Modify_Certi_Updated)
    {
        Command command = GenerateCommand({ "MOD", "-p", " ", " ", "cl", "CL4", "certi", "EX" });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "MOD,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,EX\n"\
            "MOD,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,EX\n"\
            "MOD,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,EX\n"\
            "MOD,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,EX\n"\
            "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,EX"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }
}

namespace SeachTest
{
    class AmigoSchTest : public ::testing::Test
    {
    protected:
        void SetUp()
        {
            vector<vector<string>> raw_commands
            {
                { "ADD", " ", " ", " ", "17112609", "FB NTAWR",       "CL4", "010-5645-6122", "19861203", "PRO" },
                { "ADD", " ", " ", " ", "02117175", "SBILHUT LDEXRI", "CL4", "010-2814-1699", "19950704", "ADV" },
                { "ADD", " ", " ", " ", "08123556", "WN XV",          "CL1", "010-7986-5047", "20100614", "PRO" },
                { "ADD", " ", " ", " ", "85125741", "FBAH RTIJ",      "CL1", "010-8900-1478", "19780228", "ADV" },
                { "ADD", " ", " ", " ", "11109136", "QKAHCEX LTODDO", "CL4", "010-2627-8566", "19640130", "PRO" },
                { "ADD", " ", " ", " ", "08108827", "RTAH VNUP",      "CL4", "010-9031-2726", "19780417", "ADV" },
                { "ADD", " ", " ", " ", "05101762", "VCUHLE HMU",     "CL4", "010-3988-9289", "20030819", "PRO" }
            };

            for (const auto& raw_command : raw_commands)
            {
                amigo_db.Query(GenerateCommand(raw_command));
            }
        }

        Command GenerateCommand(const vector<string>& raw_command)
        {
            int i = 0;
            Command command;
            for (const string param : raw_command)
            {
                command.param[i++] = param;
            }
            command.is_valid = true;
            return command;
        }

        AmigoDatabase amigo_db;
    };

    TEST_F(AmigoSchTest, TestByFullBirth_Pass)
    {
        Command command = GenerateCommand({ "SCH", "-p", " ", " ", "birthday", "19780228", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirth_Fail)
    {
        Command command = GenerateCommand({ "SCH", "-p", " ", " ", "birthday", "19780227", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STRNE(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthYear_Pass)
    {
        Command command = GenerateCommand({ "SCH", "-p", "-y", " ", "birthday", "1978", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV\n"\
            "SCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthYear_Fail)
    {
        Command command = GenerateCommand({ "SCH", "-p", "-y", " ", "birthday", "2003", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV\n"\
            "SCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STRNE(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthYear_NONE)
    {
        Command command = GenerateCommand({ "SCH", " ", "-y", " ", "birthday", "2000", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,NONE"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthMonth_Pass)
    {
        Command command = GenerateCommand({ "SCH", "-p", "-m", " ", "birthday", "12", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthMonth_Fail)
    {
        Command command = GenerateCommand({ "SCH", "-p", "-m", " ", "birthday", "06", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STRNE(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthDate_Pass)
    {
        Command command = GenerateCommand({ "SCH", "-p", "-d", " ", "birthday", "03", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STREQ(expect_result.c_str(), actual_result.c_str());
    }
    TEST_F(AmigoSchTest, TestByFullBirthDate_Fail)
    {
        Command command = GenerateCommand({ "SCH", "-p", "-d", " ", "birthday", "06", " ", " " });

        // 1st try and then updated
        amigo_db.Query(command);

        const string expect_result
        {
            "SCH,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"
        };

        const string actual_result = amigo_db.Query(command);

        EXPECT_STRNE(expect_result.c_str(), actual_result.c_str());
    }
 
    TEST(AmigoSearchTest, Name)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2015123099].employee_num };
        vector<unsigned int> ret = searchByName(" ", "VXIHXOTH JHOP", map_employees);
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

    TEST(AmigoSearchTest, NameException)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByName(" ", "VXIHXOTH JHOPVDNFJLDNFDDD", map_employees));
    }

    TEST(AmigoSearchTest, PhoneNumber)
    {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2017112609].employee_num };
        vector<unsigned int> ret = searchByPhoneNumber(" ", "010-5645-6122", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, optionM_Phone) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[1988114052].employee_num, map_employees[2014130827].employee_num };
        vector<unsigned int> ret = searchByMiddlePhoneNumber("4528", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, optionL_Phone) {
        makeDataforSearch();
        vector<unsigned int> answer = { map_employees[2008123556].employee_num };
        vector<unsigned int> ret = searchByLastPhoneNumber("5047", map_employees);
        EXPECT_EQ(answer.size(), ret.size());
        for (size_t i = 0; i < ret.size(); i++)
        {
            EXPECT_EQ(answer[i], ret[i]);
        }
    }

    TEST(AmigoSearchTest, PhoneNumException1)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByPhoneNumber(" ", "016-0442-4050", map_employees));
    }

    TEST(AmigoSearchTest, PhoneNumException2)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByPhoneNumber(" ", "010-442-4050", map_employees));
    }

    TEST(AmigoSearchTest, PhoneNumException3)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByPhoneNumber(" ", "01014424050", map_employees));
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

    TEST(AmigoSearchTest, CertiException)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByCerti("IM", map_employees));
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

    TEST(AmigoSearchTest, ClException)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByCl("CL5", map_employees));
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

    TEST(AmigoSearchTest, EmployeeNumberException1)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByCerti("22122329", map_employees));
    }
    TEST(AmigoSearchTest, EmployeeNumberException2)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByCerti("50122329", map_employees));
    }
    TEST(AmigoSearchTest, EmployeeNumberException3)
    {
        makeDataforSearch();
        EXPECT_ANY_THROW(searchByCerti("21129", map_employees));
    }
}
