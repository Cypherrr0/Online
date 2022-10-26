#include <stdio.h>
//构建最大堆

typedef struct HeapStruct *MaxHeap;
struct HeapStruct
{
    int *array;
    int size;
    int capacity;
};
//创建最大堆
MaxHeap CreateMaxHeap(int capacity)
{
    MaxHeap heap=(MaxHeap)malloc(sizeof(struct HeapStruct));
    heap->array=(int *)malloc(capacity*sizeof(int));
    //heap->array=malloc((capacity+1)*sizeof(int)); 因为从1开始存放
    heap->size=0;
    heap->capacity=capacity;
    heap->array[0]=100000;//哨兵 设全局最大值
    return heap;
}
//插入堆
void InsertHeap(MaxHeap heap,int value)
{
    if(heap->size==heap->capacity)
    {
        printf("堆已满\n");
        return;
    }
    heap->size++;
    int i=heap->size;//i指向插入后堆的最后一个元素
    for(;heap->array[i/2]<value;i/=2)
    {
        heap->array[i]=heap->array[i/2];
    }
    heap->array[i]=value;
}
//删除堆
int DeleteHeap(MaxHeap heap)
{
    if(heap->size==0)
    {
        printf("堆已空\n");
        return;
    }
    int Parent, Child;
    int MaxValue,temp;
    MaxValue=heap->array[1];//删除根节点，取出它的值
    temp=heap->array[heap->size--];//取出最后一个元素
    for(Parent=1;Parent*2<=heap->size;Parent=Child)
    {
        Child=Parent*2;
        if(Child<heap->size && heap->array[Child]<heap->array[Child+1])//一定有右儿子，左小于右
        {
            Child++;//把child指向左右子节点中较大的一个
        }
        if(temp>=heap->array[Child])//判断temp和左右儿子最大的那个还要大
        {
            break;//不需要调整
        }
        else
        {
            heap->array[Parent]=heap->array[Child];
        }
    }
    heap->array[Parent]=temp;
    return MaxValue;
}
//建立最大堆
void BuildMaxHeap(MaxHeap heap)
{
    int i;
    for(i=heap->size/2;i>0;i--)
    {
        MaxHeapify(heap,i);
    }
}
