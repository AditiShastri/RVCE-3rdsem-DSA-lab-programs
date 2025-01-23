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

NODE create_node(int value)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->value=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

NODE insert(NODE root, int key)
{
    NODE temp=create_node(key);
    if(root==NULL)
    {
        return temp;
    }
    else
    {
        if(root->value<=key)
        {
            root->right=insert(root->right,key);
        }
        else
        {
            root->left=insert(root->left,key);
    
        }
        return root;
    }
}

NODE inorder_successor(NODE root) //called as inorder successor of rot->right
{
    NODE cur=root;
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        while(cur->left!=NULL)
        {
            cur=cur->left;
        }
        return cur;
    }
    
}

NODE delete(NODE root, int key)
{
    NODE temp;
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(root->value<key)
        {
            root->right=delete(root->right,key);
        }
        else if(root->value>key)
        {
            root->left=delete(root->left,key);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                free(root);
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL)
            {
                temp=root->right;
                //root->value=temp->value;
                free(root);
                return temp;
            }
            else if(root->right==NULL && root->left!=NULL)
            {
                temp=root->left;
                //root->value=temp->value;
                free(root);
                return temp;
            }
            else
            {
                temp=inorder_successor(root->right);
                root->value=temp->value;
                
                root->right=delete(root->right,temp->value);
                return root;

            }
        }
    }
    return root;
}

int main()
{
    NODE root=NULL;
    int choice,key;
    while(1)
    {
        printf("1.insert\n2.delete\n3.inorder\n4.preorder\n5.postorder\n6.exit\n");

        scanf("%d",&choice);
        
            switch(choice)
            {
                case 1:
                    printf("\n Read element to be inserted :");
                    scanf("%d",&key);
                    root=insert(root,key);
                    break;
                case 2:
                    printf("\n Read node to be deleted : ");
                    scanf("%d",&key);
                    root=delete(root,key);
                    break;

                case 3:
                    printf("\n The Inorder traversal is\n");
                    inorder(root);

                    break;

                case 4:
                    printf("\n The Preorder traversal is\n");
                    preorder(root);
                    break;

        
                case 5:
                    printf("\n The Postorder traversal is\n");
                    postorder(root);

                    break;
                default :exit(0);
            
           
            }
    }

   
}