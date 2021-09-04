#include <gtest/gtest.h>

char *Strcat(char *dest, const char *src) {
  char *it = dest;
  while (*it != '\0') {
    it++;
  }

  while (*src != '\0') {
    *it = *src;
    it++;
    src++;
  }
  *it = '\0';

  return dest;
}

TEST(Strcat, BasicAssertions) {
  EXPECT_STREQ(Strcat((char *)"Squiggly", "Bumfluff"), "SquigglyBumfluff");
}
