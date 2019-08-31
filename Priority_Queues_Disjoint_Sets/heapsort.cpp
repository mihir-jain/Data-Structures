#include <iostream>
#include <vector>
using namespace std;

void siftdown(long long ar[], long long i, long long n, vector<long long> &store)
{
    long long index, temp;

    if((2*i+2)<=(n-1))   
    {
        if(ar[2*i+1]<ar[2*i+2])
        index = 2*i+1;
        else
        index = 2*i+2;
        if(ar[i]>ar[index])
        {
            store.push_back(i);
            store.push_back(index);
            temp = ar[i];
            ar[i] = ar[index];
            ar[index] = temp;
            siftdown(ar, 2*i+1, n, store);
            siftdown(ar, 2*i+2, n, store);
        }
    }
        
    if(2*i+1<=(n-1))
    {
        if(ar[i]>ar[2*i+1])
        {
            store.push_back(i);
            store.push_back(2*i+1);
            temp = ar[i];
            ar[i] = ar[2*i+1];
            ar[2*i+1] = temp;

        }
    }
    
    return;
}
   

int main(void)
{
    long long n, i;
    cin>>n;
    long long ar[n];
    for(i=0;i<n;i++)
    cin>>ar[i];
    vector<long long> store;

    //long long swap[4*n][2];
    for(i=n/2;i>=0;i--)
    {   
        siftdown(ar, i, n, store);
    }

    //for(i=0;i<n;i++)
    //cout<<ar[i]<<" ";

    long long l = store.size();
    cout<<l/2<<"\n";
    for(i=0;i<l;i+=2)
    cout<<store[i]<<" "<<store[i+1]<<"\n";
    return 0;
}
