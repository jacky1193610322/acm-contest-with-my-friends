#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

/************************************************************************/
/* 
	@param  data int的数组
	@param  len 数组的长度

	@return -1代表打开文件出错  1 代表写入成功
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
	@param  path1 文件路径 形如C:\\Users\\Administrator\\Desktop\\test.txt 注意双反斜杠
	@param  path2 文件路径 形如C:\\Users\\Administrator\\Desktop\\test1.txt 注意双反斜杠

	@return -1代表打开文件出错 0代表俩个文件内容不匹配  1 代表成功
*/
/************************************************************************/
int cmpTxtContent(char *path1,char* path2)
{
	char data[1000];
	char data1[1000];
	FILE * fp =fopen(path1,"r");   /* 改为实际文件名 注意路径的反斜杠 */
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
		printf("文件内容不匹配");
		return 0;
	}else
		printf("文件内容匹配");
	//while (1);
	return 1;
}


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


void maxHeapFixDown(int data[],int begin,int number){

	int temp = data[begin];
	int leftSon = begin*2+1;
	int rightSon = leftSon+1;
	while(leftSon<number){
		if(rightSon<number && data[rightSon]>data[leftSon])
			leftSon ++;
		if(data[leftSon] > temp){
			data[begin]=data[leftSon];
			begin = leftSon;
			leftSon = begin*2+1;
			rightSon = leftSon+1;
		}else{
			break;
		}
	}
	data[begin] = temp;
}

void makeHeap(int data[],int number){
	for(int i = number/2-1;i>=0;i--){
		maxHeapFixDown(data,i,number);
	}

}

void HeapSort(int data[],int number){
	makeHeap(data,number);
	for(int i=number-1;i>0;i--){
		swap(data[0],data[i]);
		maxHeapFixDown(data,0,i);
	}
}


void insertSort(int data[],int temp,int number){

	int end = number - 1;
	while(end>=0 && temp<data[end]){
		data[end+1] = data[end];
		end --;
	}
	data[end+1] = temp;
}

void sortInsert(int data[],int number){
	for(int i=1;i<number;i++){
		insertSort(data,data[i],i);
	}
}


void selectSort(int data[],int number){
	
	int whichMin = 0;
	for(int i=0;i<number;i++){
		whichMin = i;
		for(int k=i;k<number;k++){
			if(data[k]<data[whichMin]){
				whichMin = k;
			}
		}
		swap(data[i],data[whichMin]);
	}
}

void  maopaoSort(int data[],int number){

	for(int i=0;i<number;i++){
		for(int k=0;k+1<number-i;k++){
			if(data[k]>data[k+1]){
				swap(data[k],data[k+1]);
			}
		}
	}
}


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
#define N 1000
int *temp = new int[N+2];
void mergeSort(int data[],int left,int right){
	
	int mid = (left+right)/2;
	if(left<right){
		mergeSort(data,left,mid);
		mergeSort(data,mid+1,right);
		merge(data+left,data+mid+1,temp,mid-left+1,right-mid);
	}
}


int data[N];
int data1[N];


#include <math.h>
int singleWei[N];
int index[N]={0};
int indexTemp[N];
void init(){
	for(int i=0;i<N;i++){
		index[i]= i;
	}
}

void getWhichNumber(int num,int *index){
	switch (num){
	case 0:
		for(int i=0;i<N;i++)
			singleWei[i] = data[index[i]]%10;
		break;
	case 1:
		for(int i=0;i<N;i++)
			singleWei[i] = (data[index[i]]%100)/10;
		break;
	case 2:
		for(int i=0;i<N;i++)
			singleWei[i] = (data[index[i]]%1000)/100;
		break;
	case 3:
		for(int i=0;i<N;i++)
			singleWei[i] = (data[index[i]]%10000)/1000;
		break;
	case 4:
		for(int i=0;i<N;i++)
			singleWei[i] = (data[index[i]]%100000)/10000;
		break;
	}
}
int tong[10];
int dataTemp[N];
void clearTong(){
	for(int i=0;i<10;i++){
		tong[i] = 0;
	}
}

void jishuSort(int data[],int number){
	init();
	int* pindex = index;
	int* pindexTemp = indexTemp;
	for(int i=0;i<5;i++){
		clearTong();
		getWhichNumber(i,pindex);
		for(int i=0;i<N;i++){
			tong[singleWei[i]]++;
		}
		for(int i=1;i<10;i++){
			tong[i]=tong[i-1]+tong[i];
		}
		for(int i=N-1;i>=0;i--){
		//这边注意  我当时就写错了
		
			pindexTemp[--tong[singleWei[i]]] = pindex[i];
		}
		int* p = pindex;
		pindex = pindexTemp;
		pindexTemp = p;
	}
	for(int i=0;i<N;i++){
		dataTemp[i] = data[pindex[i]];
	}
}


int main(){
	
	for(int i=0;i<N;i++){
		data[i] = rand()%100000;
		data1[i] = data[i];
	}
	//sort_kuai(data,0,N-1);
	//HeapSort(data,N);
	//sortInsert(data,N);
	//selectSort(data,N);
	//maopaoSort(data,N);
	//mergeSort(data,0,N-1);
	jishuSort(data,N);
	std::sort(data1,data1+N);
	writeToTxt("C:\\Users\\Administrator\\Desktop\\test.txt",data1,N);
	writeToTxt("C:\\Users\\Administrator\\Desktop\\test1.txt",dataTemp,N);
	int res = cmpTxtContent("C:\\Users\\Administrator\\Desktop\\test.txt","C:\\Users\\Administrator\\Desktop\\test1.txt");
	cout<<res;
	while(1);
	return 0;
}