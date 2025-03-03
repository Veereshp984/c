// charater stuffing
#include <stdio.h>
#include <string.h>

void character_stuffing(const char *input, char *output, char ch, int pos) {
    strcpy(output, "dlestx");
    for (int i = 0, j = 6; input[i] != '\0'; i++) {
        if (i == pos - 1) {
            strcat(output, "dle");
            output[j + 3] = ch;
            strcat(output + j + 4, "dle");
            j += 7;
        } else if (!strncmp(&input[i], "dle", 3)) {
            strcat(output, "dle");
            j += 3;
        }
        output[j++] = input[i];
    }
    strcat(output, "dleetx");
}

int main() {
    char input[20], output[50];
    int pos;
    char ch;

    printf("Enter string: ");
    scanf("%s", input);
    printf("Enter stuffing position and character: ");
    scanf("%d %c", &pos, &ch);

    character_stuffing(input, output, ch, pos);
    printf("Frame after stuffing: %s\n", output);

    return 0;
}


//bit stuffing

#include <stdio.h>

void bit_stuffing(int *input, int n) {
    int output[50], j = 0, count = 0;
    for (int i = 0; i < n; i++) {
        output[j++] = input[i];
        if (input[i] == 1 && ++count == 5) {
            output[j++] = 0;
            count = 0;
        } else if (input[i] == 0) {
            count = 0;
        }
    }
    printf("After stuffing: ");
    for (int i = 0; i < j; i++) printf("%d", output[i]);
    printf("\n");
}

int main() {
    int n, input[20];
    printf("Enter frame length and bits: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &input[i]);
    bit_stuffing(input, n);
    return 0;
}
bit