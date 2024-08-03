#include <iostream>
using namespace std;
void sort(int a[], int length) {
    for (int i = 1; i < length; i++) {
        int key = a[i];
        int j = i - 1;
        
        // 找到插入位置并移动元素
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
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