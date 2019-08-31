#include <iostream>
using namespace std;

void siftdown(long long store[][2], long long n, long long i)
{   
    long long index;
    if(2*i+2<=n-1)
    {
        if(store[2*i+1][1]>store[2*i+2][1])
        index = 2*i+2;
        else if(store[2*i+1][1]<store[2*i+2][1])
        index = 2*i+1;
        else
        {
            if(store[2*i+1][0]>store[2*i+2][0])
            index = 2*i + 2;
            else
            index = 2*i + 1;        
        }
        
        if(store[i][1]>store[index][1])
        {
            long long temp = store[i][0];
            store[i][0] = store[index][0];
            store[index][0] = temp;

            temp = store[i][1];
            store[i][1] = store[index][1];
            store[index][1] = temp;

            siftdown(store, n, index);
        }
        else if(store[i][1]==store[index][1])
        {
            if(store[i][0]>store[index][0])
            {
                long long temp = store[i][0];
                store[i][0] = store[index][0];
                store[index][0] = temp;

                temp = store[i][1];
                store[i][1] = store[index][1];
                store[index][1] = temp;

               siftdown(store, n, index);
            }
        }

    }
    if((2*i+1)==n-1)
    {
        if(store[i][1]>store[2*i+1][1])
        {
            long long temp = store[i][0];
            store[i][0] = store[2*i+1][0];
            store[2*i+1][0] = temp;

            temp = store[i][1];
            store[i][1] = store[2*i+1][1];
            store[2*i+1][1] = temp;

        }

        else if(store[i][1]==store[2*i+1][1])
        {
            if(store[i][0]>store[2*i+1][0])
            {
                long long temp = store[i][0];
                store[i][0] = store[2*i+1][0];
                store[2*i+1][0] = temp;

                temp = store[i][1];
                store[i][1] = store[2*i+1][1];
                store[2*i+1][1] = temp;
            }
        }
    }
    return;
}

int main(void)
{
    long long n, m, i;
    cin>>n>>m;
    if(n==0 || m==0)
    return 0;
    long long ar[m];
    long long store[n][2];
    for(i=0;i<m;i++)
    cin>>ar[i];
    for(i=0;i<n;i++)
    {
        store[i][0] = i;
        store[i][1] = 0;
    }

    i = 0;
    while(i<m)
    {
        if(n>1)
        {
            cout<<store[0][0]<<" "<<store[0][1]<<"\n";
            store[0][1] += ar[i];
            siftdown(store, n, 0);
            i++;
        }
        else
        {
            cout<<store[0][0]<<" "<<store[0][1]<<"\n";
            store[0][1] += ar[i];
            i++;
        }
        
    }
 
}
    