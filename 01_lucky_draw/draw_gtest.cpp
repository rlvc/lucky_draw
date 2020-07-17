
#include "draw.h"
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TestNullInput, DoTestNullInput)
{
	ASSERT_THROW(lucky_draw(NULL), int);
}

TEST(TestLoopFinished, DoTestLoopFinished)
{
	int data[ID_QTY] = { 0 };
	for (size_t i = 0; i < ID_QTY; i++)
	{
		data[i] = i;
	}
	for (size_t i = 0; i < ID_QTY; i++)
	{
		lucky_draw(data);
	}
	ASSERT_THROW(lucky_draw(data), int);
}