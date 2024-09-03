#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Vulnerable function that copies user input to a buffer without bounds checking
void vulnerable_function(const char *input) {
    char buffer[50];
    char *dynamic_buffer;
    int uninitialized_var;

    // 1. Buffer overflow vulnerability
    strcpy(buffer, input); // Unsafe: no bounds checking on input length
    printf("Buffer contents: %s\n", buffer);

    // 2. Use of uninitialized variable
    if (uninitialized_var > 0) { // Unsafe: 'uninitialized_var' is not initialized
        printf("Uninitialized variable is greater than 0!\n");
    }

    // 3. Buffer overflow on dynamically allocated memory
    dynamic_buffer = (char *)malloc(25);
    if (dynamic_buffer == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(dynamic_buffer, input); // Unsafe: no bounds checking, dynamic_buffer can overflow
    printf("Dynamic Buffer contents: %s\n", dynamic_buffer);

    // Clean up
    free(dynamic_buffer);
}

