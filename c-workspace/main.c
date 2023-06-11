#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/stringUtils.h"
#include "lib/ioUtils.h"
#include "lib/dataStructures.h"


void list_test(){
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
}


int main() {  
  char *content = readFileToString("input.txt");

  string_list_t* splittedInput = split(content, ", ");
  
  

}



