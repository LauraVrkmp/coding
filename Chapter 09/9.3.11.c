#include <ctype.h>

float compute_GPA(char grades[], int n)
{
    int i;
    float sum = 0.0f;

    for (i = 0; i < n; i++) {
        switch (toupper(grades[i])) {
            case 'A':
                sum += 4.0f;
                break;
            case 'B':
                sum += 3.0f;
                break;
            case 'C':
                sum += 2.0f;
                break;
            case 'D':
                sum += 1.0f;
                break;
            case 'F': default:
                break;
        }
    }

    return sum / n;
}