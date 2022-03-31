#include "pch.h"
#include "../../Amigo/AmigoPJT/cmd.cpp"

TEST(AmigoADDTest, ADD_Test) {

    // ADD
    EXPECT_EQ(1, Add("15123099", "VXIHXOTH JHOP", "CL3", "010 - 3112 - 2609", "19771211", "ADV"));
    EXPECT_EQ(2, Add("17112609", "FB NTAWR", "CL4", "010 - 5645 - 6122", "19861203", "PRO"));
    EXPECT_EQ(3, Add("18115040", "TTETHU HBO", "CL3", "010 - 4581 - 2050", "20080718", "ADV"));
    EXPECT_EQ(4, Add("88114052", "NQ LVARW", "CL4", "010 - 4528 - 3059", "19911021", "PRO"));
}

TEST(TestCase, DEL_Test) {    
    // ADD

    // DEL

    // DEL 잘 됐는지 확인
}

TEST(TestCase, SCH_Test) {    
    // ADD

    // SCH 잘 됐는지 확인
}

TEST(TestCase, MOD_Test) {
    // ADD

    // MOD 잘 됐는지 확인
}