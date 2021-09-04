#include <gtest/gtest.h>

char *Strchr(const char *s, int c) {
  while (*s != '\0') {
    if (*s == c) return (char *)s;
    s++;
  }
  return NULL;
}

TEST(Strchr, BasicAssertions) {
  EXPECT_STREQ(Strchr("hello", 'l'), "llo");
  EXPECT_STREQ(Strchr("hello", 'a'), NULL);
}
