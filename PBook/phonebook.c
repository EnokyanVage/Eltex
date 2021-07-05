#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

struct phonebook
{
    char name[20];
    char surname[20];
    char number[12];
}users[N];

static int id_user = 0;

void add_user();
void print_user();
void search_user();
void delete_user();

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

void add_user()
{   
    if(id_user < N){
        char name[20];
        char surname[20];
        char number[12];
        printf("Name: ");
        scanf("%s",name);
        printf("\n");
        printf("Surname: ");
        scanf("%s",surname);
        printf("\n");
        printf("Number phone: ");
        scanf("%s",number);
        printf("\n");

        strcpy(users[id_user].name, name);
        strcpy(users[id_user].surname, surname);
        strcpy(users[id_user].number, number);
        id_user++;
    }
    else{
        printf("Error");
    }
}
void print_user()
{
    for (int i = 0; i < N && i < id_user; i++)
    {
        printf("%d %s %s %s\n",i,users[i].surname,users[i].name,users[i].number);
        printf("\n");
    }
}
void search_user()
{
    char surname[20];
    scanf("%s",surname);
        for (int i = 0; i < N && i < id_user; i++)
        {
            if(strcmp(surname,users[i].surname) == 0){
            printf("%d %s %s %s\n",i,users[i].surname,users[i].name,users[i].number);
            printf("\n");
        }
        else{
            printf("This surname is not on the list");
        }
    }
}
void delete_user()
{
    int delete_u;
    scanf("%d", &delete_u);

    memset(users[delete_u].name,0,20);
    memset(users[delete_u].surname,0,20);
    memset(users[delete_u].number,0,12);
    for(int j = delete_u + 1; j < N && j < id_user; j++)
    {
       strcpy(users[j-1].name,users[j].name); 
       strcpy(users[j-1].surname,users[j].surname); 
       strcpy(users[j-1].number,users[j].number); 
    }
    id_user-=1;
}
