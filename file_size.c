#include <stdio.h>
#include <stdlib.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Open the file in binary read mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file.\n");
        return -1;
    }

    // Move the file pointer to the end of the file
    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error: Unable to determine the file size.\n");
        fclose(file);
        return -1;
    }

    // Get the file size
    long file_size = ftell(file);
    if (file_size == -1) {
        fprintf(stderr, "Error: Unable to determine the file size.\n");
        fclose(file);
        return -1;
    }

    // Print the file size in bytes
    printf("The size of the file is: %ld bytes\n", file_size);

    // Close the file
    fclose(file);
    return 0;
}
