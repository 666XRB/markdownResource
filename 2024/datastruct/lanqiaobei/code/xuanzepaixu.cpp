#include <iostream>
using namespace std;

void sort(int a[],int length)
{
    int i,j,k;
    for ( i = 0; i < length-1; i++)
    {
        k=i;
        for ( j = i+1; j < length; j++)
        {
            if(a[j]<a[k])
            {
                k=j;
            }
        }
        if(i!=k)
        {
            swap(a[i],a[k]);
        }
        
    }
    

}
int main()
{
  // 请在此输入您的代码
  int n;
  cin>>n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    /* code */
    cin>>a[i];
  }
  sort(a,n);
    for (int i = 0; i < n; i++)
  {
    /* code */
    cout<<a[i]<<" ";
  }

  
  
  
  return 0;
}

