#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    long long n, i, ele;
    cin>>n;
    string str;
    vector<long long> mainstack;
    vector<long long> auxstack;
    vector<long long> output;
    long long max = -INT32_MAX;
    for(i=0;i<n;i++)
    {
        cin>>str;
        if(str.compare("push")==0)
        cin>>ele;
        //cout<<"String:"<<str<<" "<<" Ele:"<<ele<<"\n";
        if(str.compare("push")==0)
        {
            mainstack.push_back(ele);
            if(ele>max)
            {
                auxstack.push_back(ele);
                max = ele;
            }
            else
            auxstack.push_back(max);           
        }
        else if(str.compare("pop")==0)
        {
            mainstack.pop_back();
            auxstack.pop_back();
            max = auxstack.back();
        }
        else if(str.compare("max")==0)
        {
            output.push_back(auxstack.back());
        }
    }

    long long l = output.size();
    for(i=0;i<l;i++)
    cout<<output[i]<<"\n";
}
