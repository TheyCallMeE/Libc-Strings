#include <gtest/gtest.h>

char* Strncpy(char* dest, const char* src, size_t n) {
  char* res = dest;
  for (int i = 0; i < n; i++) {
    if (*src == '\0') break;
    *dest = *src;
    dest++;
    src++;
  }
  // As per man strncpy:
  //  If length of src is less than n write additional null bytes to dest
  for (; i < n; i++) {
    *dest = '\0';
    dest++;
  }
  return res;
}
