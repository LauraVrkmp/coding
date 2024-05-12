#include <stdio.h>

#define MAX_MESSAGE 80

void encrypt(char *message, int shift);

int main(void)
{
    char message[MAX_MESSAGE];
    char c, *p = message;
    int amount;

    printf("Enter message to be encrypted: ");

    while ((c = getchar()) != '\n' && p < message + MAX_MESSAGE)
        *p++ = c;
    *p = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &amount);

    encrypt(message, amount);
    printf("%s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    printf("Encrypted message: ");
    
    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A') + shift) % 26 + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
        message++;
    }
}