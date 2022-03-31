#include "pch.h"
#include "../../Amigo/AmigoPJT/searchByName.cpp"
#include "../../Amigo/AmigoPJT/searchByPhoneNumber.cpp"


TEST(AmigoSearchTest, optionF_Name) {
	EXPECT_EQ(6, searchByFirstName("TWU"));
}

TEST(AmigoSearchTest, optionL_Name) {
	EXPECT_EQ(2, searchByLastName("HBO"));
}

TEST(AmigoSearchTest, optionM_Phone) {
	EXPECT_EQ(3, searchByMiddlePhoneNumber(4528));
}

TEST(AmigoSearchTest, optionL_Phone) {
	EXPECT_EQ(7, searchByLastPhoneNumber(5047));
}