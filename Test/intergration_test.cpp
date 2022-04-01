#include "pch.h"
#include "../../Amigo/AmigoPJT/command.cpp"
#include "../../Amigo/AmigoPJT/txt_parser.cpp"

TEST(AmigoIntergtaionTest, Sample_TC_Test) {

    vector<Command> vect_tc_inputs = ParserFromTxt("../../Amigo/AmigoPJT/input_20_20.txt");

    // TODO : 추구 구현된 feature로 output 얻어옴
    
    // 아래 TC output과 비교
    vector<Command> vect_tc_outputs = ParserFromTxt("../../Amigo/AmigoPJT/output_20_20.txt");
    //vector<Command> vect_amigo_outputs = 

    // EXPECT_EQ(vect_outputs, vect_amigo_outputs);
}