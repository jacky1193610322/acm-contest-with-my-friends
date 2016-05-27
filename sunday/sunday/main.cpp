#include <iostream>
using namespace std;

#define MAXN 256

int nextchen[MAXN];

void init(char *s,int n ){
	for(int i=0;i<MAXN;i++){
		nextchen[i] = n;
	}
	for(int i=0;i<n;i++){
		nextchen[s[i]] = n-i; 
	}
}


int sunday(char * src,char *pat,int src_num,int pat_num){
	init(pat,pat_num);
	int pos=0,begin = 0,subi=0;
	while(pos<src_num&&pos+pat_num<src_num&&subi<pat_num){
		if(src[pos] == pat[subi]){
			pos++;
			subi++;
		}
		else {
			subi = 0;
			begin += nextchen[src[begin+pat_num]];
			pos = begin;
		}
	}
	if(subi==pat_num){
		return begin;
	}
	return -1;
}

int main(){
	char *src = "chenyangjiangyanliasdfhjlshfjlakhfjklahsdkashldlfjka";
	char *pat = "kaa";
	int res=sunday(src,pat,strlen(src),strlen(pat));
	if(res==-1)cout<<"meiyou"<<res<<endl;
	else{
		cout<<"res:   "<<res<<endl;
		for(int i=0;i<strlen(pat);i++){
			cout<<src[res+i];
		}
	}
	while(1);
	return 0;
}