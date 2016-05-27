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



/*
不管程序是从大到小还是从小到大  都一样按下列步骤写程序

如果是返回第一个最大(按从小到大排) 返回第一个最小（按从大到小排） 那么一定返回left  
反之返回right

框架一样
	int left = 0, right = n-1;
	while(left<=right) {
	int mid = (left+right)/2;
	if(arr[mid] < key) right = mid - 1;
	else if(arr[mid] > key) left = mid + 1;
	现在就是等于号加在if上还是else上  

	那么现在不要管其他的  假设现在是寻找等于key的下标 且left与right 最终会相等  并且落在相等元素上
	那么  由于返回left  所以等于的时候  要加在if(arr[mid] <= key) right = mid - 1;  因为如果 加在
	else if(arr[mid] > key) left = mid + 1;   那么left = mid +1 ; 因为返回的事left  且left 正好指在相等的元素上 
	所以left  不能等于 mid + 1  而应该让right = mid -1 因为 不返回right   它减去1 没有用

	至于right = mid - 1;  是if(arr[mid] < key) 的时候还是 if(arr[mid] > key) 的时候  假设现在是从大往小排序  应该将
	key>或者<arr[mid]  将key写在前面 并且这时候就想着找等于key的   这时如果  key<arr[mid]  执行right = mid - 1;   因为 从大往小排序  key 小于a[mid] 应该往左边
	更大的去找


	还有上面的假设并不真实存在 只有left = right 在最后一次循环会相等 而是这样好些代码
	假设：假设现在是寻找等于key的下标 且left与right最终会相等  并且落在与key相等元素上
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
