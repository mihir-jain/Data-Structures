#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long p = 1000003;
const long long a = 34;
const long long b = 45;
const long long m = 1000;

struct node
{
    long long number;
    string name;
    struct node* next;
};

long long hash_value(long long number)
{
    return (((a*number + b) % p) % m);
}

void find(node ar[], long long number, vector<string> &X)
{
    long long hash_val = hash_value(number);
    struct node* current = ar[hash_val].next;
    bool flag = false;
    string name;
    while(current!=NULL)
    {
        if(current->number==number)
        {
            flag = true;
            name = current->name;            
        }
        current = current->next;
    }

    if(flag==true)
    X.push_back(name);
    else
    X.push_back("not found");
}

void add(node ar[], string name, long long number)
{
    long long hash_val = hash_value(number);
    //cout<<hash_val<<"\n";
    struct node* arr = new node();
    arr = &ar[hash_val];
    struct node* current = ar[hash_val].next;
    //cout<<current;
    while(current!=NULL)
    {
        if(current->number==number)
        {
            current->name = name;
            return;
        }
        current = current->next;
    }

    struct node* x;
    while(arr!=NULL)
    {
        //cout<<"CHECL";
        x = arr;
        arr = arr->next;
    }

    struct node* new_name = new node();
    new_name->name = name;
    new_name->number = number;
    new_name->next = NULL;
    x->next = new_name;
    //cout<<"CEHCKE@";
}

void del(node ar[], long long number)
{
    long long hash_val = hash_value(number);
    struct node* track = &ar[hash_val];
    struct node* current = ar[hash_val].next;
    cout<<current;
    while(current!=NULL)
    {
        if(current->number==number)
        {
            track->next = current->next;
            break;
        }
        track = current;
        current = current->next;
    }
}

int main(void)
{
    //cout<<"hello";
    long long n, i, number, hash_val;

    vector<string> X;

    long long k = 0;
    node ar[m];
    for(i=0;i<m;i++)
    {
     
        ar[i].number = i;
        ar[i].next = NULL;
    }
    cin>>n;
    //cout<<"hello1";
    string op, name;
    //long long m = 1000;

    for(i=0;i<n;i++)
    {
        cin>>op;
        if(op.compare("find")==0)
        {
            cin>>number;
            //hash_val = hash_value(number);
            find(ar, number, X);
            k++;
        }
        else if(op.compare("add")==0)
        {
            cin>>number>>name;
            add(ar, name, number);
        }
        else if(op.compare("del")==0)
        {
            cin>>number;
            del(ar, number);
        }
    }

    long long l = X.size();
    for(i=0;i<l;i++)
    cout<<X[i]<<"\n";
    
}