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
void insert(List *list, int index, int data);
size_t size(List *list);
void print(List *list);


#endif