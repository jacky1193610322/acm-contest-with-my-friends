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
			 //�����������Ϊi�ĺ�׺  ���������j  Ҳ���ǽ���׺ǰ���j��ȥ����  ����������ǰj��ȥ���� 
										   //�����ӳ������ͼ  ǰ��j���ᱻ����  �ɺ����Ĳ���
										//��ȻҲ������forѭ����j��ʼ  ������ֱ�Ӷ�����  ����j��������֪�� ��Ϊsa[i]�����ʾ������i������˭	
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
		p=1;  //һ����p=1 ������p=0  �����p=1 ��Ϊ p = 0�������p-1�ĳ���p+1   ��Ϊ������p++  ��ʹ��p��ֵ Ҳ���ǵ���һ�����������ȵ�ʱ�� ������=0  ��++  �����Ҫ�� Ӧ�ø�Ϊ++p  ����ǰ��һ����p+1
		y[sa[0]] = 0;  //Ϊʲô�ѵ�һλ��Ϊ0  ������Ϊ�� �����forѭ���в����д������һ���Եĺ�׺i������
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