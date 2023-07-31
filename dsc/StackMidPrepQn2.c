#include<stdio.h>
#define MAX 100
#include<stdlib.h>
#include<string.h>
struct stack{
    char data;
    struct stack* next;
}*top=NULL;

void push(char dt)
{
    struct stack* temp = (struct stack*) malloc(sizeof(struct stack));
    temp->data = dt;
    temp->next = top;
    top = temp;
}

void print()
{
    while(top)
    {
        printf("%c\n", top->data);
        top = top->next;
    }
}
char pop()
{
    if(top==NULL)
    {
        printf("Empty Stack\n");
        return '\0';
    }
    else
    {
        char c = top->data;
        struct stack* temp = top;
        top = top->next;
        temp = NULL;
        free(temp);
        return c;
    }
}
int bracketCheck(char a, char b)
{
    if((a=='{' && b=='}') || (a=='[' && b==']') || (a=='(' && b==')'))
        return 1;
    else
        return 0;
}
int main()
{
    char expr[MAX];
    printf("Enter the expression: \n");
    scanf("%s", expr);
    int q=0;
    while(expr[q])
    {
       if((expr[q]=='(') || (expr[q]=='[') || (expr[q]=='{'))
            {
                push(expr[q]);
            }
       if((expr[q]==')') || (expr[q]==']') || (expr[q]=='}'))
        {
            if(!bracketCheck(pop(), expr[q]))
            {
                printf("Brackets not balanced\n");
                return 0;
            }
       }
        q++;
    }
    if(top==NULL)
        printf("Brackets balanced\n");
    else
        printf("Brackets not balanced\n");
   // print();
    return 0;
}
