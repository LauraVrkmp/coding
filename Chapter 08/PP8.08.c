#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_QUIZZES 5

int main(void)
{
    int grades[NUM_STUDENTS][NUM_QUIZZES];
    int student, quiz, total, high, low;

    for (student = 0; student < NUM_STUDENTS; student++) {
        printf("Enter grades for student %d: ", student + 1);

        for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
            scanf("%d", &grades[student][quiz]);
        }
    }

    printf("\nStudent\tTotal\tAverage\n");
    for (student = 0; student < NUM_STUDENTS; student++) {
        total = 0;
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
            total += grades[student][quiz];
        }
        printf("  %d\t%d\t%.2f\n", student + 1, total, (float) total / NUM_QUIZZES);
    }

    printf("\nQuiz\tAverage\tHigh\tLow\n");
    for (quiz = 0; quiz < NUM_STUDENTS; quiz++) {
        total = 0;
        high = 0;
        low = 100;
        for (student = 0; student < NUM_QUIZZES; student++) {
            total += grades[student][quiz];
            if (grades[student][quiz] > high)
                high = grades[student][quiz];
            if (grades[student][quiz] < low)
                low = grades[student][quiz];
        }
        printf("  %d\t%.2f\t%d\t%d\n", quiz + 1, (float) total / NUM_STUDENTS, high, low);
    }
    return 0;
}