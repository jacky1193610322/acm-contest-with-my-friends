#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
using namespace std;
#define MAXN 100
int father[MAXN];

typedef struct _edge{
	int from ;
	int to;
	int weight;
}edge;
edge e[MAXN];
int find(int x){
	if(father[x]!=x)
		father[x] = find(father[x]);
	return father[x];
}

bool unionset(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy){
		if(fx<=fy){
			father[fy] = fx;
		}else{
			father[fx] = fy;
		}
		return true;
	}
	else
	return false;
}

int cmp(edge x,edge y){
	return x.weight<y.weight;
}

int main(){
	int a,b,c;
	freopen("input.txt","r",stdin);
	for(int i=0;i<MAXN;i++){
		father[i] = i;
	}
	int num = 0,nodenum,fathernum;
	cin>>nodenum;
	while(cin>>a>>b>>c,a+b+c!=-3){
		e[num].from=a;
		e[num].to = b;
		e[num].weight = c;
		num++;
	}
	sort(e,e+num,cmp);
	int count =0,edgenum = nodenum-1,sum=0;
	while(count<num){
		if(unionset(e[count].from,e[count].to)){
			edgenum--;
			cout<<nodenum-1-edgenum<<"   "<<e[count].from<<"   "<<e[count].to<<endl;
			if(edgenum==0)break;
		}
		count++;
	}
	if(edgenum == 0)cout<<"success"<<endl;

	while(1);
	
	return 0;
}