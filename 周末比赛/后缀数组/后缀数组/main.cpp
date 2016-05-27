#include<iostream>
using namespace std;

#define N 100

void yuchuliStr(char * str,int len){
	for(int i = 0;i<len;i++){
		str[i] -= 'a'-1;
	}
	str[len] = 0;
}
int cmp(int * src,int a,int b,int j){
	return src[a] == src[b] && src[a+j] == src[b+j];
}

int myws[N],wv[N],xx[N],yy[N],sa[N];
void da(char * s,int len){
	int p = 0,m=N;
	int * x = xx;
	int * y = yy;
	for(int i=0;i<N;i++){
		myws[i] = 0;
	}
	for(int i=0;i<len;i++){
		myws[x[i] = s[i]]++;
	}
	for(int i=1;i<N;i++){
		myws[i] += myws[i-1];
	}
	for(int i=len-1;i>=0;i--){
		sa[--myws[s[i]]] = i;
	}
	for(int i = 1,p=0; p+1 < len;i<<=1){
		p=0; //一开始就因为没有加这句  就出错了  因为下面会改变p的 值
		for(int  j=len-i;j<len;j++){
			y[p++] = j;
		}
		for(int j=0;j<len;j++){
			if(sa[j] >= i){
				y[p++] = sa[j] - i;
			}
		}
		for(int i=0;i<len;i++){
			wv[i] = x[y[i]];
		}
		for(int i=0;i<N;i++){
			myws[i] = 0;
		}
		for(int i=0;i<len;i++){
			myws[wv[i]]++;
		}
		for(int i=1;i<N;i++){
			myws[i] += myws[i-1];
		}
		for(int i=len-1;i>=0;i--){
			sa[--myws[wv[i]]] = y[i];
		}
		y[sa[0]] = 0;
		p=0;
		for(int j=1;j<len;j++){
			y[sa[j]] = cmp(x,sa[j-1],sa[j],i)?p:++p;
		}
		int * t= x;
		x = y;
		y = t;
	}
	
}

int main(){
	
	char s[N] = "aabaaaab";
	int len = strlen(s);
	yuchuliStr(s,len);
	da(s,len+1);
	for(int i=0;i<len;i++){
		cout<<sa[i]<<endl;
		for(int j=sa[i];j<len;j++){
			
			cout<<char(s[j]+'a'-1)<<"   ";
		}
		cout<<endl;

	}


	system("pause");

	return 0;
}