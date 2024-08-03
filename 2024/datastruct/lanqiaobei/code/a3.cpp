#include <iostream>
using namespace std;
#include <string>
int main()
{
  // 请在此输入您的代码
  string s1;
  getline(cin,s1);


  int s2[200]={0};

  for(int i=0;i<s1.length();i++)
  {
    s2[s1[i]]++;
  }
int count=0;
  for(int i=0;i<200;i++)
  {
    if(s2[i]!=0)
    {
      count+=2;
    }
  }


  if(s1.length()>=count)
  {
  for(int i=0;i<200;i++)
  {
    if(s2[i]!=0)
    {
      cout<<char(i)<<s2[i];
    }
  }
    cout<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }


  
  return 0;
}

