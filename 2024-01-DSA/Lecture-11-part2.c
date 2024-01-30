#include <stdio.h>
#include <string.h>
#define MAX 100
int top = -1;
int stk[MAX];
void push(char);

char pop();
int main(){
    char exp[MAX],temp;
    int i, flag=1;
    printf("Enter an expression : ");
    fgets(exp, MAX, stdin);
    //https://en.cppreference.com/w/c/io/fgets
    
    printf("Value of MAX\t %d \n", MAX);
    //printf("Value of strlen()\t %d \n", strlen(exp));
    printf("Value of strlen()\t %lu \n", strlen(exp));
    
    for(int i=0; i < strlen(exp); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);   
        }
         
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top == -1){
                flag=0;
            }
            else{
                temp=pop();
                if(exp[i]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(exp[i]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                if(exp[i]==']' && (temp=='(' || temp=='{'))
                    flag=0;
            }
        }
    }
    
    if(top>=0)
         flag=0;
    
    if(flag==1)
        printf("\n Valid expression\n");
    else
        printf("\n Invalid expression\n");
    
    return 0;
}

void push(char c){
    if(top == (MAX-1))
        printf("Stack Overflow\n");
    else{
        top=top+1;
        stk[top] = c;
    }
}

char pop(){
    if(top == -1){
        printf("\n Stack Underflow");
        return(stk[top--]);
    }
    else 
        return(stk[top--]);
}

