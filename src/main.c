/*
** EPITECH PROJECT, 2023
** Fastatool
** File description:
** main.c
*/

#include "fastatools.h"
#include <unistd.h>
#include <stdlib.h>

int run_fastatools_bis(__attribute__((unused))int argc, char const *argv[])
{
    switch (atoi(argv[1])) {
        case 5:
            coding_sequences();
            break;
        default:
            write(2, "Invalid argument\n", 18);
            return 84;
    }
    return 0;
}

int run_fastatools(int argc, char const *argv[])
{
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
        case 4:
            k_mers_sequences(argc, argv);
            break;
        default:
            return run_fastatools_bis(argc, argv);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        write(2, "Invalid number of arguments\n", 28);
        return 84;
    }
    return run_fastatools(argc, argv);
}
