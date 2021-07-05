#include "phonebook.h"
extern int id_user;

void print_user()
{
    for (int i = 0; i < N && i < id_user; i++)
    {
        printf("|Id |Surname |Name |Phone     |\n");
        printf("%2d  %8s  %s  %s\n",i,users[i].surname,users[i].name,users[i].number);
        printf("\n");
    }
}