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
	for(int i = num+1; i <= n; i++)//  ����ǲ����ظ�  ��ô��num+1  ����ǿ��ظ�ȡ  ��Ԫ���ǲ����ظ���  ��i = num  
		DFS(i, step + 1);  
}  

int main()  
{  
	scanf("%d %d", &n, &r);  
	DFS(0, 0);  
	while(1);
} 