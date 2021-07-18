/*******************************************************************************
 * Generic linked list implementation.
 * July 2021
 * 
 ******************************************************************************/

#include "linkedlist.h"

#define BUILD_NODE(type)                                                       \
    node_t_##type *build_node_##type(type *_data) {                            \
        node_t_##type *node = (node_t_##type*) malloc(sizeof(node_t_##type*)); \
        node->data = _data;                                                    \
        node->next = NULL;                                                     \
        return node;                                                           \
    }

#define BUILD_LIST(type)                                                       \
    list_t_##type *build_list_##type() {                                       \
        list_t_##type *list = (list_t_##type*) malloc(sizeof(list_t_##type));  \
        list->head = NULL;                                                     \
    }

#define DESTROY(type)                                                          \
    void destroy_##type(list_t_##type *_list) {                                \
        if (_list == NULL) return;                                             \
        clear_##type(_list);                                                          \
        free(_list);                                                           \
    }

#define ADD(type)                                                              \
    list_t_##type *add_##type(list_t_##type *_list, type *_data) {             \
        if (_list == NULL) _list = build_list_##type();                        \
        node_t_##type *new_node = build_node_##type(_data),                    \
        *last = _list->head;                                                   \
        if (last == NULL) {                                                    \
            _list->head = new_node;                                            \
            return _list;                                                      \
        }                                                                      \
        while(last->next != NULL)                                              \
            last = last->next;                                                 \
        last->next = new_node;                                                 \
        return _list;                                                          \
    }

#define PUSH(type)                                                             \
    list_t_##type *push_##type(list_t_##type *_list, type *_data) {            \
        if (_list == NULL) _list = build_list_##type();                        \
        node_t_##type *new_node = build_node_##type(_data);                    \
        new_node->next = _list->head;                                          \
        _list->head = new_node;                                                \
        return _list;                                                          \
    }

#define SIZE(type)                                                             \
    size_t size_##type(list_t_##type *_list) {                                 \
        size_t list_size = 0;                                                  \
        node_t_##type *current = _list->head;                                  \
        while(current != NULL) {                                               \
            list_size++;                                                       \
            current = current->next;                                           \
        }                                                                      \
        return list_size;                                                      \
    }

#define NODE_AT_INDEX(type)                                                    \
    node_t_##type *node_at_index_##type(list_t_##type *_list, size_t _index) { \
        if (_list == NULL) return NULL;                                        \
        size_t list_size = size_##type(_list);                                 \
        if (_index >= list_size) return NULL;                                  \
        node_t_##type *current = _list->head;                                  \
        while (_index-- != 0) current = current->next;                         \
        return current;                                                        \
    }

#define DELETE_AT_INDEX(type)                                                  \
    list_t_##type *delete_at_index_##type(                                     \
        list_t_##type *_list, size_t _index                                    \
    ) {                                                                        \
        node_t_##type *prev, *node = node_at_index_##type(_list, _index);      \
        if (node == NULL) return _list;                                        \
        if (_index == 0) {                                                     \
            _list->head = node->next;                                          \
            free(node);                                                        \
            return _list;                                                      \
        }                                                                      \
        prev = node_at_index_##type(_list, _index - 1);                        \
        prev->next = node->next;                                               \
        free(node);                                                            \
        return _list;                                                          \
    }

#define CLEAR(type)                                                            \
    list_t_##type *clear_##type(list_t_##type *_list) {                        \
        while(node_at_index_##type(_list, 0) != NULL)                          \
            delete_at_index_##type(_list, 0);                                  \
        _list->head = NULL;                                                    \
        return _list;                                                          \
    }

#define DEFINITIONS(type)                                                      \
    BUILD_NODE(type)                                                           \
    BUILD_LIST(type)                                                           \
    DESTROY(type)                                                              \
    ADD(type)                                                                  \
    PUSH(type)                                                                 \
    SIZE(type)                                                                 \
    NODE_AT_INDEX(type)                                                        \
    DELETE_AT_INDEX(type)                                                      \
    CLEAR(type)

DEFINITIONS(int)
DEFINITIONS(float)