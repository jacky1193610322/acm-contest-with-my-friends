#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

/************************************************************************/
/* 
	@param  data int������
	@param  len ����ĳ���

	@return -1������ļ�����  1 ����д��ɹ�
*/
/************************************************************************/
int writeToTxt(char * path,int data[],int len){

	FILE *fp=fopen(path,"w");
	if(!fp){
		return -1;
	}
	for(int i=0;i<len;i++){
		fprintf(fp,"%d\n",data[i]);
	}
	fclose(fp);  
	return 1;
}

/************************************************************************/
/* 
	@param  path1 �ļ�·�� ����C:\\Users\\Administrator\\Desktop\\test.txt ע��˫��б��
	@param  path2 �ļ�·�� ����C:\\Users\\Administrator\\Desktop\\test1.txt ע��˫��б��

	@return -1������ļ����� 0���������ļ����ݲ�ƥ��  1 ����ɹ�
*/
/************************************************************************/
int cmpTxtContent(char *path1,char* path2)
{
	char data[1000];
	char data1[1000];
	FILE * fp =fopen(path1,"r");   /* ��Ϊʵ���ļ��� ע��·���ķ�б�� */
	FILE * f1 = fopen(path2,"r");
	
	if(!fp || !f1)
	{
		printf("can't open file\n");
		return -1;
	}
	bool flag = true;
	while(!feof(fp) && !feof(f1))
	{
		fscanf(fp,"%s",data);
		//printf("%s  ",data);
		fscanf(f1,"%s",data1);
		//printf("%s  ",data1);
		if(atoi(data)!=atoi(data1)){
			flag = false;
			break;
		}
	}
	fclose(fp);
	fclose(f1);
	if(flag == false){
		printf("�ļ����ݲ�ƥ��");
		return 0;
	}else
		printf("�ļ�����ƥ��");
	//while (1);
	return 1;
}

/*
void sort_kuai(int data[],int left,int right){
	if(left >=right)
		return;
	int temp = data[left];
	int begin = left;
	int end = right;
	while(left<right){

		while(left<right && data[right]>=temp){
			right--;
		}
		data[left] = data[right];
		if(left<right)	left ++;
		
		while (left<right && data[left]<=temp){
			left++;
		}
		data[right] = data[left];
		if(left<right)	right--;
		
	}
	data[left] = temp;
	sort_kuai(data,begin,left-1);
	sort_kuai(data,left+1,end);
}
*/
int partion(int data[],int left,int right){
	int temp = data[left];
	int begin = left;
	int end = right;
	while(left<right){

		while(left<right && data[right]>=temp){
			right--;
		}
		data[left] = data[right];
		if(left<right)	left ++;

		while (left<right && data[left]<=temp){
			left++;
		}
		data[right] = data[left];
		if(left<right)	right--;

	}
	data[left] = temp;
	return left;
}
#include <stack>
struct _data{
	int* data;
	int left;
	int right;
	int begin;
	int end;
	int flag;
};
typedef struct _data mydata;
void quickSortFeiDiGui(int data[],int left,int right){
	stack<mydata> s;
	mydata m;
	m.data = data;
	m.left = left;
	m.right = right;
	m.flag = 0;
	s.push(m);
	while(!s.empty()){
		if(s.top().flag<3){
			while(s.top().flag<3 ){
				s.top().flag++;
				//Ϊʲô���  s.top().flag!=1 ��Ϊ����ģ��ݹ��ʱ�� �ж��ǲ�����ֹ��ʱ�� ��ʹ�õ�һ�ν�����ж� ����
				// �����whileѭ���Ļ� ���ڶ��ν����ʱ�����Ǵ�ͷ��ʼ�����  ����������� s.top().flag��ô ����ڵ�һ�ν����޸���
				// s.top().left ��ô
				
				if(s.top().flag - 1 == 0 ){

					if(s.top().left>=s.top().right){
						s.top().flag = 3;
						break;
					}
					//s.top().res = partion(s.top().data,s.top().left,s.top().right);
					s.top().begin = s.top().left;
					s.top().end = s.top().right;
					int temp = s.top().data[s.top().left];
					while(s.top().left<s.top().right){

						while(s.top().left<s.top().right && s.top().data[s.top().right]>=temp){
							s.top().right--;
						}
						s.top().data[s.top().left] = s.top().data[s.top().right];
						if(s.top().left<s.top().right)	s.top().left ++;

						while (s.top().left<s.top().right && s.top().data[s.top().left]<=temp){
							s.top().left++;
						}
						s.top().data[s.top().right] = s.top().data[s.top().left];
						if(s.top().left<s.top().right)	s.top().right--;

					}
					data[s.top().left] = temp;
					mydata m1;
					m1.data = s.top().data;
					m1.flag = 0;
					m1.left = s.top().begin;
					m1.right = s.top().left -1;
					s.push(m1);
				}
				if(s.top().flag - 1 == 1 ){
					mydata m1;
					m1.data = s.top().data;
					m1.flag = 0;
					m1.left = s.top().left + 1;
					m1.right = s.top().end;
					s.push(m1);
				}

			}
		}else{
			s.pop();
		}
	}
}

