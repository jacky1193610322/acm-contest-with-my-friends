#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


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
���ܳ����ǴӴ�С���Ǵ�С����  ��һ�������в���д����

����Ƿ��ص�һ�����(����С������) ���ص�һ����С�����Ӵ�С�ţ� ��ôһ������left  
��֮����right

���һ��
	int left = 0, right = n-1;
	while(left<=right) {
	int mid = (left+right)/2;
	if(arr[mid] < key) right = mid - 1;
	else if(arr[mid] > key) left = mid + 1;
	���ھ��ǵ��ںż���if�ϻ���else��  

	��ô���ڲ�Ҫ��������  ����������Ѱ�ҵ���key���±� ��left��right ���ջ����  �����������Ԫ����
	��ô  ���ڷ���left  ���Ե��ڵ�ʱ��  Ҫ����if(arr[mid] <= key) right = mid - 1;  ��Ϊ��� ����
	else if(arr[mid] > key) left = mid + 1;   ��ôleft = mid +1 ; ��Ϊ���ص���left  ��left ����ָ����ȵ�Ԫ���� 
	����left  ���ܵ��� mid + 1  ��Ӧ����right = mid -1 ��Ϊ ������right   ����ȥ1 û����

	����right = mid - 1;  ��if(arr[mid] < key) ��ʱ���� if(arr[mid] > key) ��ʱ��  ���������ǴӴ���С����  Ӧ�ý�
	key>����<arr[mid]  ��keyд��ǰ�� ������ʱ��������ҵ���key��   ��ʱ���  key<arr[mid]  ִ��right = mid - 1;   ��Ϊ �Ӵ���С����  key С��a[mid] Ӧ�������
	�����ȥ��


	��������ļ��貢����ʵ���� ֻ��left = right �����һ��ѭ������� ����������Щ����
	���裺����������Ѱ�ҵ���key���±� ��left��right���ջ����  ����������key���Ԫ����
*/
int searchFirstEqual(int *arr, int n, int key)
{
	int left = 0, right = n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] >= key) right = mid - 1;
		else if(arr[mid] < key) left = mid + 1;
	}
	if( left < n && arr[left] == key) return left;
	return -1;
}

int searchLastEqual(int *arr, int n, int key)
{
	int left = 0, right = n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] > key) right = mid - 1;
		else if(arr[mid] <= key) left = mid + 1; 
	}
	if( right>=0 && arr[right] == key) return right;
	return -1;
}

int searchFirstEqualOrLarger(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] >= key) right = mid-1;
		else if (arr[mid] < key) left = mid+1;
	}
	return left;
}

int searchFirstEqualOrSmaller(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] <= key) right = mid-1;
		else if (arr[mid] > key) left = mid+1;
	}
	return left;
}

int searchFirstLarger(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] > key) right = mid-1;
		else if (arr[mid] <= key) left = mid+1;
	}
	return left;
}

int searchFirstSmaller(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] < key) right = mid-1;
		else if (arr[mid] >= key) left = mid+1;
	}
	return left;
}

int searchLastEqualOrSmaller(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int m = (left+right)/2;
		if(arr[m] > key) right = m-1;
		else if (arr[m] <= key) left = m+1;
	}
	return right;
}

int searchLastEqualOrLarger(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int m = (left+right)/2;
		if(arr[m] < key) right = m-1;
		else if (arr[m] >= key) left = m+1;
	}
	return right;
}

int searchLastSmaller(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] >= key) right = mid-1;
		else if (arr[mid] < key) left = mid+1;
	}
	return right;
}

int searchLastLarger(int *arr, int n, int key)
{
	int left=0, right=n-1;
	while(left<=right) {
		int mid = (left+right)/2;
		if(arr[mid] <= key) right = mid-1;
		else if (arr[mid] > key) left = mid+1;
	}
	return right;
}
#ifdef jia
int main(void) 
{
#define MAXN 1000000
	int *arr = new int[MAXN];
	for(int i=0;i<MAXN;i++){
		
	}
	printf("First Equal           : %2d \n", searchFirstEqual(arr, 16, 5));
	printf("Last Equal            : %2d \n", searchLastEqual(arr, 16, 5));
	printf("First Equal or Larger : %2d \n", searchFirstEqualOrLarger(arr, 16, 5));
	printf("First Larger          : %2d \n", searchFirstLarger(arr, 16, 5));
	printf("Last Equal or Smaller : %2d \n", searchLastEqualOrSmaller(arr, 16, 5));
	printf("Last Smaller          : %2d \n", searchLastSmaller(arr, 16, 5));
	system("pause");
	return 0;
}
#endif

int main(void) 
{
	int i ,j,temp;
	#define MAXN 1000000
	int *arr = new int[MAXN];
	int *data = new int[MAXN];
	int num = MAXN;
	for(int i=0;i<MAXN;i++){
		data[i] = rand();
		
	}
	std::sort(data,data+MAXN);
	for(int i=0;i<MAXN;i++){
		arr[i] = data[searchLastEqualOrSmaller(data, MAXN, data[i])];
	}
	
	
	writeToTxt("C:\\Users\\Administrator\\Desktop\\test.txt",data,MAXN);
	writeToTxt("C:\\Users\\Administrator\\Desktop\\test1.txt",arr,MAXN);
	int res = cmpTxtContent("C:\\Users\\Administrator\\Desktop\\test.txt","C:\\Users\\Administrator\\Desktop\\test1.txt");
	
	/*for( i = 0,j = sizeof(arr)/sizeof(arr[0]) - 1;i<j;i++,j--){
		temp = 0;
		swap(arr[i],arr[j]);
	}
	
	printf("First Equal           : %d \n", searchFirstEqual(arr, num, 5));
	printf("Last Equal            : %d \n", searchLastEqual(arr, num, 5));
	printf("First Equal or Smaller: %d \n", arr[searchFirstEqualOrSmaller(arr, num, 5)]);
	printf("First Smaller         : %d \n", searchFirstSmaller(arr, num, 5));
	printf("Last Equal or Larger  : %d \n", arr[searchLastEqualOrLarger(arr, num, 5)]);
	printf("Last Larger           : %d \n", searchLastLarger(arr, num, 5));
	*/
	system("pause");
	return 0;
}
