#include <iostream>
#include <vector>
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

void InOrder(struct node* root, vector<long long> &ar)
{
    if(root==NULL)
    return;
    if(root->left!=NULL && root->left->data == root->data)
    root->left->data +=1;  
    InOrder(root->left, ar);
    ar.push_back(root->data);
    InOrder(root->right, ar);
    //ar.push_back(root->data);
    //cout<<root->data<<" ";
}



int main(void)
{
    long long n, key, left, right, i;
    cin>>n;
    if(n==0)
    {
        cout<<"CORRECT";
        return 0;
    }
    long long store[n][3];
    for(i=0;i<n;i++)
    cin>>store[i][0]>>store[i][1]>>store[i][2];
    struct node* root = newNode(store[0][0], store, 0); 
    //root = modify(root);
    vector<long long> ar;
    bool flag = true;
    InOrder(root, ar);
    long long l = ar.size();
    long long arr[l];
    for(i=0;i<l;i++)
    arr[i] = ar[i];

    //for(i=0;i<l;i++)
    //cout<<arr[i]<<" ";
    //cout<<"\n";

    i = 0;
    if(l==2)
    {
       if(ar[i]>ar[i+1])
       {
           flag = false;
           cout<<"INCORRECT";
       }
    }
    else
    {
        for(i=0;i<l-2;i++)
        {
            if(arr[i]>arr[i+1] || arr[i]>arr[i+2] || arr[i+1]> arr[i+2])
            {
                cout<<"INCORRECT";
                flag = false;
                break;
            }
            //i++;
        }
    }
    if(flag== true)
    cout<<"CORRECT"     ;
    return 0;
}
