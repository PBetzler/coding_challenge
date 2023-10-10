#include "coding_challenge.h"
#include <cstring>
#include <cstdio>

void strange_parse(const char *input) {
  char secret[14];
  strncpy(secret, "I'm a ", 7);
  strncpy(secret+6, "secret!", 8);

  int len = strlen(input);
  int i = atoi(input);
  if (i <= len) {
    printf("%s\n", input+i);
  }
}

/*int main() {
  char buffer[50];
  fgets(buffer, 50, stdin);
  strange_parse(buffer);
  return 0;
}*/
