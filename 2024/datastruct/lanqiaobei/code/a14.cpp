#include <iostream>
using namespace std;
void sort(int a[],int b[], int n,int m) {
    for (int i = 1; i < n; i++)
    {
        // 10 6 4
        // 0 1 2 3 4 5 &6 &7 &8 &9

        // 0 1 2 3 
        int j=i-1;
        int key;
        if(i<m)
        {
            key=a[i];
        }
        else{
            key=b[(n-1)-i];
        }
        
        //寻找插入位置
        while (j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    
}
int main()
{
    int a,b;
    cin>>a>>b;
    int a1[a];
    int a2[a-b];
    for (int i = 0; i < b; i++)
    {
        /* code */
        cin>>a1[i];
    }
    for (int j = 0; j < (a-b); j++)
    {
        cin>>a2[j];
    }
    for (int i = 0; i < b; i++)
    {
        /* code */
        cout<<a1[i];
    }
    cout<<endl;
    for (int j = 0; j < (a-b); j++)
    {
        cout<<a2[j];
    }
    sort(a1,a2,a,b);
    cout<<"sort后的数组a"<<endl;
        for (int i = 0; i < a; i++)
    {
        /* code */
        cout<<a1[i]<<" ";
    }



    
    
    
    


    return 0;
}