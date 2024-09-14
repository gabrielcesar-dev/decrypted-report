#include "decryptor.h"

void error_digit (transaction_data *data,char *output_file) {
    //determine if the size of the result is greater than the size of the first number or the second number, if not, the result is invalid
    if (data->len_first_number > data->len_result || data->len_second_number > data->len_result)
        {
            FILE *file;

            file = fopen(output_file, "w");

            error_file(file);

            fprintf(file, "-1");

            fclose(file);

            exit(1);
        }
    }

void determine_data(transaction *read_transactioned, transaction_data *data, char *data_transactioned,int len, int test) {
    //determine the number of different digits in the transaction
    int count = 0;

    for (int i = 0; i < len; ++i) {
        //determine if the digit is already in the array
        switch (test) {
            //if the digit is in the first number, second number or result, add it
            case 0:
                for (int l = 0; l < data->len_second_number; ++l) {
                    if (data_transactioned[i] == read_transactioned->second_number[l]) {
                        count++;
                        break;
                    }
                }
            case 1:
                for (int k = 0; k < data->len_first_number; ++k) {
                    if (data_transactioned[i] == read_transactioned->first_number[k]) {
                        count++;
                        break;
                    }
                }
            case 2:
                for (int j = i; j >= 0; --j) {
                    if (data_transactioned[i] == data_transactioned[j] && i != j) {
                        count++;
                        break;
                    }
                }
        }
        //if the digit is not in the array, add it
        if (count == 0) {
            data->algarisms[data->digits] = data_transactioned[i];
            data->digits += 1;
        }else{
            count = 0;
        }
    }
}

void mask_numbers( transaction_data *data, transaction_data_aux *data_aux, char *transactioned, int len, int number){
    //determine the mask of the transaction
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < data->digits ; j++)
        {
            if (transactioned[i] == data->algarisms[j])
            {
                data_aux->mask_numbers[number][i] = j;
            }
        }
    }
}


void decrypt(transaction *read_transactioned, transaction_data *data, transaction_data_aux *data_aux, int index) {
    //determine if the algarism is greater than 9 or if the index is equal to the number of different digits
    if (index >= data->digits) {
        return;
    }

    //recursive function of the algarism
    for (int i = 0; i <= 9; i++){

        //determine if the algarism have zero in the first position
       if (i == 0){
        if (index == data_aux->greater_algarism[0] && data->len_first_number > 1){
            i++;
        }else if (index == data_aux->greater_algarism[1] && data->len_second_number > 1){
            i++;
        }else if (index == data_aux->greater_algarism[2] && data->len_result > 1){
            i++;
        }
       }

        //save the algarism
        data_aux->algarisms_value[index] = i;

        //call the function again
        decrypt(read_transactioned, data, data_aux, index + 1);

        //determine if the algarism is 9
        if( index != data->digits - 1 ){
            continue;
        }

        data_aux->flag_overflow = 0;
        
        //calculate the result of the transaction
         for (int i = data->len_result - 1; i >= 0 ; i--)
         {
            data_aux->result[i] = 0;
            data_aux->sum[i] = 0;
            data_aux->result[i] = data_aux->algarisms_value[data_aux->mask_numbers[2][i]];
         }

        //calculate the sum of the first number and the second number
       for (int i = data->len_first_number - 1, j = data->len_result - 1; i >= 0; i--, j--)
       {
            data_aux->sum[j] = data_aux->algarisms_value[data_aux->mask_numbers[0][i]];
       }

        //calculate the sum of the first number and the second number
       for (int i = data->len_second_number - 1, j = data->len_result - 1; j >= 0; i--, j--)
       {
            if (i >= 0)
            {
                data_aux->sum[j] += data_aux->algarisms_value[data_aux->mask_numbers[1][i]];
                    
            }

            //determine if the algarism is greater than 9
            if (data_aux->sum[j] > 9)
            {
                    data_aux->sum[j] -= 10;

                    if (j == 0)
                    {
                        data_aux->flag_overflow = 1;
                        break;
                    }
                
                    data_aux->sum[j - 1] += 1;
            }

       }

        //if overflow, the result is invalid
       if (data_aux->flag_overflow == 1)
       {
            continue;
       }

        //determine if the result is equal to the sum of the first number and the second number
        for (int i = 0; i < data->len_result; i++)
        {
            if (data_aux->sum[i] != data_aux->result[i])
            {
                data_aux->flag_overflow = 1;
                break;
            }
        }

        
        if (data_aux->flag_overflow == 0)
        {
            //determine if the result is greater than the previous result
            for (int i = 0; i < data->len_result; i++)
            {
                //save the result
                if (data_aux->result[i] > data->result_MAX[i])
                {
                    for (int j = 0; j < data->digits; ++j) {
                        data->algarisms_MAX[j] = data_aux->algarisms_value[j];
                    }

                    for (int j = 0; j < data->len_result; ++j) {
                        data->result_MAX[j] = data_aux->result[j];
                    }
                } else if (data_aux->result[i] < data->result_MAX[i])
                {
                    break;
                }
            }
        }
    }
}



