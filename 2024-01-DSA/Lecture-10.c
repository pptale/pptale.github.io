#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * start = NULL;
struct node *create_ll(struct node * ptr1);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);


int main(){
    //---------//    
    struct node *start = NULL;
    
    printf("\n Create a list");
    start = create_ll(start);
    /*
    printf("\n Display the list\n");
    start = display(start);
    
    printf("\n Add a node at the beginning\n");
    start = insert_beg(start);
    printf("\n Display the list\n");
    start = display(start);

    printf("Add a node at the end\n");
    start = insert_end(start);
    printf("\n Display the list\n");
    start = display(start);
    
    printf("Add a node before a given node\n");
    start = insert_before(start);
    printf("\n Display the list\n");
    start = display(start);
    
    
    printf("Add a node after a given node\n");
    start = insert_after(start);
    printf("\n Display the list\n");
    start = display(start);
    
    
    printf("Delete a node from the beginning\n");
    start = delete_beg(start);
    printf("\n Display the list\n");
    start = display(start);
    
    
    printf("Delete a node from the end\n");
    start = delete_end(start);
    printf("\n Display the list\n");
    start = display(start);
    
    
    printf("Delete a given node\n");
    start = delete_node(start);
    printf("\n Display the list\n");
    start = display(start);
    
    
    printf("Delete a node after a given node\n");
    start = delete_after(start);
    printf("\n Display the list\n");
    start = display(start);
    
    
    printf("Delete the entire list\n");
    start = delete_list(start);
    printf("\n LINKED LIST DELETED");
    printf("\n Display the list\n");
    start = display(start);
    */
    
    //printf("Sort the list");
    //start = sort_list(start); 
    return 0;
}

struct node *create_ll(struct node *start){
    struct node * new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num!=-1){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data=num;
        if(start==NULL){
            new_node -> next = NULL;
            start = new_node;}
        else {
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = NULL;
    ptr = start;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = new_node;
    return start;
}

struct node *insert_before(struct node *start){
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val){
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
    return start;
}

struct node *insert_after(struct node *start){
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    preptr = ptr;
    while(preptr -> data != val){
         preptr = ptr;
         ptr = ptr -> next;
    }
    preptr -> next=new_node;
    new_node -> next = ptr;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}
    
struct node *delete_end(struct node *start){
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr -> next != NULL){
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);
    return start;
}


struct node *delete_node(struct node *start){
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    if(ptr -> data == val){
        start = delete_beg(start);
        return start;
    }
    else {
        while(ptr -> data != val){
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
        return start;
    }
}

struct node *delete_after(struct node *start){
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while(preptr -> data != val){
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next=ptr -> next;
    free(ptr);
    return start;
}


struct node *delete_list(struct node *start){
    struct node *ptr; // Lines 252-254 were modified from original code to fix unresposiveness in output window
    if(start!=NULL){
        ptr=start;
        while(ptr != NULL){
            printf("\n %d is to be deleted next", ptr -> data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}