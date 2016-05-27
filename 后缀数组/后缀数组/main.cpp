#include <iostream>
using namespace std;
#define MAXN 256

int zhuzi[MAXN],myrank[MAXN],secondKey_xiabiao[MAXN],secondkey[MAXN];
bool cmp(int*str,int can1,int can2,int j){
	return str[can1]==str[can2]&&str[can1+j]==str[can2+j];
}
void da(int* src,int* sa,int src_num,int zhuzi_num){
	int i,p,j;
	int* x = myrank;
	int *y = secondKey_xiabiao;
	int *second = secondkey;
	for(i=0;i<zhuzi_num;i++){
		zhuzi[i] = 0;
	}
	for(i=0;i<src_num;i++){
		zhuzi[x[i]=src[i]]++;
	}
	for(i=1;i<zhuzi_num;i++){
		zhuzi[i]+=zhuzi[i-1];
	}
	for(i=src_num-1;i>=0;i--){
		sa[--zhuzi[src[i]]] = i;
	}
	for(p=1,j=1;p<src_num;j*=2,zhuzi_num=p){
		for(i=src_num-j,p=0;i<src_num;i++){
			y[p++] = i;
		}
		for(i=0;i<src_num;i++){
			 //这个代表将排名为i的后缀  如果超过了j  也就是将后缀前面的j个去掉了  而不是排名前j个去掉了 
										   //这个反映了那张图  前面j个会被丢弃  由后续的补上
										//当然也可以是for循环从j开始  这样就直接丢弃了  但是j的排名不知道 因为sa[i]数组表示排名第i名的是谁	
		}
		for(i=0;i<src_num;i++){
			second[i] = x[y[i]];
		}
		for(i=0;i<zhuzi_num;i++){
			zhuzi[i] = 0;
		}
		for(i=0;i<src_num;i++){
			zhuzi[second[i]]++;
		}
		for(i=1;i<zhuzi_num;i++){
			zhuzi[i]+=zhuzi[i-1];
		}
		for(i=src_num-1;i>=0;i--){
			sa[--zhuzi[second[i]]] = y[i];
		}
		p=1;  //一定是p=1 而不是p=0  当你把p=1 改为 p = 0尽管你把p-1改成了p+1   因为下面是p++  先使用p的值 也就是当下一个与这个不相等的时候 我是先=0  在++  如果真要改 应该改为++p  并且前面一定是p+1
		y[sa[0]] = 0;  //为什么把第一位设为0  那是因为在 下面的for循环中不会改写排名第一所对的后缀i的排名
		for(i=1;i<src_num;i++){
			y[sa[i]] = cmp(x,sa[i-1],sa[i],j)?p-1:p++;
		}
		int* t = x;
		x = y;
		y = t;
	}
}

int main(){
	int str[MAXN];
	int sa[MAXN];
	int num=0;
	int i,j;
	char * p = "aabsdef";
	for(i=0;p[i]!='\0';i++){
		str[i] = p[i];
		num++;
	}
	str[num++] = 0;
	da(str,sa,num,256);
	for(i=1;i<num;i++){
		cout<<"sa[j]=  "<<sa[i]<<"    ";
		for( j = sa[i];str[j]!='\0';j++){
			cout<<char(str[j]);
		}
		cout<<endl;
	}
	while(1);
	return 0;
}