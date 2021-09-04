#include <gtest/gtest.h>

char* Strcpy(char* dest, const char* src) {
  char* res = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return res;
}

TEST(Strcpy, BasicAssertions) {
  char a[6]{};
  EXPECT_STREQ(Strcpy(a, "world"), "world");
}
