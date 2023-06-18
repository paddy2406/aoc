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


int main() {  
  char *content = readFileToString("input.txt");
  int x = 0;
  int y = 0;

  string_list_t* splittedInput = split(content, ", ");
  
  int direction = 0;

  char* info = next(splittedInput);
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

    info = next(splittedInput);
    
    
  }
  printf(" --- %d --- \n", abs(x) + abs(y));
  delete(splittedInput);

}



