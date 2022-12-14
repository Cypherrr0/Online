#include <stdio.h>
#include <stdbool.h>
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    int Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}

void DeleteQ( Queue Q )
{
    Position FrontCell; 
    Queue FrontElem;
    
    if  ( IsEmpty(Q) ) {
        printf("队列空");
        return 0;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else                     
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}