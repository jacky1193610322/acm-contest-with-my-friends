#include <iostream>

using namespace std;
#define N 100
int mynext[N];

int KMP(char *source,char * pattern,int sLen,int pLen){
	int k,j;
	k = j = 0;
	while(k<sLen && j<pLen){
		if(j==-1 || source[k]==pattern[j]){
			++k;
			++j;
		}else{
			j = mynext[j];
		}
	}
	if(j==pLen){
		return sLen - pLen;
	}else{
		return 0;
	}

}


void setNumber(char * pattern,int pLen){
	int k,j;
	mynext[0] = -1;
	k=0;
	j=1;
	while(j<pLen-1){
		if(k==-1 || pattern[k] == pattern[j]){
			++j;
			++k;
			if(pattern[k] != pattern[j])
				mynext[j]=k;
			else{
				
				mynext[j] = mynext[k];
			}
		}else{
			k = mynext[k];
		}
	}
}

void setNumber1(char * pattern,int pLen){
	int k,j;
	mynext[0] = 0;
	k=0;
	j=1;
	while(j<pLen){
		if(pattern[k] == pattern[j]){
			mynext[j] = k+1;
			k++;
			j++;
			
		}else{
			if(k==0){
				j++;
			}else{
				/************************************************************************/
				/* 
					这边一定要是     k-1 因为能进入到else里面一定是pattern[k]!=pattern[j]
					说明应该找k前面那一个的最大前缀  因为pattern[k]!=pattern[j] 已经不匹配了
				*/
				/************************************************************************/
				k = mynext[k-1];
			}
		}
	}
}

void print(int len){
	for(int i=0;i<len;i++){
		cout<<mynext[i]<<"  ";
	}
	cout<<endl;
}

int main(){

	char* s = "BBC ABCDAB ABCDABCDABDE";
	setNumber(s,strlen(s));
	print(strlen(s));
	memset(mynext,0,N);
	setNumber1(s,strlen(s));
	
	print(strlen(s));
	system("pause");
	return 0;
}