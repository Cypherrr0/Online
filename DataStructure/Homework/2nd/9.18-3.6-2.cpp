#include <bits/stdc++.h>

using namespace std;

struct PolyNode
{
    int Coef;//ϵ��
    int Expon;//ָ��
    PolyNode *Next;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

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

void AddNode(Polynomial P,int Coef,int Expon)
{
	Polynomial p,q;
	p=P;
	while(p)
	{
		if(Expon==p->Expon)
		{
			p->Coef+=Coef;
			break;
		}
		p=p->Next;
	}
}