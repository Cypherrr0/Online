#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number, m, k,i;
    struct linknode
    {
        int data;
        struct linknode* next;
        struct linknode* prior;
    };
    scanf("%d%d%d", &number, &m, &k);
    struct linknode* p,*q,*g;
    p = (struct linknode*)malloc(sizeof(struct linknode));
    g = q = p;
    p->data = 1; p->next = p;
    for (i = 2; i <= number; i++)
    {
        q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
        q->prior = g;
        q->data = i;
        q->next = p;
        g = g->next;
    }
    p->prior = g;

    q = p;
    while (q != q->next)
    {
        if (m == 1)
        {
            printf("%d", q->data);
            q->next->prior = q->prior;
            q->prior->next = q->next;
            q = q->prior;
        }
        else
        {
            for (i = 2; i < m; i++)
            q = q->prior;
            printf("%d ", q->prior->data);
            q->prior = q->prior->prior;
            q->prior->next = q;
            q = q->prior;
        }
        if (k == 1)
        {
            printf("%d", q->data);
            q->next->prior = q->prior;
            q->prior->next = q->next;
            q = q->next;
        }
        else
        {
            for (i = 2; i < k; i++)
                q = q->next;
            printf("%d ", q->next->data);
            q->next = q->next->next                                                                                                    ;
            q->next->prior = q;
            q = q->next;
        }
    }
    if (number % 2 == 1)
    printf("%d", p->data);
    printf("\n");
return 0;
}