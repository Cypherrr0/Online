#include <bits/stdc++.h>
using namespace std;

struct PolyNode
{
    int Coef;//系数
    int Expon;//指数
    PolyNode *Next;
};
typedef struct PolyNode *Polynomial;
Polynomial P1;

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

Polynomial Attach(Polynomial P,int e,int c)
{
    Polynomial rear=P;
    Polynomial now=(Polynomial)malloc(sizeof(struct PolyNode));
    while(rear->Next)
    {
        rear=rear->Next;
    }
    rear->Next=now;
    now->Coef=c;
    now->Expon=e;
    now->Next=NULL;
    return P;
}
Polynomial AddSameExpon(Polynomial P)
{
    cout << "START ENTERING SINGLE TERM, 00 TO END" << endl;
    int c,e;
    cin >> c >> e;
    while(c&&e)
    {
        
        int hold=0;
        Polynomial current=P;
        
        while(current)
        {
            
            if(current->Expon==e)
            {
                hold=1;
                current->Coef=current->Coef+c;
                Print(P);
                break;
            }
            else
                current=current->Next;
        }
        if(hold==0)
        {
            P=Attach(P,e,c);
            Print(P);
        }
            
        cout << "START ENTERING SINGLE TERM, 00 TO END" << endl;
        cin >> c >> e;
    }
    return P;
}

Polynomial Sort(Polynomial P)
{
    for(Polynomial First=P->Next;First!=NULL;First=First->Next)
    {
        for(Polynomial Second=P->Next;Second!=NULL;Second=Second->Next)
        {
            if(Second->Next!=NULL)
            {
                if(Second->Expon<Second->Next->Expon)
                {
                    int Tempexp=Second->Expon;
                    int Tempcof=Second->Coef;
                    Second->Coef=Second->Next->Coef;
                    Second->Expon=Second->Next->Expon;
                    Second->Next->Coef=Tempcof;
                    Second->Next->Expon=Tempexp;
                }
            }
        }
    }
    return P;
}

int main(int argc, char **argv)
{
    Polynomial P;
    P=Create();
    Print(P);
    P=AddSameExpon(P);
    Print(P);
    P=Sort(P);
    Print(P);
}