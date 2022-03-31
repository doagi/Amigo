#include "pch.h"
#include "../AmigoPJT/sch1.cpp"


TEST(AmigoSCH1Test, TestByYear) {

  EXPECT_EQ(SearchByBirthday("y","1977"), 1);
  EXPECT_EQ (SearchByBirthday ("y", "1987"), 0);
  EXPECT_EQ (SearchByBirthday ("y", "2000"), 0);
  EXPECT_EQ (SearchByBirthday ("y", "2012"), 2);
  EXPECT_EQ (SearchByBirthday ("y", "1923"), 0);
}