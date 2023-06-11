#include "dataStructures.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct string_list {
    struct node* head;
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

string_list_t* create_list(){
  string_list_t* list = (string_list_t *) malloc(sizeof(string_list_t));
  list->head = NULL;
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

