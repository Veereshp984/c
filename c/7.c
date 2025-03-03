#include <stdio.h>

int main() {
    int bucketSize, outputRate, line, packetRate[25], currentSize = 0;

    // Input bucket size and output rate
    printf("Enter bucket size and output rate: ");
    scanf("%d %d", &bucketSize, &outputRate);

    // Input number of lines
    printf("Enter the number of input lines: ");
    scanf("%d", &line);

    // Input the packet rate for each line
    printf("Enter packet rate for %d lines:\n", line);
    for (int i = 0; i < line; i++) {
        scanf("%d", &packetRate[i]);
    }

    // Process each packet rate
    for (int i = 0; i < line; i++) {
        currentSize += packetRate[i]; // Add packet to the bucket

        // Check if bucket overflows
        if (currentSize <= bucketSize) {
            printf("Input from line %d with rate %d added to the bucket. Current size: %d\n", i + 1, packetRate[i], currentSize);
        } else {
            currentSize -= packetRate[i]; // Discard packet if overflow
            printf("Input from line %d with rate %d discarded. Current size: %d\n", i + 1, packetRate[i], currentSize);
        }
    }

    // Output the packets at the specified output rate
    if (currentSize <= outputRate) {
        printf("All packets sent at output rate %d. Bucket empty.\n", currentSize);
        currentSize = 0;
    } else {
        currentSize -= outputRate;
        printf("Packets sent at output rate %d. Remaining bucket size: %d\n", outputRate, currentSize);
    }

    return 0;
}
