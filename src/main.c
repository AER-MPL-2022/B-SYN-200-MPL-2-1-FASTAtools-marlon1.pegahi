/*
** EPITECH PROJECT, 2023
** Fastatool
** File description:
** main.c
*/

#include "fastatools.h"
#include "alpha_majmin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int is_dnachar(char c)
{
    return (c == 'A' || c == 'T' || c == 'C' || c == 'G' || c == 'N'
        || c == 'a' || c == 't' || c == 'c' || c == 'g' || c == 'n');
}

void skip_line(void)
{
    char c = 0;

    while (read(0, &c, 1) > 0 && c != '\n') {
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}

int not_dna_line(char c, int *first)
{
    if (c == '>') {
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

void dna_sequences(void)
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
        write(1, & c, 1);
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        write(2, "Invalid number of arguments\n", 28);
        return 84;
    }
    switch (argv[1][0]) {
        case '1': dna_sequences(); break;
        default: write(2, "Invalid argument\n", 18); break;
    }
    return 0;
}
