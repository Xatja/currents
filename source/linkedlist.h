/*******************************************************************************
 * Generic linked list implementation.
 * July 2021
 * 
 ******************************************************************************/

/* TODO: Use object heads to fake overloading of functions */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#define DECLARATIONS(type)                                                     \
    typedef struct node_t_##type node_t_##type;                                \
    struct node_t_##type {                                                     \
        type *data;                                                            \
        node_t_##type *next;                                                   \
    };                                                                         \
    typedef struct list_t_##type list_t_##type;                                \
    struct list_t_##type {                                                     \
        node_t_##type *head;                                                   \
    };                                                                         \
    node_t_##type *build_node_##type(type *_data);                             \
    list_t_##type *build_list_##type();                                        \
    void destroy_##type(list_t_##type *list);                                  \
    list_t_##type *add_##type(list_t_##type *list, type *data);                \
    list_t_##type *push_##type(list_t_##type *list, type *data);               \
    size_t size_##type(list_t_##type *list);                                   \
    node_t_##type *node_at_index_##type(list_t_##type *list, size_t index);    \
    list_t_##type *delete_at_index_##type(list_t_##type *list, size_t index);  \
    list_t_##type *clear_##type(list_t_##type *list);

DECLARATIONS(int)
DECLARATIONS(float)

#endif /* LINKEDLIST_H */