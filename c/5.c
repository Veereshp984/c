#include <stdio.h>

int main() {
    int data[7], dataAtRec[7], c1, c2, c3, c, i;

    // Input 4 bits of data
    printf("Enter 4 bits of data:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate parity bits
    data[3] = data[0] ^ data[1] ^ data[2];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[6] = data[0] ^ data[2] ^ data[4];

    // Display encoded data
    printf("\nEncoded data: ");
    for (i = 0; i < 7; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    // Input received data bits
    printf("\nEnter received data bits:\n");
    for (i = 0; i < 7; i++) {
        scanf("%d", &dataAtRec[i]);
    }

    // Calculate parity check bits
    c1 = dataAtRec[6] ^ dataAtRec[4] ^ dataAtRec[2] ^ dataAtRec[0];
    c2 = dataAtRec[5] ^ dataAtRec[4] ^ dataAtRec[1] ^ dataAtRec[0];
    c3 = dataAtRec[3] ^ dataAtRec[2] ^ dataAtRec[1] ^ dataAtRec[0];
    c = c3 * 4 + c2 * 2 + c1;

    // Check for errors
    if (c == 0) {
        printf("\nNo error detected.\n");
    } else {
        printf("\nError at position %d\n", c);

        // Correct the error
        dataAtRec[7 - c] = (dataAtRec[7 - c] == 0) ? 1 : 0;

        printf("\nCorrected data: ");
        for (i = 0; i < 7; i++) {
            printf("%d", dataAtRec[i]);
        }
        printf("\n");
    }

    return 0;
}
