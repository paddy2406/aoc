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

  string_list_t* instructions = split(content + 2, "\n  ");
  free(content);
  
  partOne(instructions);
    
  partTwo(instructions);

  delete(instructions);
}

void partOne(string_list_t* instructions){
  int possibleTriangles = 0;
  char* line = next(instructions);
  while(line != NULL){
    //parse line to int array
    char* peter[3] = {substring(line,0,3),substring(line,5,7),substring(line,10,12)};
    int threeNumbers[3];
    for(int i = 0; i < 3; i++){
      threeNumbers[i] = atoi(peter[i]);
      free(peter[i]);
    }
    
    //evaluate if possible
    double half = (double)(threeNumbers[0] + threeNumbers[1] + threeNumbers[2]) / 2;
    int possible = 1;
    for(int i = 0; i < 3; i++){
      if((double)threeNumbers[i] >= half){
        possible = 0;
        break;
      }
    }
    possibleTriangles += possible;
    
    line = next(instructions);
  }
  printf("Part 1: %d\n", possibleTriangles);
}


void partTwo(string_list_t* instructions){
  char* line = next(instructions);
  int possibleTriangles = 0;
  while(line != NULL){
    //parse 3 lines to matrix of 3 triangles
    int threeTriangles[3][3];
    for(int i = 0; i < 3; i++){
      char* strings[3] = {substring(line,0,3),substring(line,5,7),substring(line,10,12)};
      int numbersInRow[3];
      for(int i = 0; i < 3; i++){
        numbersInRow[i] = atoi(strings[i]);
        free(strings[i]);
      }
      for(int j = 0; j < 3; j++){
        threeTriangles[i][j] = numbersInRow[j];
      }
      line = next(instructions);
    }

    // go through matrix horizontally and evaluate if each triangle is possible
    for(int i = 0; i < 3; i++){
      double half = (double)(threeTriangles[0][i] + threeTriangles[1][i] + threeTriangles[2][i]) / 2;
      int possible = 1;
      for(int j = 0; j < 3; j++){
        if((double)threeTriangles[j][i] >= half){
          possible = 0;
          break;
        }
      }
      possibleTriangles += possible;
    }
  } 
  printf("Part 2: %d\n", possibleTriangles);
} 

