#include "libmycalculator.h"


int main(void)
{
char number_menu;
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    int answer = 0;
    while(1)
    {
        number_menu = '6';
        scanf("%c",&number_menu);
        switch (number_menu)
        {
        case 49: //Сложение
            addition();
            break;
        case 50: //Вычитание
            subtraction();
            break;
        case 51: //Умножение
            multiplication();
            break;
        case 52: // Деление
           division();
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