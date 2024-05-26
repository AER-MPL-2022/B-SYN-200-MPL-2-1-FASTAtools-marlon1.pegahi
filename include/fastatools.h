/*
** EPITECH PROJECT, 2023
** Fastatool
** File description:
** fastatools.h
*/

#pragma once

#include "linked_string.h"
#include "linked_list.h"

// fastatools tools
int is_dnachar(char c);
void skip_line(void);
int not_dna_line(char c, int *first);
void my_revstr(char *str);

// dna sequences
void dna_sequences(void);

// rna sequences
void rna_sequences(void);

// reverse complement sequences
int not_dna_line_reverse(char c, int *first, linked_string_t *dna);
void change_char_for_reverse(char *c);
void reverse_complement_sequences(void);

// k_mers sequences
void k_mers_sequences(int argc, char const *argv[]);
int not_dna_line_k_mers(char c, linked_string_t *dna, linked_list_t *k_mers);
void k_mers_sequences(int argc, char const *argv[]);

// coding sequences
void coding_sequences(void);
