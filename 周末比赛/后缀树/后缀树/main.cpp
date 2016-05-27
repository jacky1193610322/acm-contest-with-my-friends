#include<iostream>

using namespace std;

#define MAXN 256

typedef struct _node{
	struct _node * pnext[MAXN];
	int begin;
	int end;
	int leaf;
	struct _node *slink;
} node,* pnode ;

struct _root{ 
	int end;
	pnode slLink;
	pnode root;
	int remaining;
	pnode active_node;
	int active_edge;
	int active_len;
};

typedef struct _root info;


pnode getInitNode(){
	pnode p = new node();
	p->begin = 0;
	p->end = 0;
	p->leaf = 1;//д╛хон╙р╤вс
	for(int i=0;i<MAXN;i++){
		p->pnext[i] = NULL;
	}
	p->slink = NULL;
	return p;
}


info * initRoot(){
	info* p = new info();
	pnode root = getInitNode();
	root->leaf = 0;
	p->active_edge = -1;
	p->active_len = 0;
	p->active_node = root;
	p->end = 0;
	p->slLink = NULL;
	p->root = root;
	p->remaining = 0;

	return p;
}

int getlength(pnode p){
	return p->end - p->begin ;
}

info* minfo;

char str[10000];

bool walkdown(pnode p){
	int length = getlength(p);
	if(p->leaf == 1)
		length = minfo->end - p->begin;
	if (minfo->active_len >= length ) {
		minfo->active_node = p;
		minfo->active_edge = -1;
		minfo->active_len -= getlength(p);
		return true;
	}
	return false;
}

void insert(char c,int num){
	str[minfo->end] = c;
	minfo->end++;
	minfo->remaining++;
	while(minfo->remaining>0){
		if(minfo->active_len == 0){
			pnode p = minfo->active_node;
			if(p->pnext[c]==NULL){
				pnode child = getInitNode();
				child->begin = num;
				p->pnext[c] = child;
			}else{
				minfo->active_edge = c;
				minfo->active_len ++;
				p = p->pnext[minfo->active_edge];
				walkdown(p);
				break;
			}
		}else{
			pnode activenode = minfo->active_node;
			pnode p = activenode->pnext[minfo->active_edge];
			if(str[p->begin+minfo->active_len] == c){
				//minfo->active_edge = c;
				minfo->active_len ++;
				walkdown(p);
				break;
			}else{
				pnode leaf = getInitNode();
				leaf->begin = num;
				pnode neibu = getInitNode();
				neibu->leaf = 0;
				neibu->begin = p->begin;
				neibu->end = p->begin + minfo->active_len;
				p->begin = p->begin + minfo->active_len;
				activenode->pnext[minfo->active_edge] = neibu;
				neibu->pnext[str[num]] = leaf;
				neibu->pnext[str[p->begin]] = p;

				if(minfo->slLink == NULL){
					minfo->slLink = neibu;
				}else{
					minfo->slLink->slink = neibu;
					minfo->slLink = neibu;
				}
			}
		}

		minfo->remaining--;
        if (minfo->active_node == minfo->root && minfo->active_len > 0) {  //rule 1
		    minfo->active_len--;
		    minfo->active_edge = str[num - minfo->remaining + 1];
		} else{
			minfo->active_node = minfo->active_node->slink > 0 ? minfo->active_node->slink : minfo->root; //rule 3
		}
	}
	if(minfo->remaining==0){
		minfo->slLink = NULL;
	}
}

int main(){
	minfo = initRoot();
	//char * str = "xyzxyzcxyzaxyd";
	char * str = "aaaaaaa$";
	for(int i=0;i<strlen(str);i++){
		insert(str[i],i);
	}

	return 0;
}