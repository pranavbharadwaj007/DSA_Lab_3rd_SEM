#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20
int a[MAX], n, val, i, pos;

void create();
void display();
void insert();
void delet();
void main()
{
    int choice = 1;
    while (choice)
    {
        printf("\n\n--------MENU-----------\n");
        printf("1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.EXIT\n");
        printf("\nENTER YOUR CHOICE:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delet();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid choice:\n");
            break;
        }
    }
}

void create()

{
    printf("\nEnter the size of the array elements:\t");
    scanf("%d", &n);
    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
//displaying an array elements
void display()
{
    printf("\nThe array elements are:\n");
    for (i = 0; i < MAX; i++)
    {
        if (a[i])
            printf("%d\t", a[i]);
    }
}
//inserting an element into specified position of an array
void insert()
{
    printf("\nEnter the array position for the new element:\t");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted :\t");
    scanf("%d", &val);
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    n = n + 1;
}

void delet()
{
    printf("\nEnter the array position of the element to be deleted:\t");
    scanf("%d", &pos);
    val = a[pos];
    //deleting at end
    if (pos == n - 1)
        a[pos] = 0;
    else

    {
        for (i = pos; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = 0;
    }
    n = n - 1;
    printf("\nThe deleted element is =%d", val);
}