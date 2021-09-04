#include <gtest/gtest.h>

size_t Strlen(const char *s) {
  size_t n{0};
  while (*s != '\0') {
    n++;
    s++;
  }
  return n;
}

TEST(Strlen, BasicAssertions) {
  EXPECT_EQ(Strlen("jumping"), 7);
  EXPECT_EQ(Strlen("a"), 1);
  EXPECT_EQ(Strlen(""), 0);
}
