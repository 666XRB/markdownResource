#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, i, j;
    cin >> n >> m;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}