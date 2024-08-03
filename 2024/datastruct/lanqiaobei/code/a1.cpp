#include <iostream>
using namespace std;
#include <string>

#include<cstring>
int main()
{
    string str;
    getline(cin,str);
    bool flag=false;
    cout<<str.length()<<endl;
    // cout<<str.size()<<endl;
    for(int i=0;i<str.length();i++)
    {
        for(int j=i+1;j<str.length()-i;j++)
        {
            if(str[i]==str[j])
            {
                flag=true;
            }
        }
    }
    if(flag)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }





    return 0;
}