#include<stdio.h>
#include<stdlib.h>
struct stac
{
    int data;
    struct stac* next;
};

void push(struct stac** top, int dt)
{
        struct stac* temp = (struct stac*) malloc(sizeof(struct stac));
        temp->data = dt;
        temp->next = *top;
        *top = temp;
        printf("%d added\n", temp->data);
}
void display(struct stac* top)
{
   while(top)
   {
       printf("%d\n", top->data);
       top = top->next;
   }
}
int pop(struct stac** top)
{
    struct stac* temp = *top;
    int val = temp->data;
    *top = temp->next;
    temp = NULL;
    free(temp);
    return val;
}

void deleteEven(struct stac** top)
{
    int v=0;
    struct stac* temp = (struct stac*)malloc(sizeof(struct stac));
    temp = NULL;
    while(*top!=NULL)
     {
      v = pop(top);
      printf("====================== %d\n", v); //pop successful
        if(v%2==1)
        {
            push(&temp, v);
        }
    }
    if(*top==NULL)
        *top = temp;
     display(*top);
}
int main()
{
    struct stac* top = NULL;
    push(&top, 7);
    push(&top, 21);
    push(&top, 4);
    push(&top, 3);
    push(&top, 4);
    pop(&top);
    pop(&top);
   deleteEven(&top);

    return 0;
}
