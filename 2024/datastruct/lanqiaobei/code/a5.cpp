#include <iostream>
using namespace std;
int main()
{
  int i;
  char arr[101],brr[101];
  int hash[150]={0};
  scanf("%s",arr);
  scanf("%s",brr);
  for(i=0;arr[i];i++)
  {
    hash[arr[i]]++;
  }
  for(i=0;brr[i];i++)
  {
    hash[brr[i]]--;
  }
  for(i=0;i<150;i++)
  {
    if(hash[i])
    {
      printf("%c",i);
      break;
    }
  }
  return 0;
}