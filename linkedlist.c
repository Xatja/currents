#include "linkedlist.h"

struct node {
    int data; // void *
    Node *next;
};

struct list {
    Node *head;
};

Node* build_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

List *build_list() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void add(List *list, int data) {
    if (list == NULL) 
        list = build_list();

    Node *new_node = build_node(data);
    Node *last = list->head;
    if (last == NULL) {
        list->head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void push(List *list, int data) {
    if (list == NULL)
        list = build_list();

    Node *new_node = build_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

void insert(List *list, size_t index, int data) {
    Node *node = node_at_index(list, index);

    if (node == NULL) {
        fprintf(stderr, "Index out of bounds, index: %zu\n", index);
        return;
    }

    Node *new_node = build_node(data);
    new_node->next = node->next;
    node->next = new_node;
    return;
}

size_t size(List *list) {
    size_t list_size = 0;
    Node *current = list->head;
    while (current != NULL) {
        list_size++;
        current = current->next;
    }
    return list_size;
}

int value(Node *node) {
    return node->data;
}

Node *node_at_index(List *list, size_t index) {
    if (list == NULL) 
        list = build_list();

    size_t list_size = size(list);

    if (index >= list_size) 
        return NULL;
    
    Node *current = list->head;
    while(index-- != 0)
        current = current->next;
    
    return current;
}

int value_at_index(List *list, size_t index) {
    Node *node = node_at_index(list, index);
    if (node == NULL) {
        return 0;
    }

    return value(node);
}

void print(List *list) {
    if (list == NULL) {
        printf("\n");
        return;
    }

    Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
    return;
}

