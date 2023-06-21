#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/stringUtils.h"
#include "lib/ioUtils.h"
#include "lib/dataStructures.h"


/* void list_test(){
  string_list_t* list = create_list();

  push(list, strdup("lustig"));
  push(list, strdup("macht"));
  push(list, strdup("jetzt"));
  push(list, strdup("feierabend"));

  prepend(list, strdup("firster"));
  prepend(list, strdup("am firstesten")); 
  
  print(list);
  
  printf("%d\n", length(list));
  
  delete(list);
} */

void partOne(string_list_t* input);

void partTwo(string_list_t* input);


int main() {  
  char *content = readFileToString("input.txt");
  

  string_list_t* splittedInput = split(content, ", ");
  
  partOne(splittedInput);
    
  partTwo(splittedInput);

  delete(splittedInput);

}
void partOne(string_list_t* input){
int x = 0;
  int y = 0;
  int direction = 0;

  char* info = next(input);
  while(info != NULL){
    if(*info == 'L'){
      direction--;
      if(direction < 0) {
        direction = 3;
      }
    }
    if(*info == 'R'){
      direction++;
      if(direction > 3) {
        direction = 0;
      }
    }
    info++;
    int temp;
    sscanf(info, "%d", &temp);
    if(direction == 0){
      y = y + temp;
    }
    if(direction == 1){
      x = x + temp;
    }
    if(direction == 2){
      y = y - temp;
    }
    if(direction == 3){
      x = x - temp;
    }

    info = next(input);
  }
  printf(" --- %d --- \n", abs(x) + abs(y));
  
}

void partTwo(string_list_t* input){
  int x = 0;
  int y = 0;
  int field[1000][1000] = {0};
  int direction = 0;
  char* info = next(input);
  while(info != NULL){
    if(*info == 'L'){
      direction--;
      if(direction < 0) {
        direction = 3;
      }
    }
    if(*info == 'R'){
      direction++;
      if(direction > 3) {
        direction = 0;
      }
    }
    info++;
    int temp;
    sscanf(info, "%d", &temp);
    
    if(direction == 0){
      y = y + temp;
    }
    if(direction == 1){
      x = x + temp;
    }
    if(direction == 2){
      y = y - temp;
    }
    if(direction == 3){
      x = x - temp;
    }
    info = next(input);
    char* tempString = (char*) malloc(15);
    snprintf(tempString,10, "%d,%d", x,y);
    if(some(visitedPositions, tempString)){
      printf(" --- %d --- \n", abs(x) + abs(y));
      printf(" --- %d --- %d --- \n", x, y);
      print(visitedPositions);
      break;
    }
    push(visitedPositions, tempString);

  }
  delete(visitedPositions);
} 


