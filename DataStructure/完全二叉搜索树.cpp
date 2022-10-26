#include<cstdio>
#include<stack>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 30
int T[MAX];
int A[MAX];


int GetLeftLength(int n);
void solve(int ALeft,int ARight,int TRoot)//功能：从输入序列A中选出正确的数字填到T[TRoot]中
{   //初始调用为(0,N-1,0) ALeft是排序后输入序列A 当前段最左 TRoot是树数组的根节点下标
    int n=ARight-ALeft+1;//段内总元素数量
    if(n==0)
    {
        return;
    }
    int L=GetLeftLength(n);//计算n个结点的树其左子树有多少个结点
    T[TRoot]=A[ALeft+L];
    int LeftTRoot=TRoot*2+1;
    int RightTRoot=LeftTRoot+1;
    solve(ALeft,ALeft+L-1,LeftTRoot);
    solve(ALeft+L+1,ARight,RightTRoot);
}

