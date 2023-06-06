#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/stringUtils.h"
#include "lib/ioUtils.h"
#include "lib/dataStructures.h"

/* 
  char *content = readFileToString("input.txt");
  printf("%s\n", content); 
  free(content);
*/




int main() {  
  string_list_t* list = create_list("first");

  append_list(list, "peter");
  append_list(list, "lustig");
  append_list(list, "macht");
  append_list(list, "jetzt");
  append_list(list, "feierabend");

  prepend_list(list, "firster");
  prepend_list(list, "am firstesten");
  
  print_list(list);
  
  printf("%d\n", length_list(list));

  delete_list(list);
}

