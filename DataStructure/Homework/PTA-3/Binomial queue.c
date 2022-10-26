#include <stdio.h>
#include <stdlib.h>
#define max 10
#define HeapMax 65535
#define Mask 1
typedef struct node *BinoNode;
typedef struct node *BinoTree;
struct node
{
    int data;
    BinoNode Sibling;
    BinoNode FirstChild;
};

struct heap
{
    BinoNode list[max];
    int size;
};
typedef struct heap *BinoHeap;

BinoHeap InitHeap()
{	
	BinoHeap H;
	H=(BinoHeap)malloc(sizeof(struct heap));
	H->size=0;
	for(int i=0;i<max;i++)
	{
	H->list[i]=NULL;
	}
	return H;
}

BinoNode combine(BinoNode tree1, BinoNode tree2)
{
	if(tree1->data>tree2->data)
	    return combine(tree2,tree1);
	tree2->Sibling=tree1->FirstChild;
	tree1->FirstChild=tree2;
	return tree1;
}

void InsertHeap(BinoHeap H,int c)
{
    BinoHeap TempHeap;
	BinoTree TempTree;
	BinoNode X;
	int i,tempsize,position;
	X=(BinoNode)malloc(sizeof(struct node));
	X->data=c;
	X->FirstChild=NULL;
	X->Sibling=NULL; 
	TempTree=X;
	position=0;
	tempsize=H->size;
	while(tempsize&Mask)
	{
		tempsize=tempsize>>1;  //-1
		position++;
	}
	for(i=0;i<position;i++)
	{
		
		TempTree=combine(TempTree,H->list[i]);	
		H->list[i]=NULL;
	}
	H->list[position]=TempTree;
	H->size++;
}

int out[10];
int cnt=0;

void traverse(BinoTree L)
{
    if(L==NULL)
		return;
	printf("%d  ",L->data);
    traverse(L->Sibling);
	traverse(L->FirstChild);
	
}

void print(BinoTree L)
{

    if(L==NULL)
		return;
    else
    {
        
        out[cnt]=L->data;
        cnt++;
        // printf("%d  ",L->data);
        // printf("**%d**",cnt);
        print(L->Sibling);
	    print(L->FirstChild);
    }
}

int main()
{
    int x,a,k;
    BinoHeap heap;
    heap=InitHeap();
    while(scanf("%d",&a))
    {
        char temp=getchar();
        if(temp!='\n')
        {
            x=a;
            InsertHeap(heap,x);
        }
        else
        {
            k=a;
            break;
        }
    }
    BinoTree T=heap->list[k];
    if(T==NULL)
        printf("0\n");
    else 
    {
        print(T);
        for(int i=0;i<cnt-1;++i)
        {
            for(int j=i+1;j<cnt;j++)
            {
                if(out[i]>out[j])
                {
                    int temp;
                    temp=out[j];
                    out[j]=out[i];
                    out[i]=temp;
                }
            }
        }
        for(int i=0;i<cnt;i++)
            printf("%d,",out[i]);
    }  
    printf("\n");
}