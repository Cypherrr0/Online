// 这是一个调试测试文件，您可以直接运行检测配置是否生效
// 若配置任然无法调试，请查阅README_inProject.md

#include <bits/stdc++.h>

using namespace std;
int main()
{
    
    int sum=0;
    int N=1000;
    for(int i=0;i<N;i++)//执行N次
    {
        for(int j=0;j<i;j++)//执行
        {
            sum++;
        }
    }
    cout << sum << endl;
}