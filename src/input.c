#include "input.h"

void read_transaction(char *input_file, transaction *read_transactioned){
    FILE *file;

    file = fopen(input_file, "r");
    error_file(file);

    fscanf(file, " %[^\n]s", read_transactioned->first_number);
    fscanf(file, " %[^\n]s", read_transactioned->second_number);
    fscanf(file, " %[^\n]s", read_transactioned->result);

    fclose(file);
}