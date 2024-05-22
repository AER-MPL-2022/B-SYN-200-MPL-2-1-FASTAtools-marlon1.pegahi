/*
** EPITECH PROJECT, 2023
** Fastatool
** File description:
** alpha_majmin.c
*/

int is_alphanumeric(char c)
{
    return (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int is_alphamin(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_alphamaj(char c)
{
    return (c >= 'A' && c <= 'Z');
}
