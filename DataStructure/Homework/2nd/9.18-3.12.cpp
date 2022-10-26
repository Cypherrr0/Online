#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

struct List
{
    int Data;
    List *Next;
};
typedef struct List *ListNode;

ListNode CreateList(int n)
{
    ListNode head,current,p;
    int i;
    head=(ListNode)malloc(sizeof(struct List));
    cout << "Start Input List:" << endl;
    current=head;
    cin >> head->Data;
    head->Next=NULL;
    
    for(i=2;i<=n;i++)
    {
        p=(ListNode)malloc(sizeof(struct List));
        cin >> p->Data;
        p->Next=NULL;
        current->Next=p;
        current=p;
    }
    return(head);
}

ListNode ReverseList1(ListNode Head)
{
    //Head=Head->Next;
    if(Head==NULL||Head->Next==NULL)
        return Head;
    else
    {
        ListNode begin=NULL;
        ListNode mid=Head;
        ListNode end=Head->Next;
        while(1)
        {
            mid->Next=begin;
            if(end==NULL)
                break;
            begin=mid;
            mid=end;
            end=end->Next;
        }
        Head=mid;
        return Head;
    }
}

void PrintList(ListNode Head)
{
    ListNode temp=Head;
    // temp=Head->Next;
    while(temp)
    {
        cout<<temp->Data<< " ";
        
        
        temp=temp->Next;
    }
}

ListNode ReverseList2(ListNode Head)
{
    
    ListNode new_head = NULL;
    ListNode temp = NULL;
    if (Head == NULL || Head->Next == NULL) {
        return Head;
    }
    while (Head != NULL)
    {
        temp = Head;
        //将 temp 从 head 中摘除
        Head = Head->Next;

        //将 temp 插入到 new_head 的头部
        temp->Next = new_head;
        new_head = temp;
    }
    return new_head;
}

ListNode ReverseList3(ListNode head)
{
	if (head == NULL) {
		return NULL;
	}
	ListNode p0 = NULL;
	ListNode p1 = head;
	ListNode p2 = head->Next;
	while (p1 != NULL) {
		p1->Next = p0;

		p0 = p1;
		p1 = p2;
		if (p2 != NULL) {
			p2 = p2->Next;
		}
	}
	return p0;
}

int main(int argc, char **argv)
{
    ListNode Head;
    int n;
    cout << "Input N" << endl;
    cin >> n;

    

    Head=CreateList(n);

    struct timeval begin,end;
    gettimeofday(&begin,0);
    ListNode temp=Head;
    cout << "Original List:" << endl;
    PrintList(Head);
    Head=ReverseList1(Head);
    cout <<endl << "Reversed List:" << endl;
    PrintList(Head);
    gettimeofday(&end,0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    cout << endl << "Time Used:" << elapsed << "s" << endl;
}

//http://c.biancheng.net/view/8105.html