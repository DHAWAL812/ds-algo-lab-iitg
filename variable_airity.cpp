#include <bits/stdc++.h>


using namespace std;
struct node{
int data,v;
node *left,*parent,*next;

};
node* createt(int data)
{
    node *nnode=new node;
    nnode->data=data;
    nnode->v=0;
    nnode->left=NULL;
    nnode->parent=NULL;
    nnode->next=NULL;
    return nnode;
}
void addchild(node *parent,int data)
{
    node *temp=parent;
    if(temp->left==NULL)
    {
        node *nnode=createt(data);
        temp->left=nnode;
    }
    else
    {
        temp=temp->left;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *nnode=createt(data);
        nnode->parent=parent;
        temp->next=nnode;
        temp->parent=NULL;
    }
}

void traverse(node *root)
{

    if(root==NULL)
        return;

    if(root->v==0)
    {
        cout<<root->data<<" ";
        root->v=1;
    }

    traverse(root->left);
    traverse(root->next);
    if(root->parent!=NULL)
    {
    traverse(root->parent->next);
    }
}

int main()
{
    node *root=createt(1);
    addchild(root,2);
    addchild(root,3);
    addchild(root,4);

    addchild(root->left,6);
    addchild(root->left,7);
    addchild(root->left,8);
    traverse(root);

    return 0;
}
