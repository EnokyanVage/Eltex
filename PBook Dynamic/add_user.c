#include "phonebook.h"
#include <errno.h>
int id_user = 0;
void add_user()
{   

    if(id_user < N){

        if(users == 0) 
        {users = (struct phonebook*) malloc(sizeof(struct phonebook));}
        else { 
            users = (struct phonebook*) realloc(users,(id_user + 1) * sizeof(struct phonebook));
        }
        if(users == 0)
        {
            perror("Out of memory!\n");
            exit(EXIT_FAILURE);
        }
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