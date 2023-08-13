// main.cpp

#include <gtest/gtest.h>

// 测试用例1：测试相等断言
TEST(MyTestSuite, EqualityTest) {
  int a = 5;
  int b = 5;
  EXPECT_EQ(a, b);  // 断言 a 和 b 相等
}

// 测试用例2：测试不相等断言
TEST(MyTestSuite, InequalityTest) {
  int a = 5;
  int b = 10;
  EXPECT_NE(a, b);  // 断言 a 和 b 不相等
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
