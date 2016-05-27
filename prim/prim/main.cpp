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
	memset(visit, false, sizeof(visit)); //��ʼ��visit
	memset(path, -1, sizeof(path)); //��ʼ��visit
	visit[1] = true;
	for(int i = 1; i <= nodenum; ++i) {//��ʼ��lowcost[i]
		lowcost[i] = map[n][i];
		if(lowcost[i] == INF) //���µ�if else ���������
								/*for(int j = 1; j <= nodenum; ++j) //����lowcost����
								if(!visit[j] && lowcost[j] > lowcost[k] + map[k][j]){//��һ���ǿ��Ե�
									//Ҫ��Ҫ�ж�lowcost[k]�ǲ�������� ��Ϊ������������  ��ô+map[k][j]
									//�ͻ�Խ�磬Ϊʲôlowcost[k] ����Ϊ�����  ���� k��ֵ����Ϊ�����
									//����kֻ����if(!visit[j] && temp > lowcost[j]) ������� ��lowcostΪ������ʱ
									//�������if�����ж�  ���Բ���  ��ô���µ�+map[k][j]�Ͳ��ᳬ��INF
									lowcost[j] = lowcost[k] + map[k][j];
									path[j] = k;
								}*/  //��Ϊ����ѡ����һ��ʼ�Ķ���Ҳ��Ҫ����lowcost��������Ҫ����path

								//��סһ���Ǳ߸���lowcost �Ǳ߸���path
			path[i] = -1;
		else
			path[i] = n;
	}
	lowcost[n] = 0;
	k = n;
	for(int i = 1; i <= nodenum; ++i)//�����������ϵ㼯������СȨֵ�ı�
	{
		temp = INF;
		for(int j = 1; j <= nodenum; ++j)
			if(!visit[j] && temp > lowcost[j]) //���һ��Ҫ�Ǵ��� �������Ǵ��ڵ���  ��Ϊ�������  ��lowcostΪINF ��ʱ��Ҳ����� 
											   //���visit[k] = true  ����ʵ��������ܼ���
				temp = lowcost[k = j];
		//if(temp == INF) break; //�ж�����Ƿ���n��ɴ�
		visit[k] = true; //������С����������
		sum += temp;//��¼Ȩֵ֮��
		for(int j = 1; j <= nodenum; ++j) //����lowcost����
			if(!visit[j] && lowcost[j] > lowcost[k] + map[k][j]){//��һ���ǿ��Ե�
																//Ҫ��Ҫ�ж�lowcost[k]�ǲ�������� ��Ϊ������������  ��ô+map[k][j]
																//�ͻ�Խ�磬Ϊʲôlowcost[k] ����Ϊ�����  ���� k��ֵ����Ϊ�����
																//����kֻ����if(!visit[j] && temp > lowcost[j]) ������� ��lowcostΪ�����ʱ
																//�������if�����ж�  ���Բ���  ��ô���µ�+map[k][j]�Ͳ��ᳬ��INF
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
	
	cout<<"����"<<n<<"������"<<x<<"�����·������Ϊ��"<<lowcost[x]<<endl;
	cout<<"��������·��Ϊ��";
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
		for(int i = 1; i <= edgenum; ++i) //����ߵ���Ϣ
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
		//printf("%d\n", sum); //��С������Ȩֵ֮��
		while(1);
	}
	return 0;
}