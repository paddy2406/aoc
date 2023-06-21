#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/stringUtils.h"
#include "lib/ioUtils.h"
#include "lib/dataStructures.h"

void partOne(string_list_t* input);
void partTwo(string_list_t* input);
int calcNextDirection(char letter, int direction);

int main() {  
  char *content = readFileToString("input.txt");
  
  string_list_t* instructions = split(content, ", ");
  
  partOne(instructions);
    
  partTwo(instructions);

  delete(instructions);

}

void partOne(string_list_t* instructions){
  int x = 0;
  int y = 0;
  int direction = 0;

  char* instruction = next(instructions);
  while(instruction != NULL){
    direction = calcNextDirection(*instruction, direction);
    instruction++;
    int temp;
    sscanf(instruction, "%d", &temp);
    switch (direction)
    {
    case 0:
      y = y + temp;
      break;
    case 1:
      x = x + temp;
      break;
    case 2:
      y = y - temp;
      break;
    case 3:
      x = x - temp;
      break;
    
    default:
      break;
    }
    instruction = next(instructions);
  }
  printf(" --- %d --- \n", abs(x) + abs(y));
  
}

#define OFFSET 500
void partTwo(string_list_t* instructions){
  
  int x = 0 + OFFSET;
  int y = 0 + OFFSET;
  int field[1000][1000] = {0};
  int direction = 0;
  char* instruction = next(instructions);
  while(instruction != NULL){
    direction = calcNextDirection(*instruction, direction);
    instruction++;
    int steps;
    sscanf(instruction, "%d", &steps);
    for(int i = 0; i < steps; i++){
      switch (direction){
        case 0:
          x--;
          break;
        case 1:
          y++;
          break;
        case 2:
          x++;
          break;
        case 3:
          y--;
          break;
        default:
          break;
      }
      field[x][y]++;
      if(field[x][y] == 2){
        printf(" --- %d --- \n", abs(x - OFFSET) + abs(y - OFFSET));
        return;
      }
    }
    instruction = next(instructions);
  }
} 

int calcNextDirection(char letter, int direction){
  if(letter == 'L'){
    direction--;
    if(direction < 0) {
      direction = 3;
    }
  }else if(letter == 'R'){
    direction++;
    if(direction > 3) {
      direction = 0;
    }
  }
  return direction;
}