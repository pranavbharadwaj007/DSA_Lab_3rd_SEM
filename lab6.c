#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 4
char q[MAX], item;
int f = 0, r = 0, c = 0;
void insert(char data)
{
    // printf("Enter the ele: ");
    //  int flushall(void);
    // scanf("%c", &item);
    printf("element entered is %c \n", data);
    if ((f == 1 && r == MAX) || f == r + 1)
    {
        printf("queue overflow\n");
        return;
    }
    if (f == 0)
        f = r = 1;
    else if (r == MAX)
        r = 1;
    else
        r = r + 1;
    q[r] = data;
    printf("%c is inserted\n", data);
    c = c + 1;
    return;
}

void delete ()
{
    if (f == 0)
    {
        printf("queue underflow\n");
        return;
    }
    item = q[f];
    printf("\nDeleted Element is %c\n", item);
    if (f == r)
        f = r = 0;
    else if (f == MAX)
        f = 1;
    else
        f = f + 1;
    c = c - 1;
    return;
}
void display()
{
    int i;
    if (f == 0)
    {
        printf("queue underflow\n");
        return;
    }
    else //f<r
    {
        printf("queue elements are\n");
        if (f <= r)
        {
            for (i = f; i <= r; i++)
            {
                printf("%c\t", q[i]);
            }
        }
        else
        {
            for (i = f; i <= MAX; i++)
            {
                printf("%c\t", q[i]);
            }
            for (i = 1; i <= r; i++)
            {
                printf("%c\t", q[i]);
            }
        }
    }
    printf("\nStatus of Queue:\n rear is at %d\n front is at %d", r, f);
    return;
}
int main()
{
    int ch;
    char data;
    // getch();
    // clrscr();

    printf("Q Operations\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter your Choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the ele: ");
            scanf(" %c", &data);
            insert(data);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid\n");
        }
    }
    return 0;
}
