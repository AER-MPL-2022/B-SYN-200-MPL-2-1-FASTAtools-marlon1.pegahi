/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** linked_list.h
*/

#pragma once

typedef struct linked_list_s {
    char *data;
    struct linked_list_s *next;
} linked_list_t;

linked_list_t *create_node(char *data);
void add_node(linked_list_t *list, char *data);
void print_list(linked_list_t *list);
void clear_list(linked_list_t **list);
int get_list_length(linked_list_t *list);
char **linked_list_to_array(linked_list_t *list);
void insert_node_at(linked_list_t **list, char *data, int index);
linked_list_t *sort_linked_list(linked_list_t *new);
void remove_duplicates(linked_list_t *list);
