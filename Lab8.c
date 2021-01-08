#include <string.h>
#include <stdio.h>
#include <conio.h>
int count = 0;
struct node
{
    struct node *prev;
    int ssn;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
} * h, *temp, *temp1, *temp2, *temp4;
void create()
{
    int ssn;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter ssn,name,department, designation, salary and phno of employee : \n");
    scanf("%d %s %s %s %f %ld", &ssn, name, dept, desg, &sal, &phno);

    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}
void insertbeg()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
void insertend()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
    }
}
void displaybeg()
{
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : \n");
    while (temp2 != NULL)
    {
        printf("%d %s %s %s %f %ld\n", temp2->ssn, temp2->name, temp2->dept, temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf(" No of employees = %d ", count);
}
int deleteend()
{
    struct node *temp;
    temp = h;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        printf("%d %s %s %s %f %ld\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal,
               temp->phno);
        free(temp);
        h = NULL;
    }
    else

    {
        temp = temp1;
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%d %s %s %s %f %ld\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal,
               temp->phno);
        free(temp);
        temp1 = temp2;
    }
    count--;
    return 0;
}
int deletebeg()
{
    struct node *temp;
    temp = h;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        printf("%d %s %s %s %f %ld\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal,
               temp->phno);
        free(temp);
        h = NULL;
    }
    else
    {
        h = h->next;
        h->prev = NULL;
        printf("%d %s %s %s %f %ld", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal,
               temp->phno);
        free(temp);
    }
    count--;
    return 0;
}
void main()
{
    int ch, n, i;
    h = NULL;
    temp = temp1 = NULL;
    clrscr();
    printf(
        "-----------------MENU--------------------\n");

    printf("\n 1 create a DLL of n emp");
    printf("\n 2- Display from beginning");

    printf("\n 3- Insert at end");

    printf("\n 4- delete at end");

    printf("\n 5- Insert at beg");

    printf("\n 6- delete at beg");

    printf("\n 7- To show DLL as Queue");

    printf("\n 8- Exit\n");

    printf("------------------------------------------\n");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(" \n Enter no of employees : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            displaybeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            deletebeg();
            break;

        case 7:
            printf("\nTo show DLL as Queue,\n1. Perform insert and deletion operations by calling insertbeg() and deleteend() respectively.\n \tOR \n 2. Perform insert and deletion operations by calling insertend() and deletebeg() respectively\n");
            break;
        case 8:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}