#include<stdio.h>

void main() {
    int a[20], b[30], i, j, count, n;

    printf("Enter frame size (Example: 8): ");
    scanf("%d", &n);
    
    printf("Enter the frame (only 0's and 1's): ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    i = 0;
    j = 0;
    count = 0;

    while(i < n) {
        b[j++] = a[i];

        if(a[i] == 1) {
            count++;
        } else {
            count = 0;
        }

        if(count == 5) {
            b[j++] = 0;
            count = 0;
        }

        i++;
    }

    printf("After Bit Stuffing: ");
    for(i = 0; i < j; i++) {
        printf("%d", b[i]);
    }
}
