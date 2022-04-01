#include "pch.h"
#include "../../Amigo/AmigoPJT/command.cpp"
#include "../../Amigo/AmigoPJT/txt_parser.cpp"

TEST(AmigoParserTest, Parser_Test) {

    vector<Command> vect_result = ParserFromTxt("../../Amigo/AmigoPJT/input_20_20.txt");
    EXPECT_EQ(40, vect_result.size());
}