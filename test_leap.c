
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int is_leap(long y) {
    return !((y%4) || (!(y%100) && y%400));
}

int main(int argc, char **argv) {
  argc--;
  argv++;

  if (argc != 1) {
    fprintf(stderr, "Error: expected 1 command-line argument (a YEAR), but got %d\n", argc);
    exit(1);
  }

  char *end;

  // clear errno so we can check whether strtol fails
  errno = 0;
  long year = strtol(argv[0], &end, 10);
  int res_errno = errno;

  if (end == argv[0]) {
    fprintf(stderr, "Error: couldn't interpret '%s' as a number\n", argv[0]);
    exit(1);
  } else if (res_errno == ERANGE) {
    fprintf(stderr, "Error: '%s' is outside the range of numbers we can handle\n", argv[0]);
    exit(1);
  } else {
    if (is_leap(year)) {
      printf("%ld is a leap year\n", year);
    } else {
      printf("%ld is not a leap year\n", year);
    }
  }

}

