#include <bits/stdc++.h>

using namespace std;

struct PolyNode
{
    int Coef;//系数
    int Expon;//指数
    PolyNode *Next;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

int Compare(int num1,int num2)
{
    if(num1>num2)
        return 1;
    else if(num1<num2 )
        return -1;
    else
        return 0;
}

void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;

    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->Coef=c;
    P->Expon=e;
    P->Next=NULL;
    (*pRear)->Next=P;
    *pRear=P;
}

void Print(Polynomial p)
{
    Polynomial TEMP;
    TEMP=p->Next;
    if(p->Next==NULL)
        cout << "EMPTY!" << endl;
    else
    {
        while(TEMP!=NULL)
        {
            cout << TEMP->Coef << " " << TEMP->Expon << " ";
            TEMP=TEMP->Next;
        }
        cout << endl;
    }
}
Polynomial Create()
{
    Polynomial p1,p2;
    p1=(Polynomial)malloc(sizeof(struct PolyNode));
    p1->Next=NULL;
    Polynomial temp;
    temp=p1;
    cout << "START ENTERING INPUT 00 TO END" << endl;
    do
    {
        p2=(Polynomial)malloc(sizeof(struct PolyNode));
        cin >> p2->Coef >>p2->Expon;
        if(p2->Coef==0&&p2->Expon==0)
            break;
        p2->Next=temp->Next;
        temp->Next=p2;
        temp=p2;
    }while(1);

    return p1;
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;//指向结果多项式头尾
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;
    while(P1&&P2)
    {
        switch(Compare(P1->Expon,P2->Expon))
        {
            case 1:
                cout << "ok1" << endl;
                Attach(P1->Coef,P1->Expon,&rear);
                P1=P1->Next;
                break;
            case -1:
                cout << "ok-1" << endl;
                Attach(P2->Coef,P2->Expon,&rear);
                P2=P2->Next;
                break;
            case 0:
                cout << "ok0" << endl;
                sum=P1->Coef+P2->Coef;
                if(sum)
                    Attach(sum,P1->Expon,&rear);
                P1=P1->Next;
                P2=P2->Next;
                break;
        }
        
    }
    for(;P1;P1=P1->Next)
        Attach(P1->Coef,P1->Expon,&rear);
    for(;P2;P2=P2->Next)
        Attach(P2->Coef,P2->Expon,&rear);
    rear->Next=NULL;
    temp=front;
    front=front->Next;
    free(temp);
    return front;
}

int main(int argc, char *argv[])
{
    Polynomial Head1;
    Head1=Create();
    Print(Head1);

    Polynomial Head2;
    Head2=Create();
    Print(Head2);

    Polynomial Final;
    Final=PolyAdd(Head1,Head2);
    Final=Final->Next;
    Print(Final);
}
// 3 5 4 4 -1 3 2 1 -1 0 0 0
// 2 4 1 3 -7 2 1 1 0 0

//1 2 3 3 5 5 7 6 8 7 0 0
//2 3 3 5 4 7 0 0