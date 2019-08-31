#include <iostream>
using namespace std;

struct node
{
    long long data;
    struct node* right;
    struct node* left;
};

struct node* newNode(long long data, long long store[][3], long long i)
{
    struct node* x = new node();
    x->data = data;
    if(store[i][1]==-1)
    x->left = NULL;
    else
    x->left = newNode(store[store[i][1]][0], store, store[i][1]);
    if(store[i][2]==-1)
    x->right = NULL;
    else
    x->right = newNode(store[store[i][2]][0], store, store[i][2]);
    
    return x;

}

void PreOrder(struct node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(struct node* root)
{
    if(root==NULL)
    return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(struct node* root)
{
    if(root==NULL)
    return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int main(void)
{
    long long n, key, left, right, i;
    cin>>n;
    long long store[n][3];
    for(i=0;i<n;i++)
    cin>>store[i][0]>>store[i][1]>>store[i][2];
    struct node* root = newNode(store[0][0], store, 0); 
    InOrder(root);
    cout<<"\n";
    PreOrder(root);
    cout<<"\n";
    PostOrder(root);
      
    return 0;
}
