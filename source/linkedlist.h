#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
typedef struct node Node;

typedef enum type {
    INTEGER, 
    FLOAT,
} TYPE;

List *build_list();
Node *build_node(void *data, TYPE type);
void destroy(List *list);
List *add(List *list, void *data, TYPE type);
List *push(List *list, void *data, TYPE type);
size_t size(List *list);
Node *node_at_index(List *list, size_t index);
List *delete_at_index(List* list, size_t index);
List *clear(List *list);

#endif