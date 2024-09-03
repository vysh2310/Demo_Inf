#include <stdio.h>

// Function prototype declaration for the vulnerable function
void vulnerable_function(const char *input);

int main() {
    char input[100];

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Call the vulnerable function
    vulnerable_function(input);

    printf("Done.\n");
    return 0;
}
