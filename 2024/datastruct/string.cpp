#include <iostream>
using namespace std;
#include <string>
int main()
{
    string str;


    char temp[] = "aaaasdsadasda";
    char* s = temp;
    char* s1 = "aaaasdsadasda2µÄÈö";





    string str1(s);



    string str2(10,'s');
    string str3(str2);
    cout<<s<<endl;
    cout<<s1<<endl;
    cout<<str<<endl;
     cout<<str1<<endl;
      cout<<str2<<endl;
       cout<<str3<<endl;




    return 0;
}