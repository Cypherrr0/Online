

#ifndef _HEAP_H
#define _HEAP_H

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//  ************* 输出堆 *************
void output_impl(int n, bool left, string const& indent, vector<int>& vec)
{
	if (n * 2 + 1 < (int)vec.size())
	{
		output_impl(n * 2 + 1, false, indent + (left ? "|     " : "      "), vec);
	}
	cout << indent;
	cout << (left ? '\\' : '/');
	cout << "-----";
	cout << vec[n] << endl;
	if (n * 2 < (int)vec.size())
	{
		output_impl(n * 2, true, indent + (left ? "      " : "|     "), vec);
	}
}
void output(vector<int>& v)
{
	if (v.size() <= 1)
		return;
	if (v.size() >= 4)
	{
		output_impl(3, false, "", v);
	}
	cout << v[1] << endl;
	if (v.size() >= 3)
	{
		output_impl(2, true, "", v);
	}
}
//  ***************************************
//指定最小堆
template<typename T>
class Less
{
public:
	bool operator()(const T& a, const T& b)const
	{
		return a < b;
	}
};

//指定最大堆
template<typename T>
class Greater
{
public:
	bool operator()(const T& a, const T& b)const
	{
		return a > b;
	}
};

//堆，默认最小堆less排序
template<class T, class Compare = Less<T> >
class Heap
{
private:
	int lastIndex;		//数组下标，从1开始计数
	Compare cmp;		//排序类，判断最大堆还是最小堆
	vector<T> vec;		//存储数组,vec[1]是堆顶
public:
	Heap() :lastIndex(1)
	{
		vec.push_back(T());   //预先分配空间,因为要用下标1作为堆顶
	}
	~Heap() {};
	//堆插入元素
	void push(T value)
	{
		vec.push_back(value);		//先插入尾部
		int curIndex = lastIndex;	//获取当前下标
		//插入元素上浮
		while (curIndex / 2)
		{
			if (cmp(vec[curIndex], vec[curIndex / 2]))  //cmp类来比较确定是最小堆还是最大堆
			{
				//需要上浮，说明插入元素比父节点更大（更小）
				swap(vec[curIndex], vec[curIndex / 2]);
				curIndex /= 2;
			}
			else
				break;

		}
		lastIndex++;
	}
	//获取堆中所有元素
	int size() { return lastIndex - 1; };

	//获取堆顶元素
	T top() { return empty() ? T() : vec[1]; };

	//判断是否为空堆
	bool empty() { return vec.size() <= 1; }
	//删除堆顶元素
	T pop()
	{
		if (lastIndex <= 1)
			return T();
		int curIndex = 1;
		T res = vec[1];
		vec[1] = vec[lastIndex - 1];	//为保证完全二叉树结构，把最后一个元素移到堆顶，然后执行下沉操作
		vec.pop_back();
		lastIndex--;
		//下沉操作
		while (curIndex * 2 <= lastIndex - 1)   //不要越界
		{
			int child = curIndex * 2;
			if (child + 1 <= lastIndex - 1 && cmp(vec[child + 1], vec[child]))  //找子节点合适值替换，比如最小堆就找两个子节点中最小的那个和父节点比较
			{
				child++;	//右子节点更小（更大）
			}
			if (cmp(vec[child], vec[curIndex]))  //子节点是否比父节点更大（更小）
			{
				swap(vec[child], vec[curIndex]);
			}
			else
				break;
			curIndex = child;
		}
		return res;	//返回删除堆顶元素
	}
	//打印堆元素
	void printHeap()
	{
		output(vec);
	}
};



int main()
{
	Heap<int, Greater<int>> hp;   //默认为最小堆，现在Greater<int>设为最大堆
	hp.push(3);
	hp.push(2);
	hp.push(1);
	hp.push(10);
	hp.push(20);
	hp.push(6);
	hp.printHeap();
	cout << "--------------pop()---------------" << endl << endl;
	hp.pop();
	hp.printHeap();
	cout << "--------------pop()---------------" << endl << endl;
	hp.pop();
	hp.printHeap();
	cout << "--------------top()---------------" << endl;
	cout << hp.top() << endl;
	cout << "--------------pop()---------------" << endl << endl;
	hp.pop();
	hp.printHeap();
	cout << "--------------pop()---------------" << endl << endl;
	hp.pop();
	hp.printHeap();


}


#endif // !MINHEAP_H


