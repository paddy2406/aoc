#ifndef PADDY_DATA_STRUCTURES
#define PADDY_DATA_STRUCTURES

typedef struct string_list string_list_t;

typedef struct node node_t;

void print(string_list_t* list);

string_list_t* create_list();

void push(string_list_t* list, char* value);

void prepend(string_list_t* list, char* value);

void delete(string_list_t* list);

int length(string_list_t* list);

char* next(string_list_t* list);

int some(string_list_t* list, char* searchTerm); 

#endif