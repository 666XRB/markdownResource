#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int line;
    cin>>line;
for (int i = 0; i < line; i++)
{
    /* code */
    cin>>a[i];
}
int answer;
cin>>answer;
for (int i = 0; i < line; i++)
{
    /* code */
    for (int j = i+1; j < line-1; j++)
    {
        /* code */
        if(a[i]+a[j]==answer)
        {
                    cout<<i<<" "<<j<<endl;
                    break;
        }
    }
    
}





    return 0;
}