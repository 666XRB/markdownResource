#include <iostream>

//����ͷ�ļ�
#include <vector>
#include <algorithm>
//for_each��Ҫ��
using namespace std;

void myprint(int v)
{
	cout << v << " ";
}


//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
//v.begin()���ص����������������ָ�������е�һ������
//v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
//vector<int>::iterator �õ�vector<int>���������ĵ���������
int main()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator start = v.begin();
	vector<int>::iterator end = v.end();

	cout << "��һ�ֱ����ķ�ʽ��ͳ��forѭ��" << endl;
	//������[]����
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]<<" ";
	}
	cout << endl;

	for (start; start < end; start++)
	{
		cout << *start << " ";
	}
	cout << endl;
	
	//cout << "�ڶ��ֱ����ķ�ʽ" << endl;
	//while (start!=end)
	//{
	//	cout << *start<<" ";
	//	start++;
	//}
	cout << "�����ֱ����ķ�ʽ" << endl;

	for_each(v.begin(),v.end(), myprint);

	for_each(start, end, myprint);


	return 0;
}
