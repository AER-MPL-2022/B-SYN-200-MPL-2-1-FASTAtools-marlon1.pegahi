/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-FASTAtools-marlon1.pegahi
** File description:
** my_revstr.c
*/

#include <string.h>

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
