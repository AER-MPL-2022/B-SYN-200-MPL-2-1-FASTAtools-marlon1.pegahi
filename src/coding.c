/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** coding.c
*/

#include "linked_string.h"
#include "linked_list.h"
#include "alpha_majmin.h"
#include "fastatools.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void skip_line_coding(void)
{
    char c = 0;

    while (read(0, &c, 1) > 0 && c != '\n');
}

int not_dna_line_coding(char c, linked_string_t *dna, linked_list_t *coding)
{
    if (c == '>') {
        add_node(coding, linked_string_to_string(dna));
        skip_line_coding();
        return 1;
    }
    return 0;
}

static void print_coding_ter(linked_list_t **tmp, linked_string_t **str,
    int i, int *flag)
{
    for (int j = i; (*tmp)->data[j] && (*tmp)->data[j + 1] &&
    (*tmp)->data[j + 2] && (*tmp)->data[j + 3]; j += 3) {
        if (strncmp((*tmp)->data + j, "TAA", 3) == 0
        || strncmp((*tmp)->data + j, "TAG", 3) == 0
        || strncmp((*tmp)->data + j, "TGA", 3) == 0) {
            *flag = 1;
            break;
        }
        add_char(*str, (*tmp)->data[j]);
        add_char(*str, (*tmp)->data[j + 1]);
        add_char(*str, (*tmp)->data[j + 2]);
    }
}

static void print_coding_bis(linked_list_t **new, linked_list_t **tmp, int i)
{
    int flag = 0;
    linked_string_t *str = create_string('\0');

    if (strncmp((*tmp)->data + i, "ATG", 3) == 0) {
        print_coding_ter(tmp, &str, i, &flag);
        if (flag)
            add_node(*new, linked_string_to_string(str));
        clear_string(&str);
    }
}

void print_coding(linked_list_t *coding)
{
    linked_list_t *tmp = coding;
    linked_list_t *new = create_node("\0");

    while (tmp) {
        for (int i = 0; tmp->data[i]; i++) {
            print_coding_bis(&new, &tmp, i);
        }
        tmp = tmp->next;
    }
    sort_linked_list(new);
    print_list(new);
}

void coding_sequences(void)
{
    char c = 0;
    linked_string_t *dna = create_string('\0');
    linked_list_t *coding = create_node("\0");

    while (read(0, &c, 1) > 0) {
        if (not_dna_line_coding(c, dna, coding)) {
            clear_string(&dna);
            dna = create_string('\0');
            continue;
        }
        if (!is_dnachar(c))
            continue;
        if (is_alphamin(c))
            c -= 32;
        add_char(dna, c);
    }
    add_node(coding, linked_string_to_string(dna));
    print_coding(coding);
}
