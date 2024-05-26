/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** linked_list_bis.c
*/

#include "linked_list.h"
#include <string.h>
#include <stdlib.h>

char **linked_list_to_array(linked_list_t *list)
{
    linked_list_t *tmp = list;
    char **array = malloc(sizeof(char *) * (get_list_length(list) + 1));
    int i = 0;

    if (!array)
        return NULL;
    while (tmp) {
        array[i] = strdup(tmp->data);
        tmp = tmp->next;
        i++;
    }
    array[i] = NULL;
    return array;
}

void insert_node_at(linked_list_t **list, char *data, int index)
{
    linked_list_t *tmp = *list;
    linked_list_t *new = create_node(data);
    int i = 0;

    if (index == 0) {
        new->next = *list;
        *list = new;
        return;
    }
    while (tmp && i < index - 1) {
        tmp = tmp->next;
        i++;
    }
    if (!tmp)
        return;
    new->next = tmp->next;
    tmp->next = new;
}

static void sort_linked_list_bis(linked_list_t **tmp, linked_list_t **tmp2,
    linked_list_t **save, int *i)
{
    while (*tmp2 && (*tmp2)->data[0]
    && strcmp((*tmp)->data, (*tmp2)->data) > 0) {
        *tmp2 = (*tmp2)->next;
        *i += 1;
    }
    insert_node_at(save, (*tmp)->data, *i);
    *i = 0;
    *tmp = (*tmp)->next;
    *tmp2 = *save;
}

linked_list_t *sort_linked_list(linked_list_t *new)
{
    linked_list_t *tmp = new;
    linked_list_t *tmp2 = create_node("\0");
    linked_list_t *save = tmp2;
    int i = 0;

    if (!tmp)
        return NULL;
    tmp = tmp->next;
    if (!tmp)
        return new;
    insert_node_at(&tmp2, tmp->data, 0);
    save = tmp2;
    tmp = tmp->next;
    if (!tmp)
        return tmp2;
    while (tmp) {
        sort_linked_list_bis(&tmp, &tmp2, &save, &i);
    }
    return save;
}

static void remove_duplicates_bis(linked_list_t *tmp, linked_list_t *tmp2)
{
    while (tmp2->next) {
        if (strcmp(tmp->data, tmp2->next->data) == 0) {
            tmp2->next = tmp2->next->next;
            continue;
        }
        tmp2 = tmp2->next;
    }
}

void remove_duplicates(linked_list_t *list)
{
    linked_list_t *tmp = list;
    linked_list_t *tmp2 = list;

    if (!tmp)
        return;
    while (tmp) {
        remove_duplicates_bis(tmp, tmp2);
        tmp = tmp->next;
        tmp2 = tmp;
    }
    return;
}
