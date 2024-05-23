/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** linked_string_bis.c
*/

#include "linked_string.h"
#include "fastatools.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *linked_string_to_string(linked_string_t *str)
{
    linked_string_t *tmp = str;
    char *new = malloc(sizeof(char) * (get_string_length(str) + 1));
    int i = 0;

    if (!new)
        return NULL;
    while (tmp) {
        new[i] = tmp->c;
        i++;
        tmp = tmp->next;
    }
    new[i] = '\0';
    return new + 1;
}

void print_reverse_string(linked_string_t *str)
{
    char *new = linked_string_to_string(str);

    my_revstr(new);
    write(1, new, strlen(new));
}
