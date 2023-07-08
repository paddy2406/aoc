#include "ioUtils.h"

#include <stdlib.h>
#include <stdio.h>

/* returns a string that needs to be freed */
char* readFileToString(const char* filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) return NULL; //could not open file
  
  fseek(file, 0, SEEK_END);
  long f_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *content = malloc(f_size + 100);

  size_t n = 0;
  int c;
  while (!feof(file)) {
      content[n++] = (char)fgetc(file);
  }
  content[n] = '\0'; 

  fclose(file);
  return content;
}