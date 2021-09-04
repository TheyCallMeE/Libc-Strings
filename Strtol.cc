#include <ctype.h>
#include <gtest/gtest.h>

long int Strtol(const char *nptr, char **endptr, int base) {
  long int res{0};
  bool negative{false};

  int chosen_base{base};

  char *it = (char *)nptr;

  while (*it != '\0') {
    // Skip starting spaces
    if (isspace(*it) && res == 0) {
      it++;
      continue;
    } else if (isspace(*it)) {
      *endptr = it;
      if (negative) res *= -1;
      return res;
    }

    // Check sign if provided
    if (*it == '-') {
      negative = true;
      it++;
      continue;
    } else if (*it == '+') {  // Unnecessary but included for readability
      negative = false;
      it++;
      continue;
    }

    // Parsing a potential '0' for octal or '0x'/'0X' for hex
    if (base == 0 && *it == '0') {
      if (tolower(*(it + 1)) == 'x') {
        chosen_base = 16;
        it++;  // Such that the x can be skipped at the end of the loop
      } else {
        chosen_base = 8;
      }
    } else {
      if (chosen_base == 0) chosen_base = 10;
      if (isalnum(*it)) {
        int num{0};
        isdigit(*it) ? num = *it - '0' : num = tolower(*it) - 'a' + 10;
        if (num >= chosen_base) {
          *endptr = it;
          if (negative) res *= -1;
          return res;
        } else {
          res *= chosen_base;
          res += num;
        }
      } else {
        *endptr = it;
        if (negative) res *= -1;
        return res;
      }
    }

    it++;
  }
  if (negative) res *= -1;
  return res;
}

TEST(Strtol, foo) {
  char nums[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char *pEnd;

  EXPECT_EQ(Strtol(nums, &pEnd, 10), 2001);
  EXPECT_EQ(Strtol(pEnd, &pEnd, 16), 6340800);
  EXPECT_EQ(Strtol(pEnd, &pEnd, 2), -3624224);
  EXPECT_EQ(Strtol(pEnd, NULL, 0), 7340031);
}
