#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

char* FileToString(const char *source) {
  FILE *file = fopen(source, "r");
  if (file == NULL) {
    printf("failed to open %s\n", source);
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  u32 size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *string = malloc(size + 1);
  if (string == NULL) {
    printf("failed to allocate memory\n");
    fclose(file);
    return NULL;
  }
  fread(string, 1, size, file);
  fclose(file);

  string[size] = '\0';

  return string;
}
