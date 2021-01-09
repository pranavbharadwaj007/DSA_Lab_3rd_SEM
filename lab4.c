// Design ,develop and implement a program in C for converting an infix expression to Postfix wxpression.
// Program should support for both parenthesized and free parenthesized expressions with the : +
// ,-,*,/,%,^ and alphanumeric operands.


#define SIZE 50
#include<ctype.h>
#include<stdio.h>


char s[SIZE];
int top =0;         //global declaration of top of stack

void push(char elem)        //function to PUSH operations
    {
    s[++top]=elem;
    }

char pop ()     //function to POP operations
    {
    return(s[top--]);
    }

int pr(char elem)       //  function for precedence
{
    switch(elem){
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
    }
    return 0;
}

// main function

void main()
{
    char infx[50],pofx[50],ch,elem;
    int i=0,k=0;
    
    printf("\n Read the infix expression\n");
    scanf("%s",infx);
    push('#');

    while((ch=infx[i++])!='\0')
    {
        if (ch=='(')
        push(ch);

        else if (isalnum(ch))
        pofx[k++]=ch;
        else if (ch==')')
        {
            while (s[top]!='(')
            pofx[k++]=pop();
            elem =pop();
        }

        else
        {
            while (pr(s[top])>=pr(ch))
            pofx[k++]=pop();
            push(ch);
        }
        


    }

    while (s[top]!='#')
    pofx[k++]=pop();
    pofx[k]='\0';
    printf("\n\nGIVEN INFIX EXPRESSION : %s\nPOSTFIX EXPRESSION : %s\n",infx,pofx);
  
}
