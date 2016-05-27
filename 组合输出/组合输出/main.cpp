#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>  
int n, r, ans[25];  

void DFS(int num, int step)  
{  
	ans[step] = num;  
	if(step == r)  
	{  
		for(int i = 1; i <= step; i++)  
			printf("%3d", ans[i]);  
		printf("\n");  
		return;  
	}  
	for(int i = num+1; i <= n; i++)//  如果是不可重复  那么是num+1  如果是可重复取  但元素是不可重复的  将i = num  
		DFS(i, step + 1);  
}  

int main()  
{  
	scanf("%d %d", &n, &r);  
	DFS(0, 0);  
	while(1);
} 