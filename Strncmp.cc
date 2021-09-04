#include <gtest/gtest.h>

int Strncmp(const char* s1, const char* s2, size_t n) {
  for (int i = 0; i < n; i++) {
    if (*s1 == '\0' || *s2 == '\0') break;
    if (*s1 != *s2) break;
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

TEST(Strncmp, BasicAssertions) {
  EXPECT_EQ(Strncmp("hello", "here", 2), 0);
  EXPECT_NE(Strncmp("joker", "joke", 5), 0);
  EXPECT_NE(Strncmp("mountain", "mounted", 7), 0);
}
