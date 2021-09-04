#include <gtest/gtest.h>

char *Strtok(char *str, const char *delim) {
  static char *ptr{};
  if (str != NULL) {
    ptr = str;
  }
  char *it = ptr;
  char *needle_start{};
  char *start = ptr;
  char *delim_it = (char *)delim;

  if (ptr == NULL || *ptr == '\0') return NULL;

  while (*it != '\0') {
    if (*it == *delim_it) {
      needle_start = it;
      while (*delim_it != '\0') {
        if (*(++it) != *(++delim_it)) break;
      }
      if (*delim_it == '\0') {
        ptr = it;
        it = needle_start;
        *it = '\0';
        return start;
      } else {
        it = needle_start + 1;
        delim_it = (char *)delim;
      }
    }
    it++;
  }
  ptr = it;
  return start;
}

TEST(Strtok, foo) {
  char a[16]{"hello there sir"};
  char b[14]{"hellotheresir"};
  EXPECT_STREQ(Strtok(a, " "), "hello");
  EXPECT_STREQ(Strtok(NULL, " "), "there");
  EXPECT_STREQ(Strtok(NULL, " "), "sir");
  EXPECT_STREQ(Strtok(NULL, " "), NULL);

  EXPECT_STREQ(Strtok(b, " "), "hellotheresir");
  EXPECT_STREQ(Strtok(NULL, ":"), NULL);
}
