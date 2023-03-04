#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left =left;
        this->right=right;
        
    }
    int height(node *root);
    int size (node *root);
    int counttwo(node * root);
    int sum(node *root);
    bool iscbt(node * root,int index,int node_count);
};

bool node :: iscbt(node *root,int index,int node_count)
{
    if(root==NULL)
    return false;
    if(index>=node_count)
    return true;

    return iscbt(root->left,2*index,node_count)  && iscbt(root->right,2*index+1,node_count);
}

int node :: counttwo(node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    else {
        if(root->left!=NULL && root->right!=NULL)
        return (counttwo(root->left)+counttwo(root->right));
    }
}

int node :: size(node *root)
{
    int left,right;
    if(root==NULL)
    return 0;
    else{
        return (1+size(root->left)+size(root->left));
    }
}

int node :: sum(node * root)
{
    int sumleft=0,sumright=0;
    if(root==NULL)
    {
        return 0;
    }
    else{
        sumleft += sum(root->left);
        sumright += sum(root->right);
        return(root->data + sumleft + sumright );
    }
}


int node :: height(node * root)
{
    int left,right;
    if(root== NULL)
    {
        return 0;
    }
    else 
    {
    left = height(root->left);
    right = height(root->right);
    if(left>right)
    return left+1;
    else 
    return right+1;
    }
}

int main()
{
    node *root = new node(1);
    node * start = root;
    root->left = new node(3);
    root->right = new node(2);
    
    return 0;
}
