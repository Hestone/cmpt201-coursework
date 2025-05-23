#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  size_t n = 0; // size of the memory. This dynamically changes after user types
  char *line = NULL; // this is a pointer variable to a memory address where the
                     // user-input is stored

  printf("Please enter some text: ");
  if ((getline(&line, &n, stdin)) == -1) {
    printf("ERROR INPUT!\n");
  } else {
    char *saveptr = NULL;
    char *str = line;
    char *ret = strtok_r(str, " ", &saveptr);
    printf("Tokens:\n");
    printf("\t%s\n", ret);
    while ((ret = strtok_r(NULL, " ", &saveptr))) {
      printf("\t%s\n", ret);
      str = NULL;
    }
  }
  free(line);

  return 0;
}
