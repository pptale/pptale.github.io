#include<stdio.h>
#include <stdlib.h>

int main(){
    
    //---------//
    /*
    // Turn a value into a pointer using &
    // Turn a pointer into a value with *
    int a = 10;
    int *ptr1; // Value at pointer ptr should be an integer.
    int *ptr = &a; // Location of integer a has been assigned to prt1
    printf("Value of a:\t %d\n", a);
    printf("Address of a:\t %16lu\n", &a);
    
    
    //---------//
    
    int b = *ptr; //Value at pointer ptr is assigned to b.
    //int b = a;
    a = 20;
    printf("Changed Value of a:\t %d\n", a);
    printf("Value of b:\t %d\n", b);
    */
    
    //---------//
    
    /*
    int arr[]={1,2,3,4,5,6,7,8,9};
    int *ptr1;// pointer to an integer
    int *ptr2;
    ptr1 = arr; //Note that arr is also a pointer to an integer
    // If int arr[10], then it fixes a pointer and next 10 posistions for this array

    ptr2 = &arr[8];
    while(ptr1<=ptr2){
        printf("%d\t", *ptr1);
        ptr1++;
    }
    printf("\n");
    */
    
    //---------//
    /*
    int *ptr = NULL;
    int n;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    
    // Dynamically allocate memory using malloc()
    ptr = (int *) malloc(n * sizeof(int));
    // int arr[n];
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
        // Get the elements of the array
        for (int i = 0; i < n; i++) {
            ptr[i] = i*i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int i = 0; i < n; i++) {
            printf("%d, ", ptr[i]);
        }
    }
    */
    //---------//
    
    //---------//
    /*
    struct student{
       int roll_no;
       char name[80];
       float fees;
       char DOB[80];
    };
    
    struct student stud1;
    struct student stud2;
    
    printf("\n Enter the roll number : ");
    scanf("%d", &stud1.roll_no);
    printf("\n Enter the name : ");
    scanf("%s", stud1.name);
    printf("\n Enter the fees : ");
    scanf("%f", &stud1.fees);
    printf("\n Enter the DOB : ");
    scanf("%s", stud1.DOB);
    printf("\n ********STUDENT'S DETAILS *******");
    printf("\n ROLL No. = %d", stud1.roll_no);
    printf("\n NAME = %s", stud1.name);
    printf("\n FEES = %f", stud1.fees);
    printf("\n DOB = %s", stud1.DOB);
    //---------//
    */
    
    //---------//
    
    struct student{
       int roll_no;
       char name[80];
       float fees;
       char DOB[80];
    };
    
    struct student stud1;
    stud1.roll_no = 25001;
    printf("%d\n", stud1.roll_no);
    
    //struct student *new_node;
    //*new_node = stud1;
    int * ptr;
    struct student *new_node;
    new_node = (struct student *) malloc(sizeof(struct student));
    
    (*new_node).roll_no = 25002;
    printf("%d\n", (*new_node).roll_no);
    
    new_node -> roll_no = 25003;
    printf("%d\n", (*new_node).roll_no);
    
    //---------//
    
    
    //---------//
    /*
    struct node {
        int data;
        struct node *next;
    };
    
    struct node *new_node;
    struct node *ptr;
    struct node *start = NULL;
    
    int num;
    
    printf("\n Enter -1 to end");
    printf("\n Enter the data:\t ");
    scanf("%d", &num);
    
    while(num!=-1){
        new_node = (struct node*) malloc(sizeof(struct node));
        new_node -> data = num;
        if(start==NULL){
            new_node -> next = NULL;
            start = new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->next=NULL;
        }
    printf("\n Enter the data:\t");
    scanf("%d", &num);
    }
    */
    printf("\n");
    return 0;
}









