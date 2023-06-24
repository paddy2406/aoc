#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/stringUtils.h"
#include "lib/ioUtils.h"
#include "lib/dataStructures.h"

void partOne(string_list_t* input);
void partTwo(string_list_t* input);


int main() {  
  char *content = readFileToString("input.txt");
  
  string_list_t* instructions = split(content, "\n  ");
  free(content);
  
  partOne(instructions);
    
  partTwo(instructions);

  delete(instructions);
}

void partOne(string_list_t* instructions){
  print(instructions);
  char* line = next(instructions);
  while(line != NULL){
    
  }
  printf("Part 1: %s\n", "s");
}


void partTwo(string_list_t* instructions){

  printf("Part 2: %s\n", "s");
} 

