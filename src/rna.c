/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** rna.c
*/

#include "fastatools.h"
#include "alpha_majmin.h"
#include <unistd.h>

void rna_sequences(void)
{
    char c = 0;
    int first = 0;

    while (read(0, &c, 1) > 0) {
        if (not_dna_line(c, &first))
            continue;
        if (!is_dnachar(c))
            continue;
        if (is_alphamin(c))
            c -= 32;
        if (c == 'T')
            c = 'U';
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}
