#ifndef PROJECT04_DECRYPTOR_H
#define PROJECT04_DECRYPTOR_H

#include "input.h"
#include <string.h>

typedef struct {
    int len_first_number;
    int len_second_number;
    int len_result;
    char algarisms[MAX_ALGARISMS];
    int digits;
    int algarisms_MAX[MAX_ALGARISMS];
    int result_MAX[MAX_ALGARISMS];
}transaction_data;

typedef struct {
    int algarisms_value[MAX_ALGARISMS];
    int greater_algarism[3];
    int sum[MAX_ALGARISMS];
    int result[MAX_ALGARISMS];
    int flag_overflow;
    int mask_numbers[MAX_ALGARISMS][MAX_ALGARISMS];

}transaction_data_aux;

void error_digit (transaction_data *data, char *output_file);
void determine_data(transaction *read_transactioned, transaction_data *data, char *data_transactioned,int len, int test);
void mask_numbers( transaction_data *data, transaction_data_aux *data_aux,char *transactioned, int len, int number);
void decrypt(transaction *read_transactioned, transaction_data *data, transaction_data_aux *data_aux, int index);

#endif //PROJECT04_DECRYPTOR_H
