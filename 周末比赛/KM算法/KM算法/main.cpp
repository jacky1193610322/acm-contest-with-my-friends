#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include "minmax.h"
#define M 505
#define inf 0x3fffffff
bool sx[M], sy[M];
int match[M], w[M][M], n, m, d, lx[M], ly[M];
//n：左集元素个数； m：右集元素个数
void init ()
{
	memset (w, 0, sizeof(w));    //不一定要，求最小值一般要初始化为负无穷！
}

bool dfs (int u)
{
	int v; sx[u] = true;
	for (v = 0; v < m; v++)
	{
		if (!sy[v] && lx[u]+ly[v]==w[u][v])
		{
			sy[v] = true;
			if (match[v] == -1 || dfs (match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int KM ()
{
	int i, j, k, sum = 0;
	memset (ly, 0, sizeof(ly));
	for (i = 0; i < n; i++)
	{
		lx[i] = -inf;
		for (j = 0; j < m; j++)
			if (lx[i] < w[i][j])
				lx[i] = w[i][j];
	}
	memset (match, -1, sizeof(match));
	for (i = 0; i < n; i++)
	{
		while (1)
		{
			memset (sx, false, sizeof(sx));
			memset (sy, false, sizeof(sy));
			if (dfs (i))
				break;
			d = inf;
			for (j = 0; j < n; j++)
				if (sx[j])
					for (k = 0; k < m; k++)
						if (!sy[k])
							d = min (d, lx[j]+ly[k]-w[j][k]);
			if (d == inf)    //找不到完美匹配
				return -1;
			for (j = 0; j < n; j++)
				if (sx[j])
					lx[j] -= d;
			for (j = 0; j < m; j++)
				if (sy[j])
					ly[j] += d;
		}
	}
	
	return sum;
}

#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

int main()
{
	freopen("input.txt","r",stdin);
	
	while(scanf("%d%d",&n,&m)==2)
	{
		int cost;
		for(int i = 0; i < n; ++i)  
			for(int j = 0; j < n; ++j)  
				w[i][j] = -inf;
		for(int i=1;i<=m;i++){
			int from,to,k;
			scanf("%d%d",&from,&to);
			scanf("%d",&k);
			if(-k>w[from-1][to-1])
				w[from-1][to-1] = -k;
		}
		m = n;
		int flag = true;
		int ans = 0;
		for(int i = 1; i <= n; ++i) //是否有完美匹配  
		{  
			if(match[i] == -1 || map[ match[i] ][i] == -MAXN)  
			{  
				flag = false;  
				break;  
			}  
			ans += w[match[i]][i];  
		}  
		if(flag)  
			printf("%d\n", -ans);  
		else  
			printf("-1\n"); 
		//printf("%d\n",KM());
	}
	return 0;
}