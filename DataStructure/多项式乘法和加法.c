#include <stdio.h>

struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};
typedef struct PolyNode *Polynomial;

Polynomial ReadPoly();
Polynomial Mult(Polynomial P1,Polynomial P2);
Polynomial Add(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial P);
void Attach(int c,int e,Polynomial *pRear);

Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int c,e,N;//c-coef,e-expon,N-total
    scanf("%d",&N);
    P=(Polynomial)malloc(sizeof(struct PolyNode));//创建列表空结点
    P->link=NULL;
    Rear=P;
    while(N--)
    {
        scanf("%d%d",&c,&e);
        Attach(c,e,&Rear);//尾插
    }
    t=P;
    P=P->link;
    free(t);//删除头结点
    return P;
}

void Attach(int c,int e,Polynomial *pRear)//*pRear是指针的指针
{
    Polynomial P;//尾插新节点P
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    (*pRear)->link=P;//使pRear指向的旧尾连接新尾P
    *pRear=P;//使pRear更新 指向新节点（尾）
}

Polynomial Mult(Polynomial P1,Polynomial P2)
{
    Polynomial P,Rear,t1,t2,t;
    int c,e;
    if(!P1 || !P2)
    {
        return NULL;
    }
    t1=P1;
    t2=P2;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear=P;
    while(t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;//用p1第一项乘p2每一项，得到P，初始链表，后续乘完往里放
    }
    t1=t1->link;
    while(t1)
    {
        t2=P2;
        Rear=P;
        while(t2)
        {
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while(Rear->link && Rear->link->expon>e)
            {
                Rear=Rear->link;//比较下一个结点的指数和准备插入的谁大，由此找到插入位置
            }
            if(Rear->link&&Rear->link->expon == e)//指数相等---合并
            {
                if(Rear->link->coef+c)//相加后不等于0
                {
                    Rear->link->coef+=c;
                }
                else//等于0，删掉
                {
                    t=Rear->link;
                    Rear->link=t->link;
                    free(t);
                }
            }
            else//指数比现在的小---后插
            {
                t=(Polynomial)malloc(sizeof(struct PolyNode));
                t->coef=c;
                t->expon=e;
                t->link=Rear->link;
                Rear->link=t;
                Rear=Rear->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    t2=P;
    P=P->link;
    free(t2);
    return P;
}

Polynomial Add(Polynomial P1,Polynomial P2)
{
    Polynomial t1,t2,P,Rear;
    t1=P1;
    t2=P2;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear=P;
    while(t1&&t2)
    {
        if(t1->expon == t2->expon)
        {

        }
        else if(t1->expon > t2->expon)
        {

        }
        else
        {

        }
    }
    while(t1)
    {

    }
    while(t2)
    {

    }
}

void PrintPoly(Polynomial P)
{
    int flag=0;
    if(!P)
    {
        printf("0 0\n");
        return 0;
    }
    while(P)
    {
        if(!flag)
        {
            flag=1;
        }
        else
        {
            printf(" ");
        }
        printf("%d %d",P->coef,P->expon);
        P=P->link;
    }
}

int main()
{
    Polynomial P1,P2,PP,PS;
    P1=ReadPoly;
    P2=ReadPoly;
    PP=Mult(P1,P2);
    PrintPoly(PP);
    PS=Add(P1,P2);
    PrintPoly(PS);
}