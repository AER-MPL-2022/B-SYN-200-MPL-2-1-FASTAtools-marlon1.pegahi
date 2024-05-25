/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** reverse.c
*/

#include "linked_string.h"
#include <unistd.h>
#include "alpha_majmin.h"
#include "fastatools.h"

int not_dna_line_reverse(char c, int *first, linked_string_t *dna)
{
    if (c == '>') {
        print_reverse_string(dna);
        if (*first == 1)
            write(1, "\n", 1);
        else
            *first = 1;
        write(1, &c, 1);
        skip_line();
        return 1;
    }
    return 0;
}

void change_char_for_reverse(char *c)
{
    if (is_alphamin(*c))
        *c -= 32;
    switch (*c) {
        case 'T':
            *c = 'A';
            break;
        case 'G':
            *c = 'C';
            break;
        case 'C':
            *c = 'G';
            break;
        case 'A':
            *c = 'T';
            break;
        default:
            break;
    }
}

void reverse_complement_sequences(void)
{
    char c = 0;
    int first = 0;
    linked_string_t *dna = create_string('\0');

    while (read(0, &c, 1) > 0) {
        if (not_dna_line_reverse(c, &first, dna)) {
            clear_string(&dna);
            dna = create_string('\0');
            continue;
        }
        if (!is_dnachar(c))
            continue;
        change_char_for_reverse(&c);
        add_char(dna, c);
    }
    print_reverse_string(dna);
    write(1, "\n", 1);
}
