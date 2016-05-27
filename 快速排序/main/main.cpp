#include <iostream>
using namespace std;

void quicksort(int* a,int le,int r){
	
	if(le >= r)
	{
		return;
	}

	int left = le;
	int right = r;
	int temp = a[left];
	while(left<right){
		while(left<right && a[right]>temp){
			right--;
		}
		a[left] = a[right];
		if(left<right)left++;
		while(left<right && a[left]<temp){
			left++;
		}
		a[right] = a[left];
		if(left<right)right--;
	}
	a[left] = temp;

	quicksort(a,le,left-1);
	quicksort(a,left+1,r);
}

int n = 5;
int main(){
	int* a = new int[n];
	a[0] = 1;
	a[1] = 1;
	a[4] = 1;
	a[3] = 1;
	a[2] = 1;
	int i = 0;
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	
	while(1);
	return 0;
}