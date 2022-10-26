//Queue.h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//声明结构体类型
struct BinaryTreeNode;

//改变元素类型为该结构体类型的指针

typedef struct BinaryTreeNode* QDatatype;

//定义单链表结点
typedef struct QueueNode
{
	QDatatype data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;