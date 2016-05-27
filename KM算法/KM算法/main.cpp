// 题目：http://acm.hdu.edu.cn/showproblem.php?pid=2255

#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
//赤裸裸的模板啊。。
const int maxn = 301;
const int INF = (1<<31)-1;
int w[maxn][maxn];
int lx[maxn],ly[maxn]; //顶标
int linky[maxn];
int visx[maxn],visy[maxn];
int slack[maxn];
int n;
bool find(int x){
	visx[x] = true;
	for(int y = 1; y <=n; y++)
	{
		if(visy[y])
			continue;
		int t = lx[x] + ly[y] - w[x][y];
		if(t==0)
		{
			visy[y] = true;
			if(linky[y]==-1 || find(linky[y]))
			{
				linky[y] = x;
				return true;        //找到增广轨
			}
		}
		else if(slack[y] > t)
			slack[y] = t;
	}
	return false;                   //没有找到增广轨（说明顶点x没有对应的匹配，与完备匹配(相等子图的完备匹配)不符）
}

int KM1()                //返回最优匹配的值
{
	int i,j;

	memset(linky,-1,sizeof(linky));
	memset(ly,0,sizeof(ly));
	for(i = 1; i <=n; i++){
		lx[i] = -INF;
		for(j = 1; j <=n; j++)
			if(w[i][j] > lx[i])
				lx[i] = w[i][j];
	}

	for(int x = 1; x <=n; x++){
		for(i = 1; i <=n; i++)
			slack[i] = INF;
		while(true){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			//memset(slack,INF,sizeof(slack));
			if(find(x))                     //找到增广轨，退出
				break;
			int d = INF;
			for(i = 1; i <=n; i++){          //没找到，对l做调整(这会增加相等子图的边)，重新找
			
				if(!visy[i] && d > slack[i])
					d = slack[i];
			}
			for(i = 1; i <=n; i++){
				if(visx[i])
					lx[i] -= d;
			}
			for(i = 1; i <=n; i++){
				if(visy[i])
					ly[i] += d;
			//	else
			//		slack[i] -= d;
			}
		}
	}
	int result = 0;
	for(i = 1; i <=n; i++)
		if(linky[i]>-1)
			result += w[linky[i]][i];
	return result;
}

int main1(){
	// freopen("g:/1.txt","r",stdin);

	while(scanf("%d",&n)==1){
		int cost;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				scanf("%d",&cost);
				w[i][j]=cost;
			}
			printf("%d\n",KM1());
	}
	return 0;
}