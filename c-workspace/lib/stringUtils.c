#include "stringUtils.h"
#include "dataStructures.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* concat_string(const char* string1, const char* string2) {
  char* concatString = malloc(strlen(string1) + strlen(string2) + 1);
  strcpy(concatString, string1);
  strcat(concatString, string2);
  return concatString;
}

string_list_t* split(char* input, char* delimiter){
  char* temp_delimiter = delimiter;
  char temp[100];
  int temp_index = 0;
  string_list_t* list = create_list();
  while (*input != '\0') {
    if(*input != *temp_delimiter){
      temp[temp_index] = *input;
      temp_index++;
      input++;
    } else {
      char temp2[10];
      int temp_index2 = 0;
      while(*temp_delimiter != '\0')  
        if(*input == *temp_delimiter){
          temp2[temp_index2] = *input;
          input++;
        }
        
        printf("%c\n", *input);
        
        input++;
    }

    


    return list;
  }
}