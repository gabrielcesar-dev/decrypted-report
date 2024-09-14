#include "input.h"
#include "decryptor.h"
#include "error_manager.h"
#include "output.h"

int main(int argc, char **argv) {
    //determine if the number of arguments is correct
    argc_error(argc);

    transaction read_transactioned;

    //read the transaction on the input file
    read_transaction(argv[1], &read_transactioned);

    transaction_data data;

    data.digits = 0;
    data.len_first_number = strlen(read_transactioned.first_number);
    data.len_second_number = strlen(read_transactioned.second_number);
    data.len_result = strlen(read_transactioned.result);

    error_digit(&data, argv[2]);

    //determine the number of different digits in the transaction
    determine_data(&read_transactioned, &data, read_transactioned.first_number,data.len_first_number, 2);
    determine_data(&read_transactioned, &data, read_transactioned.second_number, data.len_second_number, 1);
    determine_data(&read_transactioned, &data, read_transactioned.result, data.len_result, 0);

    transaction_data_aux data_aux;

    //initialize the arrays
    for (int i = 0; i < data.digits; ++i) {
        data_aux.algarisms_value[i] = 0;
        data_aux.sum[i] = 0;
        data_aux.result[i] = 0;
        data.algarisms_MAX[i] = -1;
        data.result_MAX[i] = -1;

        //determine the position of the greater algarism in the transaction
        if (read_transactioned.first_number[0] == data.algarisms[i]) {
            data_aux.greater_algarism[0] = i;
        }

        //determine the position of the greater algarism in the transaction
        if (read_transactioned.second_number[0] == data.algarisms[i]) {
            data_aux.greater_algarism[1] = i;
        }

        //determine the position of the greater algarism in the transaction
        if (read_transactioned.result[0] == data.algarisms[i]) {
            data_aux.greater_algarism[2] = i;
        }
    }

    //determine the mask of the numbers
    mask_numbers(&data, &data_aux, read_transactioned.first_number, data.len_first_number, 0);
    mask_numbers(&data, &data_aux, read_transactioned.second_number, data.len_second_number, 1);
    mask_numbers(&data, &data_aux, read_transactioned.result, data.len_result, 2);

    //decrypt the transaction
    decrypt(&read_transactioned, &data, &data_aux, 0);

    //write the result on the output file
    write_transaction(argv[2], &data);

    return 0;
}
