#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>  
#include <algorithm>  
using namespace std;  

int main()  
{  
	int n, m, a[25], b[25];  
	scanf("%d %d", &n, &m);  
	memset(a, 1, sizeof(a));  
	memset(b, 0, sizeof(b));  
	for(int i = 0; i < m; i++)  
		a[i] = 0;  
	for(int i = 0; i < n; i++)  
		b[i] = i + 1;  
	for(int i = 0; i < m; i++)  
		printf("%3d", b[i]);  
	printf("\n");  
	while(next_permutation(a, a + n))  
	{  
		for(int i = 0; i < n; i++)  
			if(!a[i])  
				printf("%3d", b[i]);  
		printf("\n");  
	}  
	while(1);
}  