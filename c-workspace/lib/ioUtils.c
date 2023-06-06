#include "ioUtils.h"

#include <stdlib.h>
#include <stdio.h>

char* readFileToString(const char* filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) return NULL; //could not open file
  
  fseek(file, 0, SEEK_END);
  long f_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *content = malloc(f_size);

  size_t n = 0;
  int c;
  while ((c = fgetc(file)) != EOF) {
      content[n++] = (char)c;
  }
  content[n] = '\0'; 

  fclose(file);
  return content;
}