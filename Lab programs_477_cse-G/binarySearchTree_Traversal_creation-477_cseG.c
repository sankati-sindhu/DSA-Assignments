#include <stdio.h>
#include <stdlib.h>
#define initmemory() (struct node*)malloc(sizeof(struct node))

struct node {
    
    int data;
    struct node *left;
    struct node *right;
    
};

struct node* insert(struct node* root, int data) {
        
    if(root == NULL) {
    
        struct node* node = initmemory();

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
    
    } else {
            
        if(data <= root->data) { 
            root->left = insert(root->left, data);
        } 

        else {
            root->right = insert(root->right, data);;
        }
        return root;
    }
}

void inOrder(struct node *root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main() {
  
    struct node* root = NULL;
    
    int num,i;
    int data;

    printf("enter initial tree size\n");
    scanf("%d", &num);

    printf("Enter the elements in tree\n");
    for(i=0;i<num;i++){
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nIn Order\n");
    inOrder(root);
    return 0;

}



