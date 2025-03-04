
#include <stdio.h>
int main() {
    int data[50], div[16], rem[16], datalen = 0, divlen = 0;
    char ch;
    printf("Enter data: ");
    while ((ch = getchar()) != '\n') {
        data[datalen++] = ch - '0';
    }
    printf("Enter divisor: ");
    while ((ch = getchar()) != '\n') {
        div[divlen++] = ch - '0';
    }
    // Append zeros to the data for CRC calculation
    for (int i = 0; i < divlen - 1; i++) {
        data[datalen + i] = 0;
    }
    // Initialize remainder with the first part of data
    for (int i = 0; i < divlen; i++) {
        rem[i] = data[i];
    }
    // Perform the CRC division
    for (int i = divlen; i <= datalen + divlen - 1; i++) {
        if (rem[0]) {
            for (int j = 1; j < divlen; j++) {
                rem[j - 1] = rem[j] ^ div[j];  // XOR operation for division
            }
        } else {
            for (int j = 1; j < divlen; j++) {
                rem[j - 1] = rem[j];  // Shift the remainder
            }
        }
        rem[divlen - 1] = data[i];  // Move the next data bit to the remainder
    }
    // Append the remainder (CRC checksum) to the data
    for (int i = 0; i < divlen - 1; i++) {
        data[datalen + i] = rem[i];
    }  
    // Print the final data to send (original data + checksum)
    printf("Data to send: ");
    for (int i = 0; i < datalen + divlen - 1; i++) {
        printf("%d", data[i]);
    }
    printf("\n"); 
    return 0;
}
