#include "stringUtils.h"
#include "dataStructures.h"

#include <stdlib.h>
#include <string.h>

char* concat_string(const char* string1, const char* string2) {
  char* concatString = malloc(strlen(string1) + strlen(string2) + 1);
  strcpy(concatString, string1);
  strcat(concatString, string2);
  return concatString;
}

char* split_string(const char* string, const char* ) {
  
}