#include <iostream>
using namespace std;
#define N 1000
int mynext[N];

int strCmp(char* src,char* pat,int srcLen,int patLen){
	int j,k;
	j = k = 0;
	while(j < srcLen && k < patLen){
		if(k == -1 || src[j] == pat[k]){
			++k;
			++j;
		}else{
			k = mynext[k];
		}
	}
	if(k == patLen){
		return j - patLen;
	}else {
		return -1;
	}
}

void setNext(char * pat,int len){
	int j,k;
	j = 1;
	k = 0;
	mynext[0] = -1;
	while(j < len - 1){
		if(k == -1 || pat[j] == pat[k]){
			++k;
			++j;
			if(pat[j] == pat[k])
				mynext[j] = mynext[k];
			else{
				mynext[j] = k;
			}
		}else{
			k = mynext[k];
		}	
	}
}

int main(){

	char* s = "asjl";
	char* src = "asdfjalksjfd;lkasjlkdfjaskl;djfalksjdflk;asjdfkllahsdfco8qwiealhfndbowuabedchlqnWDSAHUIJKQWAEBUSDCILKJNAwlkwahnefsdcolawjlkneasiudfnlaschenyang";
	setNext(s,strlen(s));
	int begin = strCmp(src,s,strlen(src),strlen(s));
	cout<<strlen(src)<<endl;
	cout<<begin<<endl;
	system("pause");
	return 0;
}