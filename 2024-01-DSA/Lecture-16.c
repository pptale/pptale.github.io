#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
      
struct node *tree;

void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void inorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *deleteRootElement(struct node *tree, int); 
//Different Formulation

int main()
{
    int option, val;
    struct node *ptr;
    create_tree(tree);
    tree = insertElement(tree, 5);
    tree = insertElement(tree, 4);
    tree = insertElement(tree, 45);
    tree = insertElement(tree, 39);
    tree = insertElement(tree, 65);
    tree = insertElement(tree, 12);
    tree = insertElement(tree, 34);
    tree = insertElement(tree, 78);
    tree = insertElement(tree, 32);
    tree = insertElement(tree, 10);
    tree = insertElement(tree, 89);
    tree = insertElement(tree, 54);
    tree = insertElement(tree, 50);
    tree = insertElement(tree, 51);
    tree = insertElement(tree, 52);
    tree = insertElement(tree, 55);
    
    
    printf("The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    
    /*
    printf("Deleting 10\n");
    tree = deleteElement(tree, 10);
    printf("The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    
    printf("Deleting 34\n");
    tree = deleteElement(tree, 34);
    printf("The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    
    printf("Deleting 45\n");
    tree = deleteElement(tree, 45);
    printf("The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    
    printf("Deleting 65\n");
    tree = deleteElement(tree, 65);
    printf("The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    
    printf("Deleting 5\n");
    tree = deleteElement(tree, 5);
    printf("The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    */

    /*
    printf("Deleting 39\n");
    tree = deleteElement(tree, 39);
    printf("Deleting 56\n");
    tree = deleteElement(tree, 56);
    printf("Deleting 12\n");
    tree = deleteElement(tree, 12);
    printf("Deleting 34\n");
    tree = deleteElement(tree, 34);
    printf("Deleting 78\n");
    tree = deleteElement(tree, 78);
    printf("Deleting 32\n");
    tree = deleteElement(tree, 32);
    printf("Deleting 10\n");
    tree = deleteElement(tree, 10);
    printf("Deleting 89\n");
    tree = deleteElement(tree, 89);
    printf("Deleting 67\n");
    tree = deleteElement(tree, 67);
    
    printf("\n The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    */
    return 0; 
}

void create_tree(struct node *tree){
    tree = NULL;
}

struct node *insertElement(struct node *tree, int val){
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*) malloc(sizeof(struct node));
    
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    
    if(tree==NULL)
    {
       tree=ptr;
       tree->left = NULL;
       tree->right = NULL;
    }
    else{
        parentptr = NULL;
        nodeptr = tree;
        while(nodeptr != NULL){
            //Finding parent node of new-node
            parentptr=nodeptr;
            if(val < nodeptr->data) 
                nodeptr=nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        
        //Inserting new node.
        if(val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    
    return tree;
}

void inorderTraversal(struct node *tree)
{
    if(tree != NULL){
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    } 
}

struct node *findSmallestElement(struct node *tree){
    if( (tree == NULL) || (tree->left == NULL)) 
        return tree;
    else
        return findSmallestElement(tree->left);        
}

struct node *deleteElement(struct node *tree, int val)
{
    struct node *cur, *parent, *suc, *psuc, *ptr;
    //Corner case: If tree is empty
    //if(tree->left == NULL)
    if(tree == NULL){
        printf("The tree is empty \n");
        return(tree);
    }
    
    parent = tree;
    //cur = tree->left;
    cur = tree;
    while(cur != NULL && val != cur->data){
        parent = cur;
        cur = (val < cur->data) ? cur->left : cur->right;
        // i < 0 ? printf("i is below 0") : printf("i is not below 0");
    }
    
    //Sanity check
    if(cur == NULL){
        printf("The value to be deleted is not present in the tree\n");
        return(tree);
    }
    
    //Added the following part
    if(cur == tree){
        // The value to be deleted is at the root node.
        tree = deleteRootElement(tree, val);
        return tree;
    }

    if(cur->left == NULL)
        ptr = cur->right;
    else 
        if(cur->right == NULL)
        ptr = cur->left;
    else{
        // Find the in–order successor and its parent
        psuc = cur;
        //cur = cur->left; MAJOR CHANGE
        suc = cur->right;
        while(suc->left!=NULL){
            psuc = suc;
            suc = suc->left;
        }
        
        if(cur==psuc){
            // Situation 1: MAJOR CHANGE
            suc->left = cur->left;
            //psuc->left = suc->right;
        } 
        else {
            // Situation 2
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc; 
    }
    
    // Attach ptr to the parent node
    if(parent->left == cur)
        parent->left=ptr;
    else
        parent->right=ptr;
    
    free(cur);
    return tree;
}

struct node *deleteRootElement(struct node *tree, int val){
    struct node *cur, *parent, *suc, *psuc, *ptr;
    
    //Corner case: If tree is empty
    if(tree == NULL){
        printf("The tree is empty \n");
        return(tree);
    }
    
    if(tree->left == NULL){
        tree = tree -> right;
        return(tree);
    }
        
    if(tree -> right == NULL){
        tree = tree -> left;
        return(tree);
    }
    
    if (tree -> left == NULL && tree ->right == NULL){
        return NULL;
    }
    
    // Find the in–order successor and its parent
    psuc = tree;
    //cur = tree;
    //cur = cur->left; MAJOR CHANGE
    suc = tree->right;
    while(suc->left!=NULL){
        psuc = suc;
        suc = suc->left;
    }
    
    //suc->left = tree->left;
    tree->data = suc->data; 
    psuc->left = suc->right;
    //suc->right = tree->right;
    //tree = suc;
    //free(suc);
    return(tree);
}