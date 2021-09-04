#include <gtest/gtest.h>

int Atoi(const char *nptr) {
  int res{0};
  char *it = (char *)nptr;
  while (*it != '\0') {
    res *= 10;
    res += *it - '0';
    it++;
  }
  return res;
}

TEST(Atoi, foo) {
  EXPECT_EQ(Atoi("10"), 10);
  EXPECT_EQ(Atoi("0"), 0);
  EXPECT_EQ(Atoi("123456789"), 123456789);
}
