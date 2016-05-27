#include <iostream>
using namespace std;
#define N 260

int mynext[N];
void setNext(char * pat,int len){
	for(int i=0;i<N;i++){
		mynext[i] = len;
	}
	for(int i=0;i<len;i++){
		mynext[pat[i]] = len - i;
	}
}

int sunday(char* src,char* pat,int srcLen,int patLen){

	int j=0,k=0,begin = 0 ;
	while(j<srcLen && k<patLen){
		if(src[j] == pat[k]){
			j++;
			k++;
		}else{
			begin += mynext[src[begin+patLen]];
			j = begin;
			k = 0;
		}
	}
	if(k == patLen){
		return begin;
	}else{
		return -1;
	}

}

int main(){
	char* s = "chenchenyang";
	char* src = "asdfasl;fdjaklsjfedka;sjlkfd;ajschenchenyang;lkfjdakl;sjfdo;aljkl;djoFLJKjhlfjkhnLKJASDFKASL;JDK;JASKDASKlasdkfakchenyang";
	setNext(s,strlen(s));
	int res = sunday(src,s,strlen(src),strlen(s));
	cout<<strlen(src)<<endl;
	cout<<res<<endl;
	for(int i=0;i<strlen(s);i++){
		cout<<src[res+i];
	}
	cout<<endl;
	system("pause");
	return 0;
}