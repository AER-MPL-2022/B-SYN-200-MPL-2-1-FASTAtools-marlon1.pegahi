/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** linked_list.c
*/

#include "linked_list.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

linked_list_t *create_node(char *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(linked_list_t *list, char *data)
{
    linked_list_t *node = create_node(data);
    linked_list_t *tmp = list;

    if (!node)
        return;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

void print_list(linked_list_t *list)
{
    linked_list_t *tmp = list;

    while (tmp) {
        if (tmp->data[0] != '\0') {
            write(1, tmp->data, strlen(tmp->data));
            write(1, "\n", 1);
        }
        tmp = tmp->next;
    }
}

void clear_list(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    linked_list_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }
    *list = NULL;
}

int get_list_length(linked_list_t *list)
{
    linked_list_t *tmp = list;
    int i = 0;

    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return i;
}
