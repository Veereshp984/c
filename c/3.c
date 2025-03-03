#include <stdio.h>

int main() {
    int data[50], div[16], rem[16];
    int datalen = 0, divlen = 0;

    // Input data
    printf("Enter the data (0s and 1s): ");
    char ch;
    while ((ch = getchar()) != '\n') {
        data[datalen++] = ch - '0';
    }

    // Input divisor
    printf("Enter the divisor (0s and 1s): ");
    while ((ch = getchar()) != '\n') {
        div[divlen++] = ch - '0';
    }

    // Append zeros to data for CRC
    for (int i = 0; i < divlen - 1; i++) {
        data[datalen + i] = 0;
    }

    // Initialize remainder with the first part of the data
    for (int i = 0; i < divlen; i++) {
        rem[i] = data[i];
    }

    // Perform division
    for (int i = divlen; i <= datalen + divlen - 1; i++) {
        if (rem[0] == 1) {
            for (int j = 1; j < divlen; j++) {
                rem[j - 1] = rem[j] ^ div[j];
            }
        } else {
            for (int j = 1; j < divlen; j++) {
                rem[j - 1] = rem[j];
            }
        }
        rem[divlen - 1] = data[i];
    }

    // Combine remainder with data for the final message
    for (int i = 0; i < divlen - 1; i++) {
        data[datalen + i] = rem[i];
    }

    // Display final data
    printf("The data to be sent is: ");
    for (int i = 0; i < datalen + divlen - 1; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    retu
