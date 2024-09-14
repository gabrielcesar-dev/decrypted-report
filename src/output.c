#include "output.h"

void write_transaction(char *output_file, transaction_data *data) {
    FILE *file;

    file = fopen(output_file, "w");
    error_file(file);

    // If the result is less than or equal to 0, then the transaction is invalid
    if (data->result_MAX[0] < 0) {
        fprintf(file, "-1");

        fclose(file);

        return;
    }

    for (int i = 0; i < data->len_result; ++i) {
        // Write the result on the output file
        fprintf(file, "%d", data->result_MAX[i]);
    }

    fprintf(file, "\n");

    for (int i = 0; i < data->digits; ++i) {
        fprintf(file, "%c:%d\n", data->algarisms[i], data->algarisms_MAX[i]);
    }

    fclose(file);
}
