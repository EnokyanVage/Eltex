#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

struct phonebook
{
    char name[20];
    char surname[20];
    char number[12];
}*users;
void add_user();
void print_user();
void search_user();
void delete_user();