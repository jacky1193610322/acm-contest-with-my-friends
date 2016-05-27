#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAXN 11

int sum[MAXN<<2];

int add[MAXN<<2];

void pushup(int rt){
	sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int rt,int Left,int right){
	if(Left == right){
		add[rt] = 0;
		cin>>sum[rt];
		return ;
	}
	int m = (Left+right)>>1;
	build(rt<<1,Left,m);
	build(rt<<1|1,m+1,right);
	pushup(rt);
}

void pushdown(int rt,int Left,int Right){
	if(add[rt]!=0){
		int m = (Right + Left)>>1;
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt]*(m - Left + 1);
		sum[rt<<1|1] += add[rt]*(Right - m);
		add[rt] = 0;
	}
}
void updata(int which_left,int which_right,int data,int Left,int Right,int rt){
	if(which_left<=Left&&Right<=which_right){
		add[rt] = data;
		sum[rt] = data*(Right - Left + 1);
		return;
	}
	pushdown(rt,Left,Right);//�Ҹо����pushdown���Բ�Ҫ �����Ҫ ��ô�����sum[rt] = Right - Left + 1;
							//Ҳ��Ҫ  �����sum[rt] = Right - Left + 1;  query��ʹ�� ����ʱ��ͷ����� query�� ����  
	int m = (Left+Right)>>1;
	if(which_left<=m)updata(which_left,which_right,data,Left,m,rt<<1);
	if(which_right>m)updata(which_left,which_right,data,m+1,Right,rt<<1|1);
	pushup(rt);
}
int query(int which_left,int which_right,int Left,int Right,int rt){
	
	if (which_left <= Left && Right <= which_right) {
		return sum[rt];
	}
	pushdown(rt ,Left,Right);
	int m = (Left + Right) >> 1;
	long ret = 0;
	if (which_left <= m) ret += query(which_left , which_right , Left,m,rt<<1);
	if (m < which_right) ret += query(which_left , which_right , m+1,Right,rt<<1|1);
	
	return ret;

}


int main(){
	freopen("input.txt","r",stdin);
	int a;
	for(int i = 1;i<MAXN;i++){
		cin>>a;
		updata(i,i,a,1,MAXN-1,1);
	}
	for(int i = 1;i<MAXN;i++){
		cout<<i<<" �� "<<MAXN-1<<"  "<<query(i,MAXN-1,1,MAXN-1,1)<<endl;;
	}

	while(1);
	return 0;
}