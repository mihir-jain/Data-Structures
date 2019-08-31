#include <iostream>
using namespace std;

int main(void)
{
    string str;
    cin>>str;
    int n = str.length();
    char ch[n][2];
    int i;
    int k = 0;
    int count = 0;
    bool flag = true;

    for(i=0;i<n;i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            ch[k][0] = str[i];
            ch[k][1] = i+1;
            k++;
        }
        else if(str[i]==')')
        {
            if(ch[k-1][0]=='(')
            k--;
            else
            {
                k--;
                cout<<i+1;
                flag = false;
                break;
            }
        }
        else if(str[i]==']')
        {
            if(ch[k-1][0]=='[')
            k--;
            else
            {
                k--;
                cout<<i+1;
                flag = false;
                break;
            }
        }
        else if(str[i]=='}')
        {
            if(ch[k-1][0]=='{')
            k--;
            else
            {
                k--;
                cout<<i+1;
                flag = false;
                break;
            }
        }

    }
    if(k>0 && flag == true) 
    cout<<(int)ch[0][1];
    else if(k==0 && flag == true)
    cout<<"Success";
    return 0;
}