#include <stdio.h>
//构造哈夫曼树
typedef struct HuffmanTreeNode *HuffmanTree;
struct HuffmanTreeNode
{
    int weight;
    char ch;
    HuffmanTree left;
    HuffmanTree right;
};
HuffmanTree Huffman(MinHeap H)
{
    int i;
    HuffmanTree T;
    BuildMinHeap(H);//把数组按权值调整为最小堆
    for(i=0;i<H->Size;i++)//做H->Size-1次合并
    {
        T=(HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));//建立新节点
        T->left=DeleteMin(H);//从最小堆中删除一个节点，作为T的左子节点
        T->right=DeleteMin(H);//从最小堆中删除一个节点，作为T的右子节点
        T->weight=T->left->weight+T->right->weight;//计算新节点的权值
        InsertMinHeap(H,T);//把新节点插入最小堆
    }
    T=DeleteMin(H);//最后剩下的一个节点就是树的根节点
    return T;
}

int main()
{

}