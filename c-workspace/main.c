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
  
  string_list_t* instructions = split(content, "\n");
  
  partOne(instructions);
    
  partTwo(instructions);

  delete(instructions);
}

void partOne(string_list_t* instructions){
  char code[5];
  int codeIndex = 0;
  int currentButton = 5;
  char* part = next(instructions);
  while(part != NULL){
    while(*part != '\0'){
      switch (*part){
      case 'U':
      if(currentButton > 3){
        currentButton = currentButton - 3;
      }
        break;
      case 'R':
      if(currentButton % 3 != 0){
        currentButton++;
      }
        break;
      case 'D':
      if(currentButton < 7){
        currentButton = currentButton + 3;
      }
        break;
      case 'L':
      if(currentButton % 3 != 1){
        currentButton--;
      }
        break;
      default:
        break;
      }
      part++;
    }
    code[codeIndex++] = '0' + currentButton;
    part = next(instructions);
  }
  printf("Part 1: %s\n", code);
}


void partTwo(string_list_t* instructions){
  char code[5];
  int codeIndex = 0;
  int currentButton = 5;
  char* part = next(instructions);
  while(part != NULL){
    while(*part != '\0'){
      switch (*part){
      case 'U':
      if(currentButton != 5 && currentButton != 2 && currentButton != 1 && currentButton != 4 && currentButton != 9){ //macht kein sinn, mach grid mit 0 rand
        currentButton = currentButton - 3;
      }
        break;
      case 'R':
      if(currentButton % 3 != 0){
        currentButton++;
      }
        break;
      case 'D':
      if(currentButton < 7){
        currentButton = currentButton + 3;
      }
        break;
      case 'L':
      if(currentButton % 3 != 1){
        currentButton--;
      }
        break;
      default:
        break;
      }
      part++;
    }
    code[codeIndex++] = '0' + currentButton;
    part = next(instructions);
  }
  printf("Part 2: %c\n", '0');
} 

