
#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
struct node* insertion(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
    node->left  = insertion(node->left, key); 
    else if (key > node->key) 
    node->right = insertion(node->right, key);    
    return node; 
} 
struct node *find_min(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return(find_min(root->left));
    }
}
struct node* deletion(struct node *root,int item)
{
    struct node *temp;
    if(root==NULL)
    {
        printf("the tree is empty");
    }
    else if(item<root->key)
    {
        root->left=deletion(root->left,item);
    }
    else if(item>root->key)
    {
        root->right=deletion(root->right,item);
    }
    else
    {
        struct node *temp;
        if(root->left==NULL && root->right==NULL)
	    {
		    free(root);
		    return NULL;
	    }
        else if(root->left!=NULL && root->right!=NULL)
        {
            temp=find_min(root->right);
            root->key=temp->key;
            root->right=deletion(root->right,root->key);
        }
        else
        {
            temp=root;
            if(root->left==NULL)
            {
                root=root->right;
            }
            else if(root->right==NULL)
            {
                root=root->left;
            }
            free(temp);
        }
        return root;
    }
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
    inorder(root->left); 
    printf("%d \n", root->key); 
    inorder(root->right); 
    } 
}
int main() 
{
    int item;
    struct node *root = NULL; 
    root = insertion(root, 67);
    insertion(root, 12); 
    insertion(root, 10); 
    insertion(root, 43);
    insertion(root, 55); 
    inorder(root);
    root = deletion(root, 10);
    inorder(root);
}
  