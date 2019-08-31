#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

const long long prime = 1000000007;
const long long multiplier = 263;


struct node
{
    long long number;
    string name;
    struct node* next;
};

long long hash_value(string str, long long m)
{
    //cout<<"hello1";
    long long hash_val = 0;
    //cout<<"hello2";
    long long i;
    long long l = str.length();
    for(int z=l-1;z>=0;z--)
    hash_val = (hash_val * multiplier + str[z]) % prime;
    hash_val = hash_val % m;
    //cout<<hash_val;
    return(hash_val);
}

void find(node ar[], string name, long long m, vector<string> &X)
{
    long long hash_val = hash_value(name, m);
    struct node* current = ar[hash_val].next;
    bool flag = false;
    //string str;
    while(current!=NULL)
    {
        if(current->name.compare(name)==0)
        {
            flag = true;
            //str = current->name;  
            break;          
        }
        current = current->next;
    }

    if(flag==true)
    {
        X.push_back("yes");
        X.push_back("\n");
    }

    else
    {
        X.push_back("no");
        X.push_back("\n");
    }
}

void check(long long x, node ar[], vector<string> &X)
{
    struct node* track = ar[x].next;
    while(track!=NULL)
    {
        //cout<<"Hello1";
        X.push_back(track->name);
        X.push_back(" ");
        track = track->next;
    }
    //cout<<"Hello2";
    X.push_back("\n");

}

void add(node ar[], string name, long long m)
{
    long long hash_val = hash_value(name, m);
    struct node* arr = new node();
    arr = &ar[hash_val];
    struct node* current = ar[hash_val].next;
    while(current!=NULL)
    {
        //cout<<"No na?";
        if(current->name.compare(name)==0)
        return;
        current = current->next;
    }

    struct node* u = new node();
    u->name = name;
    u->next = arr->next;
    arr->next = u;
}

void del(node ar[], string name, long long m)
{
    long long hash_val = hash_value(name, m);
    struct node* track = &ar[hash_val];
    struct node* current = ar[hash_val].next;
    while(current!=NULL)
    {
        if(current->name.compare(name)==0)
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
    //cout<<"hello1";
    long long n, m, i;
    vector<string> X;
    cin>>m;
    node ar[m];
    //cout<<"hello3";
    for(i=0;i<m;i++)
    {
        ar[i].number = i;
        ar[i].next = NULL;
        //cout<<ar[i].next<<" \n";
    }
    cin>>n;
    string op, name;
;

    for(i=0;i<n;i++)
    {
        cin>>op;
        if(op.compare("find")==0)
        {
            cin>>name;
            //hash_val = hash_value(number);
            find(ar, name, m, X);
            
        }
        else if(op.compare("add")==0)
        {
            cin>>name;
            add(ar, name, m);
        }
        else if(op.compare("del")==0)
        {
            cin>>name;
            del(ar, name, m);
        }
        else if(op.compare("check")==0)
        {
            long long e;
            cin>>e;
            check(e, ar, X); 
            //cout<<"Hello3";           
        }
    }

    long long l = X.size();
    for(i=0;i<l;i++)
    cout<<X[i];
    
}
