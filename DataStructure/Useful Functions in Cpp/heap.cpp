#include <bits/stdc++.h>
using namespace std;

void printnum(vector<int>num)
{
    for(int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}


int main()
{
    int num_temp[8]={24,22,17,23,5,4,67,68};
    
    vector<int> num(num_temp,num_temp+8);
    make_heap(num.begin(),num.end(),greater<int>());//建最小堆
    cout << "原始的最小堆" << endl;
    printnum(num);
    cout << endl << "pop后最小堆"<< endl;
    pop_heap(num.begin(),num.end(),greater<int>());//第一个元素和最后一个互换，然后除最后一个以外所有再建堆

    
    printnum(num);
    cout << num.back() << endl;//输出最后一个元素
}