#include "stringUtils.h"
#include "dataStructures.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* returns a string that needs to be freed */
char* concat_string(const char* string1, const char* string2) {
  char* concatString = malloc(strlen(string1) + strlen(string2) + 1);
  strcpy(concatString, string1);
  strcat(concatString, string2);
  return concatString;
}

/* returns a list that needs to be freed by calling delete(list) */
string_list_t* split(char* input, char* delimiter){
  char* temp_delimiter = delimiter;
  char temp[1000];
  int temp_index = 0;
  string_list_t* list = create_list();
  while (*input != '\0') {
    if(*input != *temp_delimiter){
      // delemiter not active
      temp[temp_index] = *input;
      temp_index++;
      input++;
    } else {
      // delemiter active
      char temp2[10];
      int temp_index2 = 0;
      int failed = 0;
      while(*temp_delimiter != '\0'){
        if(*input != *temp_delimiter){
          failed = 1;
          temp2[temp_index2] = '\0';
          break;
        }
        temp2[temp_index2] = *input;
        temp_index2++;
        input++;
        temp_delimiter++;
      }
      if(failed){
        strcat(temp,temp2);
      }else{
        char* peter = (char*) malloc(temp_index + 1);
        temp[temp_index] = '\0';
        strcpy(peter, temp);
        memset(&temp[0], 0, sizeof(temp));
        temp_delimiter = delimiter;
        temp_index = 0;
        push(list, peter);
      } 
    }
    
  }
  char* last = (char*) malloc(temp_index + 1);
  temp[temp_index] = '\0';
  strcpy(last, temp);
  push(list, last);
  return list;
}

void trim(char* input){
  char* copy = strdup(input);
  size_t beginning = 0;
  size_t end = strlen(input);
  while(input[beginning] == ' '){
    beginning++;  
  }
  while(input[end - 1] == ' '){
    end--;  
  }
  input = (char *) realloc(input, end - beginning);
  memcpy(input, &copy[beginning], end - beginning);
  free(copy);
  input[end - beginning] = '\0';
}

char* substring(char* input, int beginning, int end){
  end++;
  char * result = (char *) malloc(end - beginning);
  memcpy(result, &input[beginning], end - beginning);
  result[end - beginning] = '\0';
  return result;
}