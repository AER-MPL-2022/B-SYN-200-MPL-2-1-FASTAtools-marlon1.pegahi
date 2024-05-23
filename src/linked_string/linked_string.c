/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** linked_string.c
*/

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "linked_string.h"
#include "fastatools.h"

linked_string_t *create_string(char c)
{
    linked_string_t *new = malloc(sizeof(linked_string_t));

    if (!new) {
        return NULL;
    }
    new->c = c;
    new->next = NULL;
    return new;
}

void add_char(linked_string_t *str, char c)
{
    linked_string_t *new = create_string(c);
    linked_string_t *tmp = str;

    if (!new)
        return;
    if (!str)
        return;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return;
}

void print_string(linked_string_t *str)
{
    linked_string_t *tmp = str;

    while (tmp) {
        write(1, &tmp->c, 1);
        tmp = tmp->next;
    }
}

void clear_string(linked_string_t **str)
{
    linked_string_t *tmp = *str;
    linked_string_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    *str = NULL;
}

int get_string_length(linked_string_t *str)
{
    linked_string_t *tmp = str;
    int len = 0;

    while (tmp) {
        len++;
        tmp = tmp->next;
    }
    return len;
}
