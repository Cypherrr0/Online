#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct list *linklist;
struct list
{
    int size;
    int data;
    linklist next;
};

struct heap
{
    linklist bilist[10];
    int heapsize;
};
typedef struct heap *biheap;

biheap InitHeap()
{
    biheap H=(biheap) malloc(sizeof(struct heap));
    H->heapsize=0;
    for(int i=0; i<10; i++)
    {
        H->bilist[i]=NULL;
    }
    return H;
}

void sort(int *array,int length)
{
    for(int i=0;i<length-1;i++)
    {
        int flag=1;
        for(int j=0;j<length-1-i;j++)
        {
            if(array[j]>array[j-1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                flag=0;
            }
        }
        if(flag==1)
            break;
    }
}

linklist Insertlist(linklist list,int x)
{
    linklist temp=(linklist)malloc(sizeof(struct list));
    temp->data=x;
    temp->size=1;
    temp->next=NULL;
    if(list==NULL)
    {
        linklist head=temp;
        return head;
    }
    else
    {
        linklist rear=list;
        while(rear->next!=NULL)
        {
            rear=rear->next;
        }
        rear->next=temp;
        temp->size=list->size+1;
        return list;
    }
}

void InsertHeap(biheap H,int *array,int length)
{
    int tempsize,position=0;
    for(int i=0;i<length;i++)
    {
        if(H->bilist[position]!=NULL)
            tempsize=H->bilist[position]->size;
        else
            tempsize=-1;
        int sizeheap=pow(2,position);
        if(tempsize==sizeheap)
        {
            int nextposition=position+1
            H->bilist[nextposition]
        }
    }
}

int main(int argc, char *argv[])
{
    int a,k;
    int array[20],j=-1;
    biheap heap=InitHeap();
    while(scanf("%d",&a))
    {
        char temp=getchar();
        if(temp=='\n')
        {
            j++;
            array[j]=a;
        }
        else
        {
            k=a;
            break;
        }
    }
    sort(array,j);
    InsertHeap(heap,array,j);
}