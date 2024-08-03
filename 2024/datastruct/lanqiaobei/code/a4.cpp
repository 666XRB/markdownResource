#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string str;
  getline(cin,str);
  // for(int i=str.length();i>=0;i--)
  // {
  //   //  cout<<str[i];
  // }
  // cout<<endl;
  for(int i=0,j=str.length()-1;i<=j;i++,j--)
  {
    char c;
    c=str[i];
    str[i]=str[j];
    str[j]=c;
  }

  cout<<str;
  return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//   // 请在此输入您的代码
//   string str;
//   getline(cin,str);
//   for(int i=str.length()-1;i>=0;i--)
//   {
//      cout<<str[i];
//   }
//   cout<<endl;
//   return 0;
// }