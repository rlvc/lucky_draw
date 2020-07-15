
#include "draw.h"
#include <stdio.h>
#include <direct.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(test_my_draw, do_test_my_draw)
{
    int a[10]={0};
	int b = lucky_draw(a);
	ASSERT_TRUE(b == 1);
}