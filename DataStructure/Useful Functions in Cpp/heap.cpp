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
    make_heap(num.begin(),num.end(),greater<int>());//����С��
    cout << "ԭʼ����С��" << endl;
    printnum(num);
    cout << endl << "pop����С��"<< endl;
    pop_heap(num.begin(),num.end(),greater<int>());//��һ��Ԫ�غ����һ��������Ȼ������һ�����������ٽ���

    
    printnum(num);
    cout << num.back() << endl;//������һ��Ԫ��
}