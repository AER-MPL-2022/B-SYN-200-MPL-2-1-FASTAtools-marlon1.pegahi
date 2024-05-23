/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** linked_string.h
*/

#pragma once

typedef struct linked_string_s {
    char c;
    struct linked_string_s *next;
} linked_string_t;

linked_string_t *create_string(char c);
void add_char(linked_string_t *str, char c);
void print_string(linked_string_t *str);
void clear_string(linked_string_t **str);
int get_string_length(linked_string_t *str);
char *linked_string_to_string(linked_string_t *str);
void print_reverse_string(linked_string_t *str);
