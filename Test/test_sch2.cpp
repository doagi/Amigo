#include "pch.h"
#include "../../Amigo/AmigoPJT/searchByName.cpp"
#include "../../Amigo/AmigoPJT/searchByPhoneNumber.cpp"


TEST(AmigoSearchTest, optionF_Name) {
	EXPECT_STREQ("test", searchByFirstName().c_str());
}

TEST(AmigoSearchTest, optionL_Name) {
	EXPECT_STREQ("test", searchByLastName().c_str());
}

TEST(AmigoSearchTest, optionM_Phone) {
	EXPECT_STREQ("test", searchByMiddlePhoneNumber().c_str());
}

TEST(AmigoSearchTest, optionL_Phone) {
	EXPECT_STREQ("test", searchByLastPhoneNumber().c_str());
}