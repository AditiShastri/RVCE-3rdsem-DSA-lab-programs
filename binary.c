#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

struct node 
{
    int value;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;

NODE create_node(int value)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->value=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

NODE insert_left(NODE root,int value)
{
    NODE temp=create_node(value);
    if(root==NULL)
    {
        return NULL;
    }
    root->left=temp;
    return root;

}
NODE insert_right(NODE root,int value)
{
    NODE temp=create_node(value);
    if(root==NULL)
    {
        return NULL;
    }
    root->right=temp;
    return root;

}

int count_nodes(NODE root)
{
    if(root==NULL)
    {
        return 0;
    }
    return count_nodes(root->left)+count_nodes(root->right)+1;
}
int count_leaf_nodes(NODE root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        return count_leaf_nodes(root->left)+count_leaf_nodes(root->right);
    }
}
int height(NODE root)
{
    if(root==NULL)
    {
        return 0;
    }
    else{
        int leftht=height(root->left);
        int rightht=height(root->right);
        return leftht>rightht?leftht+1:rightht+1;
    }
}

void inorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d \t",root->value);
    inorder(root->right);
}
void preorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    
    printf("%d \t",root->value);
    preorder(root->left);
    preorder(root->right);
}
void postorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    
    
    postorder(root->left);
    postorder(root->right);
    printf("%d \t",root->value);
}
int main()
{
    NODE root=NULL;
    root=create_node(45);
    root=insert_left(root,39);
    root=insert_right(root,78);
    root->right=insert_left(root->right,54);
    root->right=insert_right(root->right,79);
    root->right->left=insert_right(root->right->left,55);
    root->right->right=insert_right(root->right->right,80);
    printf("\n The tree(inorder) is\n");
    inorder(root);
    printf("\n");
    printf("\n The total number of nodes is %d\n",count_nodes(root));
    printf("\n The height of the tree is %d\n",height(root));
    printf("\n The total number of leaf nodes is %d\n",count_leaf_nodes(root));
  
    return 0;
}