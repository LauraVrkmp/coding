#include <stdio.h>

#define MAX_MESSAGE 80

int main(void)
{
    char message[MAX_MESSAGE] = {0};
    char c;
    int i, amount, length = 0;

    printf("Enter message to be encrypted: ");

    for (i = 0; (c = getchar()) != '\n' && i < MAX_MESSAGE; i++) {
        message[i] = c;
        length++;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &amount);

    printf("Encrypted message: ");

    for (i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + amount) % 26 + 'A';
            putchar(message[i]);
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + amount) % 26 + 'a';
            putchar(message[i]);
        } else {
            putchar(message[i]);
        }
    }

    return 0;
}