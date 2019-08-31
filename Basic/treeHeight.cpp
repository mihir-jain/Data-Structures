#include <algorithm>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* child2;
    struct node* child1;
    struct node* parent;
};

int height(struct node* N)
{
    if(N==NULL)
    return 0;

    int h;
    h = 1 + max(height(N->child1), height(N->child2));
    return h;
}

int main(void)
{
   // cout<<"Hello";
    int n, i;
    cin>>n;
    int ar[n];
    for(i =0;i<n;i++)
    cin>>ar[i];
    
    node* ele[n];
    struct node* root;
    for(i=0;i<n;i++)
    {
        //cout<<"Hello";
        ele[i] = (node*)malloc(sizeof(node));
        ele[i]->data = i;
        //cout<<ele[i]->data<<" ";
        ele[i]->child1 = NULL;
        ele[i]->child2 = NULL;
    }

    for(i=0;i<n;i++)
    {
        if(ar[i]!=-1)
        {
            ele[i]->parent = ele[ar[i]];
            if(ele[ar[i]]->child1==NULL)
            ele[ar[i]]->child1 = ele[i];
            else            
            ele[ar[i]]->child2 = ele[i];
        }
        else
        {
            ele[i]->parent = ele[i]; 
            root = ele[i];
        }       
    }

    /*for(i=0;i<n;i++)
    {
        cout<<ele[i]->data<<" "<<ele[i]->parent->data<<" ";
        cout<<"\n";
    }
    */
    int h = height(root);
    cout<<h;
   
    return 0;
}