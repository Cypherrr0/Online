#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MinElement -100000
#define MaxCapacity 10000
typedef struct HeapStruct *MinHeap;
struct HeapStruct
{
    int *array;
    int size;
    int capacity;
};

MinHeap CreateMinHeap(int capacity)
{
    MinHeap H=(MinHeap)malloc(sizeof(struct HeapStruct));
    H->array=(int *)malloc((capacity+1)*sizeof(int));
    H->size=0;
    H->capacity=capacity;
    H->array[0]=MinElement;
    return H;
}

bool IsFull(MinHeap H)
{
    return (H->capacity==H->size);
}

void Insert(MinHeap H, int x)
{
    int i;
    if(IsFull(H))
    {
        printf("FULL!!\n");
        return;
    }
    i=++H->size;//准备放进去的位置 i/2父节点
    for(;H->array[i/2]>x;i/=2)
        H->array[i]=H->array[i/2];//父节点的值往下走
    H->array[i]=x;

}

int DeleteMin(MinHeap H)
{
    int parent,child;
    int MinItem,LastItem;
    if(IsFull(H))
    {
        printf("EMPTY!!\n");
        return H->array[0];
    }

    MinItem=H->array[1];//取出最小值
    LastItem=H->array[H->size];//取出最后一个元素
    H->size--;
    //寻找最后一个元素该放的位置 并调整堆
    for(parent=1;parent*2<=H->size;parent=child)//判断条件是parent的左右儿子都在size范围内，即不空
    {
        child=parent*2;
        if((child!=H->size)&&(H->array[child]>H->array[child+1]))
            child++;//左右儿子都在，而且左儿子比右儿子大，选中右儿子
        if(LastItem<=H->array[child])
            break;
        else
            H->array[parent]=H->array[child];
    }
    H->array[parent]=LastItem;
    return MinItem;
}

int main(int argc, char **argv)
{
    int n,x;
    MinHeap H=CreateMinHeap(MaxCapacity);
    H->size=0;
    printf("ENTER N\n");
    scanf("%d",&n);
    printf("ENTER ITEM\n");
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        Insert(H,x);
    }

    printf("HEAP\n");
    for(int i=1;i<=H->size;i++)
        printf("%d ",H->array[i]);
    printf("\n");
    printf("DELETEMIN:\n");
    int MinItem=DeleteMin(H);
    printf("%d\n",MinItem);
    for(int i=1;i<=H->size;i++)
        printf("%d ",H->array[i]);
    printf("\n");

    printf("DELETEMIN:\n");
    MinItem=DeleteMin(H);
    printf("%d\n",MinItem);
    for(int i=1;i<=H->size;i++)
        printf("%d ",H->array[i]);
    printf("\n");

    printf("DELETEMIN:\n");
    MinItem=DeleteMin(H);
    printf("%d\n",MinItem);
    for(int i=1;i<=H->size;i++)
        printf("%d ",H->array[i]);
    printf("\n");
}
// 15
//  10 12 1 14 6 5 8 15 3 9 7 4 11 13 2

// https://blog.csdn.net/SteelBasalt/article/details/49455161