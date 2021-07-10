#include "libmycalculator.h"


int main(void)
{
char number_menu;
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    int answer;
    int v1 = 0,v2 = 0;
    while(1)
    {
        number_menu = '6';
        scanf("%c",&number_menu);
        switch (number_menu)
        {
        case 49: //Сложение
            printf("variable 1:");
            scanf("%d",&v1);
            printf("variable 1:");
            scanf("%d",&v2);
            answer = addition(v1,v2);
            printf("%d\n",answer);
            break;
        case 50: //Вычитание
            printf("variable 1:");
            scanf("%d",&v1);
            printf("variable 1:");
            scanf("%d",&v2);
            answer = subtraction(v1,v2);
            printf("%d\n",answer);
            break;
        case 51: //Умножение
            printf("variable 1:");
            scanf("%d",&v1);
            printf("variable 1:");
            scanf("%d",&v2);
            answer = multiplication(v1,v2);
            printf("%d\n",answer);
            break;
        case 52: // Деление
            printf("variable 1:");
            scanf("%d",&v1);
            printf("variable 1:");
            scanf("%d",&v2);
                if(v2 != 0)
                {
                answer = division(v1,v2);
                printf("%d\n",answer);
                }
                else
                {
                    printf("You cannot divide by zero!\n");
                }
            break;
        case 53: //Выход
            exit(0);
        break;
        default:
            main();
            break;
        }
    }
    return 0;
}