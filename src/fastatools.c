/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** fastatools.c
*/

#include "string.h"
#include <unistd.h>

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

void my_revstr(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    char tmp;

    while (start < end) {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}
