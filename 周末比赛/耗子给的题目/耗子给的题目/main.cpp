#include<iostream>

using namespace std;

#define N 40
long long data[N][(N*39)/4+1];
long long data1[N][(N*39)/4+1];
void init(){

	int j = (N*39)/4+1;
	for(int i=1;i<N;i++)
		for(int k=0;k<j;k++){
			if(k==0)
				data[i][k]=1;
			else 
				data[i][k] = 0;
		}

		data[1][1] = 1;
		for(int i=2;i<N;i++){
			int end = (1+i)*i/2;
			int k = 0;
			for(k=1;k<=end && k<j;k++){
				if(k-i>=0)
					data[i][k] = data[i-1][k-i]+data[i-1][k];
				else{
					data[i][k] = data[i-1][k];
				}
			}

		}
}

int main1(){
	int n;
	init();
	while(1){
		cin>>n;
		int sum = 0;
		sum = (1+n)*n/2;
		if((sum&1) ==1){
			cout<<0<<endl;
		}
		else{
			sum /=2;
			cout<<data[n][sum]/2<<endl;

		}
	}
	return 0;
}

#define NUM 100

int ceshi[NUM];

int getRes(int n){
	
	if(n == 1)
		return 1;
	if(n == 2)
		return 1;
	if(ceshi[n]!=0)
		return ceshi[n];
	ceshi[n] = getRes(n-1)+getRes(n-2);
	return ceshi[n];
}
int getRes1(int n){

	if(n == 1)
		return 1;
	if(n == 2)
		return 1;
	
	return getRes1(n-1)+getRes1(n-2);
	
}



int main(){
	int n;
	while(1){
		cin>>n;
		int sum = 0;
		sum = (1+n)*n/2;
		if((sum&1) ==1){
			cout<<0<<endl;
		}
		else{
			sum /=2;
			cout<<getNumber(sum,n)<<endl;

		}
	}
	system("pause");
	return 0;
}