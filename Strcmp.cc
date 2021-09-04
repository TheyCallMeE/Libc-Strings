#include <gtest/gtest.h>

int Strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 != *s2) break;
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

TEST(Strcmp, BasicAssertions) {
  EXPECT_NE(Strcmp("hello", "world"), 0);
  EXPECT_NE(Strcmp("hellp", "hello"), 0);
  EXPECT_EQ(Strcmp("world", "world"), 0);
}
