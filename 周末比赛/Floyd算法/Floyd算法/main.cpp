#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define N 100
#define inf 0x3ffffff
int list[N][N];
int sumNode;
void floyd(){
	for(int i=1;i<=sumNode;i++){
		for(int k=1;k<=sumNode;k++){
			for(int j=1;j<=sumNode;j++){
				if(list[i][j]!=inf && list[k][j]!=inf && list[i][j]+list[j][k]<list[i][k]){
					list[i][k] = list[i][j]+list[j][k];
					list[k][i] = list[i][j]+list[j][k];
				}
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	cin>>sumNode;
	for(int i=0;i<=sumNode;i++)
		for(int k = 0;k<=sumNode;k++){
			if(i==k)
				list[i][k] = 0;
			else
				list[i][k] = inf;
		}
			
	int beg,end,weight;
	while(cin>>beg>>end>>weight){
		if(list[beg][end] == inf || list[beg][end] > weight){
			list[beg][end] = weight;
			list[end][beg] = weight;
		}
	}
	floyd();
	for(int i=1;i<=sumNode;i++){
		for(int k=1;k<=sumNode;k++){
			cout<<list[i][k]<<"  ";
		}
		cout<<endl;
	}
	cout<<"end;";
	while(1);
	return 0;
}