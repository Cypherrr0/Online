#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 5

struct Deque
{
    int Data[MAXSIZE];
    int head=0;
    int tail=0;
};
typedef struct Deque DequeArray;

void Push(DequeArray *p,int n)//前端插入
{
    if((p->tail-p->head+MAXSIZE)%MAXSIZE==MAXSIZE-1)//(p->tail+1)==p->head
    {
        cout << "NO ROOM!!!" << endl;
    }
    else
    {
        p->head=(p->head+MAXSIZE-1)%MAXSIZE;
        p->Data[p->head]=n;
        cout << "PUSH SUCCESS!!!" << endl;
    }
}

int Pop(DequeArray *p)//删除前端并返回
{
    if(p->head-p->tail==0)
    {
        cout << "NO DATA!!!" << endl;
        return -1;
    }
    else
    {
        int n=p->Data[p->head];
        p->head=(p->head+1)%MAXSIZE;
        cout << "POP SUCCESS!!!" << endl;
        return n;
    }
}

void Inject(DequeArray *p,int n)
{
    if((p->tail-p->head+MAXSIZE)%MAXSIZE==MAXSIZE-1)//(p->tail+1)==p->head
    {
        cout << "NO ROOM!!!" << endl;
    }
    else
    {
        
        p->Data[p->tail]=n;
        p->tail=(p->tail+1)%MAXSIZE;
        cout << "INJECT SUCCESS!!!" << endl;
    }
}

int Eject(DequeArray *p)
{
    if(p->head-p->tail==0)
    {
        cout << "NO DATA!!!" << endl;
        return -1;
    }
    else
    {
        
        p->tail=(p->tail+MAXSIZE-1)%MAXSIZE;
        cout << "EJECT SUCCESS!!!" << endl;
        return p->Data[p->tail];
    }
}

int main()
{
    int x;
    DequeArray p;
    cout << "0 FOR END, 1 FOR PUSH, 2 FOR POP, 3 FOR INJECT, 4 FOR EJECT" << endl;
    cin >> x;
    while(x!=0)
    {
        int a,b,c;
        
        switch(x)
        {
            case 0:
                return 0;
            case 1:
                int n;
                cout << "INPUT N: TO PUSH" << endl;
                cin >> n;
                Push(&p,n);
                break;
            case 2:
                b=Pop(&p);
                cout << "POP: " << b << endl;
                break;
            case 3:
                
                cout << "INPUT N: TO INJECT" << endl;
                cin >> a;
                Inject(&p,a);
                break;
            case 4:
                c=Eject(&p);
                cout << "POP END :" << c << endl;
                break;
        }
        cout << "0 FOR END, 1 FOR PUSH, 2 FOR POP, 3 FOR INJECT, 4 FOR EJECT" << endl;
        cin >> x;
    }
}
