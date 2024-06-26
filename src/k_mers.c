/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** k_mers.c
*/

#include "linked_string.h"
#include "linked_list.h"
#include "alpha_majmin.h"
#include "fastatools.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int k_mers_error_gestion(int argc, char const *argv[])
{
    int k = 0;

    if (argc != 3) {
        write(2, "Invalid number of arguments\n", 28);
        exit(84);
    }
    k = atoi(argv[2]);
    if (k < 1) {
        write(2, "Invalid argument\n", 18);
        exit(84);
    }
    return k;
}

void skip_line_k_mers(void)
{
    char c = 0;

    while (read(0, &c, 1) > 0 && c != '\n');
}

int not_dna_line_k_mers(char c, linked_string_t *dna, linked_list_t *k_mers)
{
    if (c == '>') {
        add_node(k_mers, linked_string_to_string(dna));
        skip_line_k_mers();
        return 1;
    }
    return 0;
}

static void print_k_mers_bis(linked_list_t **tmp,
    linked_list_t **new, char **str, int k)
{
    for (int i = 0; (*tmp)->data[i + k - 1]; i++) {
        for (int j = 0; j < k; j++)
            (*str)[j] = (*tmp)->data[i + j];
        (*str)[k] = '\0';
        add_node(*new, strdup(*str));
    }
}

void print_k_mers(linked_list_t *k_mers, int k)
{
    linked_list_t *tmp = k_mers;
    linked_list_t *new = create_node("\0");
    char *str = malloc(sizeof(char) * (k + 1));

    while (tmp) {
        if ((int) strlen(tmp->data) < k) {
            tmp = tmp->next;
            continue;
        }
        print_k_mers_bis(&tmp, &new, &str, k);
        tmp = tmp->next;
    }
    new = sort_linked_list(new);
    remove_duplicates(new);
    print_list(new);
}

void k_mers_sequences(int argc, char const *argv[])
{
    char c = 0;
    linked_string_t *dna = create_string('\0');
    linked_list_t *k_mers = create_node("\0");
    int k = k_mers_error_gestion(argc, argv);

    while (read(0, &c, 1) > 0) {
        if (not_dna_line_k_mers(c, dna, k_mers)) {
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
    add_node(k_mers, linked_string_to_string(dna));
    print_k_mers(k_mers, k);
}
