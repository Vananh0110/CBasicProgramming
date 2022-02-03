/*Create an binary search tree with 10
nodes. Each node contains an
random integer.
• Ask user to input an number and
search for it.
• Print the content of the trees.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct nodetype{
    int value;
    struct nodetype *left,*right;
} nodetype;

//Kiem tra cay con phai
int leftof(const int value, const nodetype *root)
{
    return value< root->value;
}

//Kiem tra cay con phai
int rightof(const int value, const nodetype *root)
{
    return value > root ->value;
}

//Them node vao trong cay
nodetype* insert( nodetype*root,const int value)
{
    if(root==NULL)
    {
        nodetype* node=(nodetype*)malloc(sizeof(nodetype));
        node->left=NULL;
        node->right=NULL;
        node->value=value;
        return node;
    }
    else if(leftof(value,root))
    {
        root->left=insert(root->left,value);
    }
    else if(rightof(value,root))
    {
        root->right=insert(root->right,value);
    }
    return root;
}

//Duyet theo thu tu truoc
void preorder(nodetype* root)
{   if(root!=NULL)
    {
        printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void Free(nodetype* root)
{
    if(root==NULL) return ;
    Free(root->left);
    Free(root->right);
    Free(root);
}

void search(nodetype *root, int value)
{
    if(root->value == value)
    {
        printf("Tim thay gia tri %d tren cay",value);
    }
    else if(rightof(value, root))
    {
        search(root -> right, value);
    }
    else if(leftof(value,root))
    {
        search(root->left,value);
    }
    else printf("Khong tim thay gia tri %d tren cay\n",value);
    
}

int main()
{   
    nodetype *root=NULL;
    srand(time(0));
    int i;
    for(i=0;i<10;i++)
    {
       root=insert(root,rand());
    }
    printf("---------Duyet cay theo thu tu truoc-----------\n");
    preorder(root);
    printf("\nNhap gia tri muon tim kiem: \n");
    int value;
    scanf("%d",&value);
    search(root,value);    
    Free(root);
    return 0;
}
