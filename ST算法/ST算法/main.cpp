#include <iostream>
using namespace std;
#include <cmath>
#define MAXN 50
int ma[MAXN][17];
int mi[MAXN][17];
int Test[MAXN];
void STInit(int *a,int num){
	for(int i=0;i<num;i++){
		ma[i][0] = a[i];
		mi[i][0] = a[i];
	}
	int m = (int)(log(num*1.0)/log(2.0));
	for(int i=1;i<=m;i++){
		for(int j=0;j<num;j++){
			if(j+(1<<i) <= num){//当j+1<<i >num 的时候已经可以不往后计算了  因为后面一定更大于0
				int begin = j+(1<<(i-1));
				ma[j][i] = max(ma[j][i-1],ma[begin][i-1]);
				mi[j][i] = min(mi[j][i-1],mi[begin][i-1]);
			}else{
				break;
			}
		}
	}
}

int mysearch(int l,int r){
	int num = r-l+1;
	int m = (int)(log(num*1.0)/log(2.0));
	return max(ma[l][m],ma[r+1-(1<<m)][m]);
}

int main(){

	for(int i=0;i<MAXN;i++){
		Test[i] = i;
	}
	STInit(Test,MAXN);
	cout<<mysearch(23,29)<<endl;
	while(1);
	return 0;
}