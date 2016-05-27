#include <iostream>

using namespace std;

#define N 500
char p[N];

void setP(char* pattern,int len){
	for(int i=0;i<N;i++){
		p[i] = len;
	}
	for(int i=0;i<len;i++){
		p[pattern[i]] = len - i;
	}
}

int sunday(char* source,char* pattern,int sLen,int pLen){
	int j,k,begin=0;
	j = k =0;
	while(j<sLen  && k<pLen){
		if(source[j] == pattern[k]){
			j++;
			k++;
		}else{
			begin += p[source[begin+pLen]];
			j = begin;
			k=0;
		}
	}
	if(k==pLen){
		return begin;
	}else{
		return -1;
	}
}


int main(){
	char * p="search";
	char * src = "substring searching algorithm";
	setP(p,strlen(p));
	cout<<sunday(src,p,strlen(src),strlen(p));
	system("pause");
	return 0;
}