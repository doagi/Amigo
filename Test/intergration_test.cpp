#include "pch.h"
#include "../../Amigo/AmigoPJT/command.cpp"
#include "../../Amigo/AmigoPJT/txt_parser.cpp"

TEST(AmigoIntergtaionTest, Sample_TC_Test) {

    vector<Command> vect_tc_inputs = ParserFromTxt("../../Amigo/AmigoPJT/input_20_20.txt");

    // TODO : �߱� ������ feature�� output ����
    
    // �Ʒ� TC output�� ��
    vector<Command> vect_tc_outputs = ParserFromTxt("../../Amigo/AmigoPJT/output_20_20.txt");
    //vector<Command> vect_amigo_outputs = 

    // EXPECT_EQ(vect_outputs, vect_amigo_outputs);
}