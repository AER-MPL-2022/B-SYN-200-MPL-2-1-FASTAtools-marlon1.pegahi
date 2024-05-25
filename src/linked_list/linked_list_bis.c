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
