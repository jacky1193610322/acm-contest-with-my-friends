#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;
#define N 100
#define inf 0x3ffffff
int dist[N];
int vis[N];
int pre[N];

int list[N][N];
int sumNode;

int prim(int node){

	for(int i=1;i<=sumNode;i++){
		dist[i] = inf;
		vis[i] = 0;
		pre[i] = -1;
	}

	for(int i=1;i<=sumNode;i++){
		int nodeWeight = list[node][i];
		if(nodeWeight !=inf ) {
			dist[i] = list[node][i];
			pre[i] = node;
		}
	}
	vis[node] = 1;
	dist[node] = 0;
	for(int k=0;k<sumNode-1;k++){

		int min = inf;
		int u = -1;
		for(int i=1;i<=sumNode;i++){
			if(vis[i]==0 && min > dist[i]){
				min = dist[i];
				u = i;
			}
		}
		if(u == -1){
			return 0;
		}
		vis[u] = 1;
		for(int i=1;i<=sumNode;i++){
			if(vis[i] == 0 && dist[i]>dist[u] + list[u][i]){
				dist[i] = dist[u] + list[u][i];
				pre[i] = u; 
			}
		}
	}
	return 1;
}

void printTrace(int node){
	while(pre[node]!=-1){
		cout<<node<<"   ";
		node = pre[node];
	}
	cout<<node<<endl;
}


int main(){
	freopen("input.txt","r",stdin);

	int beg,end,weight;
	cin>>sumNode;
	for(int i=1;i<=sumNode;i++)
		for(int k=1;k<=sumNode;k++)
			list[i][k] = inf;
	while(cin>>beg>>end>>weight){

		if(list[beg][end] ==inf || list[beg][end] >  weight){
			list[beg][end] = weight;
			list[end][beg] = weight;
		}

	}

	cout<<prim(1)<<endl;;
	for(int i=1;i<=sumNode;i++){
		printTrace(i);
	}
	while(1);
	return 0;
}
