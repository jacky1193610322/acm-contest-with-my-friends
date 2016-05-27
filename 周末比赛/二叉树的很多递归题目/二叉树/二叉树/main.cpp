#include <iostream>
using namespace std;

typedef struct _node{
	struct _node * left;
	struct _node * right;
	int data;
}Node;

typedef struct _root{
	struct _node * root;
}Root;
Root root; 

Node * createNode(int a){
	Node * pNode = new Node();
	pNode->data = a;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}


void insert(int a){
	Node * p = root.root;
	Node * pNode = createNode(a);
	if(root.root == NULL){
		root.root = pNode;
		return;
	}
	int flag = 0;
	Node * pre = NULL;
	while(p!=NULL){
		pre = p;
		if(a<p->data){
			p = p->left;
			flag = 1;
		}else if(a == p->data){
			flag = 2;
			break;
		}else{
			flag = 3;
			p = p->right;
		}
	}
	if(flag == 1){
		pre->left = pNode;
	}else if(flag == 3){
		pre->right = pNode;
	}
}

void trace_xianxu(Node* p){
	if(p == NULL) return;
	
	trace_xianxu(p->left);
	cout<<p->data<<endl;
	trace_xianxu(p->right);
}


int getNodeNum(Node * p){
	if(p == NULL) return 0;
	return getNodeNum(p->left)+getNodeNum(p->right)+1;
}

int getDepth(Node *p){
	if(p == NULL) return 0;
	int left = getDepth(p->left);
	int right = getDepth(p->right);

	return max(left,right)+1;

}

int getLeafNum(Node* p){
	if(p==NULL) return 0;
	if(p->left == NULL && p->right == NULL){
		return 1;
	}
	return getLeafNum(p->left)+getLeafNum(p->right);
}

int whichLevelTrace(Node * p,int k){
	if(p == NULL || k<0) return 0;
	if(k == 1) return 1;
	return whichLevelTrace(p->left,k-1) + whichLevelTrace(p->right,k-1);;
	
}

Node * leastCommonAncestors(Node* root,Node* a,Node* b){
	return NULL;
}

void mirror(Node * p){
	if(p == NULL) return;

	mirror(p->left);
	mirror(p->right);
	Node* temp = p->left;
	p->left = p->right;
	p->right = temp;
}

int  main(){
	for(int i = 0;i<10;i++){
		int ram = rand();
		//cout<<ram<<"   ";
		insert(ram);
	}
	/*cout<<endl;
	cout<<"----------------------------------"<<endl;
	trace_xianxu(root.root);*/

	cout<<"节点个数"<<getNodeNum(root.root)<<endl;;
	cout<<"最大深度"<<getDepth(root.root)<<endl;;
	cout<<"叶子节点数"<<getLeafNum(root.root)<<endl;;
	int num;
	cout<<"你想打印哪层的节点数"<<endl;
	cin>>num;
	cout<<"第K层节点数"<<endl;
	cout<<whichLevelTrace(root.root,num)<<endl;;
	
	mirror(root.root);
	trace_xianxu(root.root);

	system("pause");
	return 0;
}