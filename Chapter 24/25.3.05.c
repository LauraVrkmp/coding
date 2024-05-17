#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

int main(void)
{
    char code;

    for (;;) {
        setjmp(env);
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'i': insert();
                        break;
            case 's': search();
                        break;
            case 'u': update();
                        break;
            case 'p': print();
                        break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}