#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
void myprint(int a)
{
	cout << a << " ";
}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int> v1(v.begin(), v.end());
	//��v[begin(), end())�����е�Ԫ�ؿ���������
	//����ҿ�
	for_each(v1.begin(), v1.end(), myprint);

	cout << endl;
	vector<int> v3(10, 1);
	for_each(v3.begin(), v3.end(), myprint);

	cout << endl;
	cout << "�������캯��" << endl;

	vector<int> v4(v3);
	for_each(v4.begin(), v4.end(), myprint);




	return 0;
}