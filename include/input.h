#ifndef PROJECT04_INPUT_H
#define PROJECT04_INPUT_H

#include <stdio.h>
#include "error_manager.h"

#define MAX_ALGARISMS 11

typedef struct {
    char first_number[MAX_ALGARISMS];
    char second_number[MAX_ALGARISMS];
    char result[MAX_ALGARISMS];
} transaction;

void read_transaction(char *input_file, transaction *read_transactioned);

#endif //PROJECT04_INPUT_H
