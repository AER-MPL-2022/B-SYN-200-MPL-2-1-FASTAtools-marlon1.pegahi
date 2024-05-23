/*
** EPITECH PROJECT, 2023
** Fastatool
** File description:
** main.c
*/

#include "fastatools.h"
#include "alpha_majmin.h"
#include "linked_string.h"
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

static int not_dna_line(char c, int *first)
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

static int not_dna_line_reverse(char c, int *first, linked_string_t *dna)
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

static void dna_sequences(void)
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
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}

static void rna_sequences(void)
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

static void change_char_for_reverse(char *c)
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

static void reverse_complement_sequences(void)
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

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        write(2, "Invalid number of arguments\n", 28);
        return 84;
    }
    switch (atoi(argv[1])) {
        case 1:
            dna_sequences();
            break;
        case 2:
            rna_sequences();
            break;
        case 3:
            reverse_complement_sequences();
            break;
        default:
            write(2, "Invalid argument\n", 18);
            return 84;
    }
    return 0;
}
