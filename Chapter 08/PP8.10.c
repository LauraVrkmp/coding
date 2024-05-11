#include <stdio.h>

int main(void)
{
    int hours, minutes, minutes_since_midnight, d_hours, d_minutes, a_hours, a_minutes;

    int dep[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arr[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    minutes_since_midnight = hours * 60 + minutes;

    printf("Closest departure time is ");

    for (int i = 0; i < 7; i++) {
        if (minutes_since_midnight <= dep[i] + (dep[i + 1] - dep[i]) / 2) {

            d_hours = dep[i] / 60 > 12 ? dep[i] / 60 - 12 : dep[i] / 60;
            d_minutes = dep[i] % 60;
            a_hours = arr[i] / 60 > 12 ? arr[i] / 60 - 12: arr[i] / 60;
            a_minutes = arr[i] % 60;

            printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n", 
                   d_hours, d_minutes, dep[i] / 60 > 11 ? 'p' : 'a',
                   a_hours, a_minutes, arr[i] / 60 > 11 ? 'p' : 'a');
            return 0;
        }
    }

    d_hours = dep[7] / 60 > 12 ? dep[7] / 60 - 12 : dep[7] / 60;
    d_minutes = dep[7] % 60;
    a_hours = arr[7] / 60 > 12 ? arr[7] / 60 - 12 : arr[7] / 60;
    a_minutes = arr[7] % 60;
   
    printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
           d_hours, d_minutes, dep[7] / 60 > 11 ? 'p' : 'a',
           a_hours, a_minutes, arr[7] / 60 > 11 ? 'p' : 'a');
           
   return 0;
}