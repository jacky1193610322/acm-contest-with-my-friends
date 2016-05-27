#include <iostream>
using namespace std;

void mymatern(int *str,int *p,int num){
	p[0] = 1;
	int id = 0,mx = 0;
	int ans = 0;
	for(int i=1;i<num;i++){
		if(i<mx){
			p[i] = min(mx-i,p[2*id-i]);
		}else{
			p[i]=1;
		}
		while(str[i+p[i]]==str[i-p[i]])p[i]++;
		if(i+p[i]>mx){
			id = i;
			mx = i + p[i];
		}
		if(p[ans]<p[i])ans = i;
	}
	for(int j = ans;j<ans+p[ans];j++){
		if(str[j]!='#')cout<<char(str[j]);
	}
	cout<<endl;

}
#define MAXN 50
int test[MAXN];
int pp[MAXN];
 int main(){
	int len=0;
	char *p = "chenyanggnay";
	while(p[len]!='\0')len++;
	test[0] = -1;
	test[1] = '#';
	for(int i = 0;i<len;i++){
		test[2*i+2] = p[i];
		test[2*i+3] = '#';
	}
	test[2*len+2] = 0;
	mymatern(test,pp,2*len+2);
	while(1);
	return 0;
}