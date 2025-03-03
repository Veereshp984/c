#include <stdio.h>

typedef struct {
    int num;
    char str[50];
} Frame;

void sort(Frame arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].num > arr[j].num) {
                Frame temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of frames: ");
    scanf("%d", &n);
    Frame arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter frame number and content: ");
        scanf("%d %s", &arr[i].num, arr[i].str);
    }
    sort(arr, n);
    printf("Sorted frames:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\n", arr[i].num, arr[i].str);
    }
    return 0;
}
