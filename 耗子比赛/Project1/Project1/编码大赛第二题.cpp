#include<iostream>
#include<cmath>
using namespace std;

int getMaxNumber(int x){
	return sqrt(double(x*2));
}

int main(){
	int x=0;
	while(1){
	int flag = 0;
	cin>>x;

	int maxNumber = getMaxNumber(x);

	if(x&1==1 && x!=1){//ÆæÊý
		flag = 1;
		for(int i=maxNumber;i>=3;i-=2){
			
			int chushu = x/i;
			if(chushu*i == x){
				int begin = chushu-i/2;
				for(int k=0;k<i;k++){
					cout<<begin+k;
					if(k!=i)cout<<" ";
				}
				cout<<endl;
			}
		}
		cout<<x/2<<" "<<x/2+1<<endl;
	}
	else{
		for(int i=maxNumber;i>=2;i-=2){
			if((x*2)%i==0 && (x%i)!=0){
				flag = 1;
				int begin = x/i-i/2+1;
				for(int k=0;k<i;k++){
					cout<<begin+k;
					if(k!=i)cout<<" ";
				}
				cout<<endl;
			}
		}
	}
	if(flag == 0){
		cout<<"None"<<endl;
	}

		
}

	return 0;
}