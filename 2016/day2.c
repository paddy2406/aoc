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
  char field[5][5] = {
    {'0','0','1','0','0'},
    {'0','2','3','4','0'},
    {'5','6','7','8','9'},
    {'0','A','B','C','0'},
    {'0','0','D','0','0'}
  };
  char code[6];
  int codeIndex = 0;
  int x = 2;
  int y = 0;
  char* part = next(instructions);
  while(part != NULL){
    while(*part != '\0'){
      switch (*part){
      case 'U':
      if(x > 0 && field[x - 1][y] != '0'){
        x--;
      }
        break;
      case 'R':
      if(y < 4 && field[x][y + 1] != '0'){
        y++;
      }
        break;
      case 'D':
      if(x < 4 && field[x + 1][y] != '0'){
        x++;
      }
        break;
      case 'L':
      if(y > 0 && field[x][y - 1] != '0'){
        y--;
      }
        break;
      default:
        break;
      }
      part++;
    }
    code[codeIndex++] = field[x][y];
    part = next(instructions);
  }
  code[codeIndex] = '\0';
  printf("Part 2: %s\n", code);
} 

