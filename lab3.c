#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define maxstk 10
int s[maxstk], top = 0, item, n;
void push();
void pop();
void display();
void pali();
int main()
{
    int choice = 1;

    while (choice)
    {
        printf("\n---STACK OPERATIONS---\n1.Push\n 2.Pop\n3.Palindrome\n4.Display\n5.Exit\n");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            pali();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid choice:\n");
            break;
        }
    }
    return 0;
}
//Inserting element into the stack
void push()
{
    if (top == maxstk)
    {
        printf("\nStack Overflow:");
        return;
    }
    else
    {
        printf("Enter the single digit element to be inserted into stack:\t");
        scanf("%d", &item);
        s[++top] = item;
    }
}
//deleting an element from the stack
void pop()
{
    if (top == 0)
    {
        printf("Stack Underflow:");
        return;
    }
    else
    {
        item = s[top--];
        printf("\nPoped element is : %d\n", item);
    }
}
void pali()
{
    int low = 1;
    int high = top;

        while (high > low)
    {
        if (s[low++] != s[high--])
        {
            printf("\n Stack is Not Palindrome");
            return;
        }
    }
    printf("\n Stack is palindrome");
}
//display the content of the stack
void display()

{
    int i;
    if (top == 0)
    {
        printf("\nStack is Empty:");
        return;
    }
    else
    {
        printf("\nThe stack elements are:\n");
        for (i = top; i >= 1; i--)
        {
            printf("%d\n", s[i]);
        }
    }
}