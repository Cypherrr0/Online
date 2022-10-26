#include <bits/stdc++.h>
using namespace std;

const int N = 5010, M = 2e5+10;

int n, m;
int f[N];
struct Edge
{
	int a, b, w;
	bool operator<(const Edge& W) const
    {
		return w < W.w;//内嵌比较函数
	}
}edges[M];

int find(int x)//找根结点
{
	if(x != f[x])
        f[x] = find(f[x]);
	return f[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
    {
		int a, b, w;
        cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	sort(edges, edges + m);
	
	int res = 0, cnt = 0;   //res存储最小生成树所有边权和，cnt存当前边数
	for(int i = 1; i <= n; i++) 
        f[i] = i;	//并查集初始化
	for(int i = 1; i <= m; i++)
    {
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);
		if(a != b)
        {
			f[a] = b;
			res += w;
			cnt++;
		}
		if(cnt == n-1) 
            break;		//如果到了n-1，后面再连边也没意义了
	}
	
	if(cnt < n-1) 
        puts("impossible");	//最小生成树不存在
	else 
        printf("%d\n", res);
	
	return 0;
}
//https://blog.csdn.net/u012011079/article/details/122892534
//https://blog.csdn.net/Li5566123/article/details/123611568
//https://www.luogu.com.cn/problem/P3366