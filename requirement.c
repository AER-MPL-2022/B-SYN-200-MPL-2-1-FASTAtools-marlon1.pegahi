/*
** EPITECH PROJECT, 2023
** Fastatool
** File description:
** requirement.c
*/

#include <stdlib.h>

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int is_alphanumeric(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
    || (c >= '0' && c <= '9');
}

char *my_strcapitalize_synthesis(char *str)
{
    char *ans = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'
        && (i == 0 || !is_alphanumeric(str[i - 1]))) {
                ans[i] = str[i] - 32;
        } else {
            ans[i] = str[i];
        }
    }
    return ans;
}
