#include<bits/stdc++.h>
using namespace std;
int len;
string str;
template<class T>
struct treeNode{
	T data;
	treeNode *L_child,*R_child;
};


template<class T>
class Tree{
	public:
		~Tree(){
			this->root=new treeNode<T>();
			this->root->L_child=NULL;
			this->root->R_child=NULL;
		}
		treeNode<T>* createTree();
		treeNode<T>* getRoot();
	
	private:
		treeNode<T> *root;
};

template<class T>
treeNode<T>* Tree<T>::createTree()
{
	if(len>=str.size()) return NULL;
	T d = str[len++];
	if(d=='@'){
		return NULL;
	}
	treeNode<T> *node = new treeNode<T>();
	node->data=d;
	node->L_child=createTree();
	node->R_child=createTree();
	return node;
}

template<class T>
treeNode<T>* Tree<T>::getRoot()
{
	return this->root;
}

void levelFind(treeNode<char> *root){
	if(root==NULL) return;
	queue<treeNode<char>*> q;
	q.push(root);
	treeNode<char> *t;
	while(!q.empty()){
		t=q.front();
		if(t->L_child!=NULL){
			q.push(t->L_child);
		}
		if(t->R_child!=NULL){
			q.push(t->R_child);
		}
		cout<<t->data;
		q.pop();
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n--){
		len=0;
		cin>>str;
		Tree<char> *tree = new Tree<char>();
		treeNode<char> *root = tree->getRoot();
		root = tree->createTree();
		levelFind(root);
	}
}

//https://blog.csdn.net/weixin_44546342/article/details/124706367