#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include<stack>
#include<vector>
#define MAXN 500
using namespace std;

stack<int> s ;
typedef struct _vetex{
	struct _next* next;
	vector<int> lianbiao;
}vetex;

int visit[MAXN];
int dfn[MAXN];
int low[MAXN];
int parent[MAXN];
int index = 0,cnt=0;
vetex v[MAXN];

void tarjan(int v_number){
	int i=0;
	int child = 0;
	s.push(v_number);
	low[v_number] = ++index;
	dfn[v_number] = index;
	visit[v_number] = 1; //是在这里赋值
	vector<int>::iterator it = v[v_number].lianbiao.begin();
	for(it;it!=v[v_number].lianbiao.end();it++){
		int number = *it;
		if(!visit[number]){
			parent[number] = v_number;
			child++;
			tarjan(number);
			low[v_number] = min(low[v_number],low[number]);
		    //visit[number] = 1; //之前在这里赋值就错了
			if(dfn[v_number]<=low[number]){
				int nu;
				cout<<"number"<<cnt++<<endl;
				do{
					nu = s.top();
					cout<<nu<<endl;
					s.pop();
				}while (nu!=v_number);
				s.push(v_number);
				cout<<endl<<"end"<<endl;
			}
		}else if(number!=parent[v_number]){
			low[v_number] = min(low[v_number],dfn[number]);
		}
	}
}



int main(){
	freopen("input.txt","r",stdin);
	for(int i=0;i<MAXN;i++){
		parent[i] = -1;
	}
	for(int i= 0;i<MAXN;i++){
		visit[i]  = 0;
		dfn[i] = 0;
		v[i].next = NULL;
	}
	
	int a,b;
	cin>>a>>b;
	while(a!=-1&&b!=-1){
		v[a].lianbiao.push_back(b);
		v[b].lianbiao.push_back(a);
		cin>>a>>b;
	}
	tarjan(5);

	cout<<"tarjan_end"<<endl;
	

	while (true);
	{

	}
	return 0;
}