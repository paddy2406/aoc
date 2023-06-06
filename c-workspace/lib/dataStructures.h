#ifndef PADDY_DATA_STRUCTURES
#define PADDY_DATA_STRUCTURES

typedef struct string_list string_list_t;

typedef struct node node_t;

void print_list(string_list_t* list);

string_list_t* create_list(char* firstValue);

void append_list(string_list_t* list, char* value);

void prepend_list(string_list_t* list, char* value);

void delete_list(string_list_t* list);

int length_list(string_list_t* list);

#endif