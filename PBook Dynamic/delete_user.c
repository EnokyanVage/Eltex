#include "phonebook.h"
extern int id_user;

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
