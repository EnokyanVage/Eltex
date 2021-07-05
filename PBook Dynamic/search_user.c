#include "phonebook.h"
extern int id_user;


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