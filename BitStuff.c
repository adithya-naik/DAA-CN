#include <stdio.h>
#include <string.h>

void bitStuffing() {
    char input[100], stuffed[200];
    int i, j = 0, count = 0;

    printf("Enter the binary data to be transmitted: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        stuffed[j++] = input[i];

        if (count == 5) { // After 5 consecutive 1s, stuff a 0
            stuffed[j++] = '0';
            count = 0;
        }
    }
    stuffed[j] = '\0';

    printf("Stuffed data: %s\n", stuffed);
}

int main() {
    bitStuffing();
    return 0;
}
