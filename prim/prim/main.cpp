#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 110
int map[MAXN][MAXN], lowcost[MAXN];
bool visit[MAXN];
int path[MAXN];
int nodenum, sum;

void prim(int n)
{
	int temp, k;
	sum = 0;
	memset(visit, false, sizeof(visit)); //初始化visit
	memset(path, -1, sizeof(path)); //初始化visit
	visit[1] = true;
	for(int i = 1; i <= nodenum; ++i) {//初始化lowcost[i]
		lowcost[i] = map[n][i];
		if(lowcost[i] == INF) //底下的if else 就是相等于
								/*for(int j = 1; j <= nodenum; ++j) //更新lowcost数组
								if(!visit[j] && lowcost[j] > lowcost[k] + map[k][j]){//这一步是可以的
									//要不要判断lowcost[k]是不是无穷大 因为如果它是无穷大  那么+map[k][j]
									//就会越界，为什么lowcost[k] 不会为无穷大  首先 k初值不会为无穷大
									//还有k只会在if(!visit[j] && temp > lowcost[j]) 里面更新 当lowcost为无穷大大时
									//不会进入if条件判断  所以不会  那么底下的+map[k][j]就不会超过INF
									lowcost[j] = lowcost[k] + map[k][j];
									path[j] = k;
								}*/  //因为当我选择了一开始的顶点也是要更新lowcost的所以需要更新path

								//记住一个那边更新lowcost 那边更新path
			path[i] = -1;
		else
			path[i] = n;
	}
	lowcost[n] = 0;
	k = n;
	for(int i = 1; i <= nodenum; ++i)//找生成树集合点集相连最小权值的边
	{
		temp = INF;
		for(int j = 1; j <= nodenum; ++j)
			if(!visit[j] && temp > lowcost[j]) //这边一定要是大于 而不能是大于等于  因为如果这样  当lowcost为INF 的时候也会更新 
											   //造成visit[k] = true  而事实是这个不能加入
				temp = lowcost[k = j];
		//if(temp == INF) break; //判断这点是否是n点可达
		visit[k] = true; //加入最小生成树集合
		sum += temp;//记录权值之和
		for(int j = 1; j <= nodenum; ++j) //更新lowcost数组
			if(!visit[j] && lowcost[j] > lowcost[k] + map[k][j]){//这一步是可以的
																//要不要判断lowcost[k]是不是无穷大 因为如果它是无穷大  那么+map[k][j]
																//就会越界，为什么lowcost[k] 不会为无穷大  首先 k初值不会为无穷大
																//还有k只会在if(!visit[j] && temp > lowcost[j]) 里面更新 当lowcost为无穷大时
																//不会进入if条件判断  所以不会  那么底下的+map[k][j]就不会超过INF
				lowcost[j] = lowcost[k] + map[k][j];
				path[j] = k;
			}
	}
}

void Print_Path(int n,int x)
{
	stack<int> s;
	int w=x;
	s.push(w);
	while(path[w]!=-1)
	{
		w=path[w];
		s.push(w);
	}
	
	cout<<"顶点"<<n<<"到顶点"<<x<<"的最短路径长度为："<<lowcost[x]<<endl;
	cout<<"所经过的路径为：";
	while(!s.empty())
	{
		cout<<s.top()<<"";
		s.pop();
	}
	cout<<endl;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a, b, cost, edgenum;
	
	//cin>>edgenum>>nodenum;
	scanf("%d%d", &edgenum, &nodenum);
	while(1)
	{
		memset(map, INF, sizeof(map));
		for(int i = 1; i <= edgenum; ++i) //输入边的信息
		{
			scanf("%d%d%d", &a, &b, &cost);			
			map[a][b]  = cost;
		}
		int n = 1;
		prim(n);
		for(int i=1;i<=nodenum;i++){
			if(i!=n){
				Print_Path(n,i);
			}
		}
		//printf("%d\n", sum); //最小生成树权值之和
		while(1);
	}
	return 0;
}