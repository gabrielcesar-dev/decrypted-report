# Decrypting Transactions – Computer Programming I

Welcome to the **Decrypting Transactions** project. This project focuses on deciphering encrypted transaction values. If the sum of the first two numbers is equal to the third, the transaction is considered solved. This README provides details on how to use and compile the program, along with an overview of the modularization and usage instructions.

## Authors

- Gabriel Cesar Silvino Xavier

## Acknowledgements

- Prof. Daniel Saad Nogueira Nunes

## Modularization

- **Input Module**: Reads the transaction reports from a text file.
- **Output Module**: Prints the deciphered result to a text file.
- **Processing Module**: Deciphers the transaction reports, if possible.
- **Error Handling Module**: Captures and reports errors to the user, if necessary.

## Features

The input and output file paths should be obtained via command line arguments, as described in the Compilation and Execution section.

- **Input File**
  The input file contains three lines representing the values A, B, and C, where C is the sum of A and B.

### Restrictions:
- 1 ≤ |A|, |B|, |C| ≤ 8
- A, B, or C do not have leading zeros but can be zero.

- **Output File**
  The first line of the output file should contain the largest possible value of C. If the transaction cannot be deciphered, the output should be "-1". If successful, subsequent lines should describe the mapping used to decipher the transaction in the format "c : d", where *c* is a character and *d* is the corresponding digit.

## Deployment

### Compile

To compile this project, run:

```bash
  make
```

### Run

To execute the program, run:

```bash
 ./bin/main parameter01 parameter02
```

- `parameter01`: Absolute path to the input transaction file.
- `parameter02`: Absolute path to the output report file.
