/*******************************************************************************
 * Generic linked list implementation.
 * July 2021
 * 
 ******************************************************************************/

#include "linkedlist.h"

struct list {
    Node *head;
};

struct node {
    void *data;
    Node *next;
    TYPE type;
};

/**
 * Determines the size to allocate depending on the type defined in the TYPE 
 * TODO: Handle exception on default.
 * enum.
 * @param type Data type defined in the TYPE enum.
 * @return sizeof value of the type to allocate. 0 if type is unknown. 
 */ 
size_t data_size(TYPE type) {
    switch (type) {
        case INTEGER: return sizeof(int);
        case FLOAT: return sizeof(float);
        default: return 0;
    }
}

/**
 * Builder function for the List object.
 * @return A pointer to the List object.
 */
List *build_list() {
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;
    return list;
};

/**
 * Builder function for the generic Node object.
 * @param data Data to store in the Node.
 * @param type Data type of the value to be stored in the Node.
 * @return A pointer to the Node object.
 */
Node *build_node(void *data, TYPE type) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = malloc(data_size(type));
    node->next = NULL;
    return node;
}

/**
 * Destroys the list and makes sure it is empty. 
 * @param list The List to destroy.
 */
void destroy(List *list) {
    if (list == NULL) return;
    clear(list);
    free(list);
}

/**
 * Adds a Node to the end of the List. 
 * @param list Pointer to the List to which to add the item.
 * @param data Data to store in the added Node. 
 * @param type Data type of the data to store in the added Node.
 * @return A pointer to the List object. 
 */
List *add(List *list, void *data, TYPE type) {
    if (list == NULL) list = build_list();

    Node *new_node = build_node(data, type), *last = list->head;
    if (last == NULL) {
        list->head = new_node;
        return list;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    return list;
}

/**
 * Pushes a Node at the start of the List. 
 * @param list Pointer to the list to which to push the item.
 * @param data Data to store in the pushed Node. 
 * @param type Data type of the data that is stored in the pushed Node.
 * @return A pointer to the List object. 
 */
List *push(List *list, void *data, TYPE type) {
    if (list == NULL) list = build_list();

    Node *new_node = build_node(data, type);
    new_node->next = list->head;
    list->head = new_node;
    return list;
}

/**
 * Retrieves a value for the amount of items stored in the List.
 * @param list The list of which to get the amount of items stored. 
 * @return A value indicating the amount of items stored in the List. 
 */
size_t size(List *list) {
    size_t size = 0;
    Node *current = list->head;
    while(current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

/**
 * Retrieves the Node at specified index.
 * TODO: Handle exception when index is out of bounds. 
 * @param list Pointer to List object of which to retrieve Node. 
 * @param index Zero-based position of the Node to retrieve within the List.
 * @return Pointer to the Node object to retrieve, NULL if no Node can be found.
 */
Node *node_at_index(List *list, size_t index) {
    if (list == NULL) return NULL;

    size_t list_size = size(list);
    if (index >= list_size) return NULL;

    Node *current = list->head;
    while (index-- != 0) current = current->next;

    return current;
}

/**
 * Deletes a Node at a given index.
 * @param list List of which to delete the Node from.
 * @param index Zero-based position of the Node to delete within the List.
 * @return A pointer to the List object.
 */
List *delete_at_index(List* list, size_t index) {
    Node *prev, *node = node_at_index(list, index);
    if (node == NULL) return list;

    if (index == 0) {
        list->head = node->next;
        free(node);
        return list;
    }

    prev = node_at_index(list, index - 1);
    prev->next = node->next;
    free(node);
    return list;
}

/**
 * Clears the entire List object.
 * TODO: Can probably be optimized by not using `delete_at_index`.
 * @param list A pointer to the List to clear. 
 * @return A pointer to the cleared List.
 */
List *clear(List *list) {
    while(node_at_index(list, 0) != NULL) delete_at_index(list, 0);
    list->head = NULL;
    return list;
}