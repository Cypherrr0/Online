#include <bits/stdc++.h>
using namespace std;

#define MaxSize 64
typedef struct TNode *HuffmanTree;
struct TNode {
	int Weight;
	HuffmanTree Left;
	HuffmanTree Right;
};//哈夫曼树标准定义

typedef struct HeapNode *MinHeap;
struct HeapNode {
	HuffmanTree Elements[MaxSize];
	int Size;
};
char ch[MaxSize];//输入的字符
int N,w[MaxSize],TotalCodes;//编码中含字符个数，以及频率 最优编码长度

MinHeap CreateHeap();//创建最小堆
HuffmanTree CreatHuffman();//创建哈夫曼结点
void Insert(MinHeap H,HuffmanTree X);//插入元素
HuffmanTree DeleteMin(MinHeap H);//删除最小堆元素
HuffmanTree BuildHuffman(MinHeap H);//创建哈夫曼
int WPL(HuffmanTree root, int depth);//算	WPL的权值
//带权路径长度(WPL):设二叉树有n个叶子结点，每个叶子结点
//带有权值wk，从根结点到每个叶子结点的长度为lk，则每个
//叶子结点的带权路径长度之和 wk*lk

//最优二叉树或哈夫曼树：WPL最小的二叉树
int Judge();//判断

MinHeap CreateHeap()//最小堆初始化
{
	MinHeap H;
	H = (MinHeap)malloc(sizeof(struct HeapNode));
	H->Size = 0;
	H->Elements[0] = (HuffmanTree)malloc(sizeof(struct TNode));
	H->Elements[0]->Weight = -1;
	H->Elements[0]->Left = H->Elements[0]->Right = NULL;
	return H;
}

HuffmanTree CreatHuffman()//创建哈夫曼结点
{
	HuffmanTree  T;
	T = (HuffmanTree)malloc(sizeof(struct TNode));
	T->Left = T->Right = NULL;
	T->Weight = 0;
	return T;
}

void Insert(MinHeap H,HuffmanTree X)//最小堆插入元素
{
	int i = ++H->Size;
	while(H->Elements[i/2]->Weight > X->Weight)
	{
		H->Elements[i] = H->Elements[i/2];
		i/=2;
	}
	H->Elements[i] = X;
}

HuffmanTree DeleteMin(MinHeap H)//最小堆删除元素
{
	HuffmanTree MinTtem,temp;
	int Parent,Child;
	MinTtem = H->Elements[1];
	temp = H->Elements[H->Size--];
	for(Parent = 1;Parent *2<=H->Size;Parent = Child) {
		Child = Parent * 2;
		if((Child != H->Size) && (H->Elements[Child]->Weight > H->Elements[Child+1]->Weight))
			Child ++;
		if(temp->Weight <= H->Elements[Child]->Weight) 
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MinTtem;
}

HuffmanTree BuildHuffman(MinHeap H)//构建完整哈夫曼树
{
	HuffmanTree T;
	int num = H->Size;
	for(int i=1;i<num;i++)
	{
		T = CreatHuffman();
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H,T);
	}
	T = DeleteMin(H);
	return T;
}

int WPL(HuffmanTree root,int depth)//计算WPL
{
	if((root->Left == NULL ) && (root->Right == NULL))
		return depth*root->Weight;
	else
		return WPL(root->Left,depth+1) + WPL(root->Right,depth+1);
}

int Judge()
{
	HuffmanTree T,p;
	char chl,*codes;
	codes = (char *)malloc(sizeof(char)*MaxSize);
	int length = 0,flag=1,wgh,j;
	T = CreatHuffman();
	
	for(int i=0;i<N;i++)
	{
		scanf("\n%c %s",&chl,codes);
		if(strlen(codes)>=N)
			flag = 0;
		else
        {
			for(j = 0;chl !=ch[j];j++);
			wgh = w[j];
			p = T;
			for(j=0;j<strlen(codes);j++)
			{
				if(codes[j]=='0')
                {
					if(!p->Left)
						p->Left = CreatHuffman();

					p = p->Left;
					
				}
                else if(codes[j] == '1')
                {
					if(!p->Right)
						p->Right = CreatHuffman();
					
                    p = p->Right;
				}
				if(p->Weight) flag = 0;
			}
			if(p->Left || p->Right )
				flag = 0;
			else
				p->Weight = wgh;
		}
		length += strlen(codes)*p->Weight;
	}
	if(length!=TotalCodes)
		flag = 0;
	return flag;
}

int main()
{
	/*
	以最小堆构建哈夫曼树，得到最优编码长度
	根据学生输入建造树，判断是否为最优编码。判断根据：
			最优秀编码长度为一，检查是否与第一步所得的最优编码长度一致
			是否存在二义性，即是否具有前缀码
	*/
	int M;
	HuffmanTree tmp,ROOT;
	scanf("%d",&N);
	MinHeap H = CreateHeap();
	//根据输入的字符已经其频率，一个个插入构建最小堆
	for(int i=0;i<N;i++)
	{
		getchar();
		scanf("%c %d",&ch[i],&w[i]);
		tmp = CreatHuffman();
		tmp->Weight = w[i];
		Insert(H,tmp);
	}
	ROOT = BuildHuffman(H);
	TotalCodes = WPL(ROOT, 0);
	scanf("%d",&M);
	for(int i =0;i<M;i++)
	{
		if(Judge())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
// https://blog.csdn.net/m0_37149062/article/details/105641639