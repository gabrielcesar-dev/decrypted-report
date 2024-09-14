#include "error_manager.h"

void argc_error (int argc) {
    if (argc != 3) {
        printf("Error: wrong number of arguments\n");
        exit(1);
    }
}
void error_file (FILE *file) {
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
}
    