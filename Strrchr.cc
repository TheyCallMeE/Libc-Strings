#include <gtest/gtest.h>

char *Strrchr(const char *s, int c) {
  char *pos = NULL;
  while (*s != '\0') {
    if (*s == c) pos = (char *)s;
    s++;
  }
  return pos;
}

TEST(Strrchr, BasicAssertions) {
  EXPECT_STREQ(Strrchr("Retaliation", 't'), "tion");
}
