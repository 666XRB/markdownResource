#include <iostream>

//包含头文件
#include <vector>
#include <algorithm>
//for_each需要用
using namespace std;

void myprint(int v)
{
	cout << v << " ";
}


//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
int main()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator start = v.begin();
	vector<int>::iterator end = v.end();

	cout << "第一种遍历的方式传统的for循环" << endl;
	//重载了[]符号
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
	
	//cout << "第二种遍历的方式" << endl;
	//while (start!=end)
	//{
	//	cout << *start<<" ";
	//	start++;
	//}
	cout << "第三种遍历的方式" << endl;

	for_each(v.begin(),v.end(), myprint);

	for_each(start, end, myprint);


	return 0;
}
