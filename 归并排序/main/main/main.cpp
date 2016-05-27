#include <iostream>

using namespace std;

void merge(int a[],int b[],int c[],int alen,int blen){
	int j=0,k=0,num=0;
	while(j<alen&&k<blen){
		if(a[j]<b[k]){
			c[num++] = a[j++];
		}else{
			c[num++] = b[k++];
		}
	}
	while(j<alen){
		c[num++] = a[j++];
	}
	while(k<blen){
		c[num++] = b[k++];
	}

	for(int i=0;i<num;i++){
		a[i] = c[i];
	}

}

void mergesort(int a[],int begin,int end,int temp[]){
	int mid = (begin+end)/2;
	if(begin<end){
		mergesort(a,begin,mid,temp);
		mergesort(a,mid+1,end,temp);
		merge(a+begin,a+mid+1,temp,mid-begin+1,end-mid);
	}
	
}

#define N 10
int main(){
	int* a = new int[N];
	int* c = new int[N];

	for(int i=0;i<N;i++){
		a[i] = N-i;
	}

	mergesort(a,0,N-1,c);

	for(int i=0;i<N;i++){
		cout<<a[i]<<endl;
	}
	while(1);
	return 0;
}