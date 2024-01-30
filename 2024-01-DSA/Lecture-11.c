//STACK -- First In Last Out (FILO)

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main(){
    // Created 
    /*
    for(int i=1; i <= 10; i++){
        top = push(top, i*i);
    }
    top = display(top);
    printf("\n");
    
    top = pop(top);
    printf("\n");
    top = display(top);
    printf("\n");
    
    int top_value = peek(top);
    printf("Top value %d \n", top_value);
    
    top = display(top);
    printf("\n");
    */
    
    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr -> data = val;
    if(top == NULL){
        ptr -> next = NULL;
        top = ptr;
    }
    else{
        ptr -> next = top;
        top = ptr;
    }
    return top;
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n STACK IS EMPTY");
    }
    else
    {
        printf("\n Displaying Stack");
        while(ptr != NULL){
            printf("\n %d", ptr -> data);
            ptr = ptr -> next;
            
        }
    }
    return top;
}

struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n STACK UNDERFLOW");
        }
    else{
        top = top -> next;
        printf("\n The value being deleted is: %d", ptr -> data);
        free(ptr);
    }
    return top;
}

int peek(struct stack *top){
    if(top==NULL) return -1;
    else
        return top ->data;
}