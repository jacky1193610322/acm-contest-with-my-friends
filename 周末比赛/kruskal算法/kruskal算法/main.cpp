#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100


int sumNode;
int father[N];
int vis[N];
int find(int node){
	int x = node;
	while(father[node]!=node){
		node = father[node];
	}
	int temp;
	while(father[x]!=x){
		temp = father[x];
		father[x] = node;
		x = temp;
	}
	return node;
};

int unionSet(int u,int v){
	int fu = find(u);
	int fv = find(v);
	if(fu!=fv){
		if(fu<=fv){
			father[fv] = fu;
		}else{
			father[fu] = fv;
		}
		return 1;
	}else{
		return 0;
	}
}

typedef struct _edge{
	int beg;
	int end;
	int weight;
}edge;
edge kru[N];
int edgeNum=0;

bool cmpp(edge a,edge b){
	return a.weight<b.weight;

}

void krusal(){
	sort(kru,kru+edgeNum,cmpp);
	int sum=0;
	int i = 0;
	while(i<edgeNum && sum<sumNode-1){
		if(unionSet(kru[i].beg,kru[i].end)){
			sum++;
			cout << kru[i].beg<<"   "<<kru[i].end<<endl;
		}
		i++;
	}
}

void printTrace(int node){


}


int main(){
	for(int i=0;i<N;i++){
		father[i]= i;
	}
	freopen("input.txt","r",stdin);
	int beg,end,weight;
	cin>>sumNode;
	while(cin>>beg>>end>>weight){
		kru[edgeNum].beg = beg;
		kru[edgeNum].end = end;
		kru[edgeNum].weight = weight;
		edgeNum++;
	}

	krusal();

	while(1);
	return 0;
}