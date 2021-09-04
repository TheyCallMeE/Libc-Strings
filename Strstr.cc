#include <gtest/gtest.h>

char *Strstr(const char *haystack, const char *needle) {
  char *start = (char *)haystack;
  char *needle_head = (char *)needle;

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      start = (char *)haystack;
      while (*needle != '\0') {
        if (*haystack != *needle) {
          haystack = start;
          needle = needle_head;
          break;
        }
        haystack++;
        needle++;
      }
      if (*needle == '\0') return start;
    }
    haystack++;
  }
  return NULL;
}

TEST(Strstr, BasicAssertions) {
  EXPECT_STREQ(Strstr("Whats poppin", "pop"), "poppin");
  EXPECT_STREQ(Strstr("SquigglyBumfluff", "hello"), NULL);
}
