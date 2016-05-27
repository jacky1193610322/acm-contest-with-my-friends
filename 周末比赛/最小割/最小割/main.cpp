#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define NN 504
#define INF 1 << 30
int vis[NN];
int wet[NN];
int combine[NN];
int map[NN][NN];

int S, T, minCut, N;
void Search(){
	int i, j, Max, tmp;
	memset(vis, 0, sizeof(vis));
	memset(wet, 0, sizeof(wet));
	S = T = -1;
	for (i = 0; i < N; i++){
		Max = -INF;
		for (j = 0; j < N; j++){
			if (!combine[j] && !vis[j] && wet[j] > Max){
				tmp = j;
				Max = wet[j];
			}
		}
		//这在第n-1时说明  上面的for循环没有改变任何值了  因为每次合并一个点的时候 相当于图中的点已经少了一个了
		//因为合并了吗  所以 准确来说 上面的for循环  的N变小一个
		if (T == tmp) return;
		S = T; T = tmp;
		minCut = Max;
		vis[tmp] = 1;
		for (j = 0; j < N; j++){
			if (!combine[j] && !vis[j]){
				wet[j] += map[tmp][j];
			}
		}
	}
}
int Stoer_Wagner(){
	int i, j;
	memset(combine, 0, sizeof(combine));
	int ans = INF;
	for (i = 0; i < N - 1; i++){
		Search();
		if (minCut < ans) ans = minCut;
		if (ans == 0) return 0;
		combine[T] = 1;
		for (j = 0; j < N; j++){
			if (!combine[j]){
				map[S][j] += map[T][j];
				map[j][S] += map[j][T];
			}
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int a, b, c, M;
	while(scanf("%d%d", &N, &M) != EOF){
		memset(map, 0, sizeof(map));
		while(M--){
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] += c;
			map[b][a] += c;
		}
		printf("%d\n", Stoer_Wagner());
	}
	//while(1);
	return 0;
}