struct _mergeData{
	int * data;
	int left;
	int right;
	int mid;
	int flag;
};

void merge(int data1[],int data2[],int temp[],int len1,int len2){
	int begin1 = 0;
	int begin2 = 0;
	int zong = 0;
	while(begin1<len1 && begin2 <len2){
		if(data1[begin1]<data2[begin2]){
			temp[zong++] = data1[begin1++];
		}else{
			temp[zong++] = data2[begin2++];
		}
	}
	while(begin1<len1){
		temp[zong++] = data1[begin1++];
	}
	while(begin2<len2){
		temp[zong++] = data2[begin2++];
	}
	for(int i=0;i<zong;i++){
		if(i<len1){
			data1[i] = temp[i];
		}else{
			data2[i-len1] = temp[i];
		}
	}
}
#define N 10000
int *temp = new int[N+2];
void mergeSort(int data[],int left,int right){

	int mid = (left+right)/2;
	if(left<right){
		mergeSort(data,left,mid);
		mergeSort(data,mid+1,right);
		merge(data+left,data+mid+1,temp,mid-left+1,right-mid);
	}
}
typedef struct _mergeData mergeData;
/*  //������ȷ��
void mergeSortFeiDiGui(int data[],int left,int right){
	stack<mergeData> s;
	mergeData m;
	m.data = data;
	m.flag = 0;
	m.left = left;
	m.right = right;
	s.push(m);
	while(!s.empty()){
		if(s.top().flag<3){
			while(s.top().flag<3){
				s.top().flag++;
				if(s.top().left>=s.top().right && s.top().flag == 1){
					s.top().flag = 3;
					break;
				}
				if(s.top().flag - 1 == 0){
					s.top().mid = (s.top().left + s.top().right)/2;
					mergeData m1;
					m1.flag = 0;
					m1.data = s.top().data;
					m1.left = s.top().left;
					m1.right = s.top().mid;
					s.push(m1);
				}else if(s.top().flag - 1 == 1){
					mergeData m1;
					m1.flag = 0;
					m1.data = s.top().data;
					m1.left = s.top().mid+1;
					m1.right = s.top().right;
					s.push(m1);
				}else {
					merge(s.top().data+s.top().left,s.top().data+s.top().mid+1,temp,s.top().mid-s.top().left+1,s.top().right-s.top().mid);
				}


			}

		}else{
			s.pop();
		}

	}
};
*/

void mergeSortFeiDiGui(int data[],int left,int right){
	stack<mergeData> s;
	mergeData m;
	m.data = data;
	m.flag = 0;
	m.left = left;
	m.right = right;
	s.push(m);
	while(!s.empty()){
		if(s.top().flag<3){
			while(s.top().flag<3){
				s.top().flag++;
				if((s.top().left<s.top().right && s.top().flag ==1) || s.top().flag!=1){
					if(s.top().flag - 1 == 0){
						s.top().mid = (s.top().left + s.top().right)/2;
						mergeData m1;
						m1.flag = 0;
						m1.data = s.top().data;
						m1.left = s.top().left;
						m1.right = s.top().mid;
						s.push(m1);
					}else if(s.top().flag - 1 == 1){
						mergeData m1;
						m1.flag = 0;
						m1.data = s.top().data;
						m1.left = s.top().mid+1;
						m1.right = s.top().right;
						s.push(m1);
					}else {
						merge(s.top().data+s.top().left,s.top().data+s.top().mid+1,temp,s.top().mid-s.top().left+1,s.top().right-s.top().mid);
					}
				}else{
					s.top().flag = 3;
				}
			}
		}else{
			s.pop();
		}
	}
};

int data[N];
int data1[N];





int main(){
	
	for(int i=0;i<N;i++){
		data[i] = rand();
		data1[i] = data[i];
	}
	quickSortFeiDiGui(data,0,N-1);
	//mergeSortFeiDiGui(data,0,N-1);
	std::sort(data1,data1+N);
	writeToTxt("C:\\Users\\Administrator\\Desktop\\test.txt",data1,N);
	writeToTxt("C:\\Users\\Administrator\\Desktop\\test1.txt",data,N);
	int res = cmpTxtContent("C:\\Users\\Administrator\\Desktop\\test.txt","C:\\Users\\Administrator\\Desktop\\test1.txt");
	cout<<res;
	while(1);
	return 0;
}