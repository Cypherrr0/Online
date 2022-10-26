#include <bits/stdc++.h>
#include <Windows.h>
#include <sys/time.h>
using namespace std;
typedef struct Node
{
    int number;
    struct Node *next;
}Person;

Person *InitialLink(int n)
{
    Person *head=(Person*)malloc(sizeof(Person));
    head->number=1;
    head->next=NULL;
    Person *Cycle=head;
    for(int i=2;i<=n;i++)
    {
        Person *member=(Person*)malloc(sizeof(Person));
        member->number=i;
        member->next=NULL;
        Cycle->next=member;
        Cycle=Cycle->next;
    }
    Cycle->next=head;
    return head;
}

void Josephus(Person *Head,int m)
{
    Person *tail=Head;
    while(tail->next!=Head)
    {
        tail=tail->next;
    }
    Person *p=Head;
    cout <<"Killed:";
    while(p->next!=p)
    {
        for(int i=0;i<m;i++)
        {
            tail=p;
            p=p->next;
        }
        tail->next=p->next;
        cout << p->number << " ";
        free(p);
        p=tail->next;
    }
    cout << endl;
}

int main()
{
    int n,m;
    cout << "Input N:" << endl;
    cin >> n;
    cout << "Input M:" << endl;
    cin >> m;
    struct timeval begin,end;
    gettimeofday(&begin,0);
    Person *head=InitialLink(n);
    
    Josephus(head,m);
    gettimeofday(&end,0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    cout << "Time used:" << elapsed <<"s"<< endl;
}