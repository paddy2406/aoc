#include "dataStructures.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct string_list {
    struct node* head;
    struct node** current;
} string_list_t;


typedef struct node {
    char* val;
    struct node * next;
} node_t;


void print(string_list_t* list) {
  node_t* current = list->head;

  while (current != NULL) {
      printf("%s\n", current->val);
      current = current->next;
  }
}

/* needs to be freed by calling delete(list)*/
string_list_t* create_list(){
  string_list_t* list = (string_list_t *) malloc(sizeof(string_list_t));
  list->head = NULL;
  list->current = &list->head;
  return list;
}

void push(string_list_t* list, char* value){  
  node_t** current = &list->head;
  while(*current != NULL){
    current = &((*current)->next);
  }
  node_t* new_node = ((node_t*) malloc(sizeof(node_t)));
  new_node->val = value;
  new_node->next = NULL;
  (*current) = new_node;
}

void prepend(string_list_t* list, char* value){
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->val = value;
  new_node->next = list->head;
  list->head = new_node;
}

void delete(string_list_t* list){
  node_t* current = list->head;
  node_t* temp = NULL;
  free(list);

  while(current != NULL){
    free(current->val);
    temp = current;
    current = current->next;
    free(temp);
  }
}

int length(string_list_t* list){
  int length = 0; 
  node_t* current = list->head;
  
  while(current != NULL){
    current = current->next;
    length++;
  }
  return length;
}

char* next(string_list_t* list){
  if(*list->current == NULL){
    list->current = &list->head;
    return NULL;
  }else{
    char* temp = (*list->current)->val;
    list->current = &(*list->current)->next;
    return temp;
  }
}

int some(string_list_t* list, char* searchTerm) {
  node_t* current = list->head;
  while(current != NULL){
    if(strcmp(current->val, searchTerm) == 0){
      return 1;
    }
    current = current->next;
  }
  return 0;
}

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