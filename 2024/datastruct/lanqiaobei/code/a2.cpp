#include <iostream>
using namespace std;
#include <string>
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    // cout<<s1<<endl;
    // cout<<s2<<endl;
    int count=0;
    for(int i=0;i<s1.length();i++)
    {
        for(int j=0;j<s2.length();j++)
        {
            if(s1[i]==s2[j])
            {
                count++;
            }
        }
    }
    if(count==s1.length())
    {
        cout<<"YES"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}