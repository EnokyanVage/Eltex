#include "phonebook.h"

int main(void)
{
    char number_menu;
    printf("1. Add user\n");
    printf("2. Output of all users\n");
    printf("3. Search user\n");
    printf("4. Delete user\n");
    printf("5. Exit\n");
    
    while(1)
    {
        number_menu = '6';
        scanf("%c",&number_menu);
        switch (number_menu)
        {
        case 49: //Добавить
            add_user();
            break;
        case 50: //Вывод всех абонентов
            print_user();
            break;
        case 51: //Поиск
            search_user();
            break;
        case 52: // Удалить
            delete_user();
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