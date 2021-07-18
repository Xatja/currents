#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

Node *build_node(int data);
List *build_list();
void add(List *list, int data);
void push(List *list, int data);
void insert(List *list, size_t index, int data);
size_t size(List *list);
int value(Node *node);
Node *node_at_index(List *list, size_t index);
int value_at_index(List *list, size_t index);
void print(List *list);



#endif