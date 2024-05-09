#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define bool _Bool
#define true 1
#define false 0

int roll_dice(void);
bool play_game(void);

int main(void)
{
    bool won;
    int choice, times_won = 0, times_lost = 0;

    srand((unsigned) time(NULL));
    
    while (true) {
        if (play_game())
            times_won++;
        else
            times_lost++;
        
        printf("Play again? ");
        scanf(" %c", &choice);
    
        if (choice != 'Y' && choice != 'y')
            break;

        printf("\n");
    }

    printf("\nWins: %d\tLosses: %d\n", times_won, times_lost);
}

int roll_dice(void)
{
    int random1, random2;

    random1 = rand() % 6 + 1;
    random2 = rand() % 6 + 1;

    return random1 + random2;
}

bool play_game(void)
{
    int hand = roll_dice(), point;

    printf("You rolled: %d\n", hand);

    if (hand == 7 || hand == 11) {
        printf("You win!\n\n");
        return true;
    } else if (hand == 2 || hand == 3 || hand == 12) {
        printf("You lose!\n\n");
        return false;
    } else {
        printf("Your point is %d\n", point = hand);
    }

    while (hand = roll_dice()) {
        printf("You rolled: %d\n", hand);

        if (hand == point) {
            printf("You win!\n\n");
            return true;
        }
        if (hand == 7) {
            printf("You lose!\n\n");
            return false;
        }
    }
}
