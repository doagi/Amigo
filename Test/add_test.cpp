#include "pch.h"
#include "../../Amigo/AmigoPJT/command.cpp"
#include "../../Amigo/AmigoPJT/txt_parser.cpp"


TEST(AmigoADDTest, ADD_Test) {

    // ADD
    EXPECT_EQ(1, Add("15123099", "VXIHXOTH JHOP", "CL3", "010 - 3112 - 2609", "19771211", "ADV"));
    EXPECT_EQ(2, Add("17112609", "FB NTAWR", "CL4", "010 - 5645 - 6122", "19861203", "PRO"));
    EXPECT_EQ(3, Add("18115040", "TTETHU HBO", "CL3", "010 - 4581 - 2050", "20080718", "ADV"));
    EXPECT_EQ(4, Add("88114052", "NQ LVARW", "CL4", "010 - 4528 - 3059", "19911021", "PRO"));
}

TEST(AmigoParserTest, Parser_Test) {

    vector<Command> vect_result = ParserFromTxt("../../Amigo/AmigoPJT/input_20_20.txt");
    EXPECT_EQ(40, vect_result.size());
}