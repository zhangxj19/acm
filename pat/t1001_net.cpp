#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)
#define INF 0x7FFFFFFF
 
int gra[505][505],cost[505],dis[505];
bool vis[505];
int N, M;
 
void mintree(int v)  //最小生成树，Prim算法
{
	memset(vis, 0, N + 1);
	int i,next,r = N - 2,s=v==N?1:v+1; //找除去该点的其他点作为起点，
	for (i = 1; i <= N; ++i)dis[i] = gra[s][i];
	vis[v] = vis[s] = 1;
	while (r--) {
		int min = INF;
		for (i = 1; i <= N; ++i) {
			if (!vis[i] && min > dis[i]) {
				min = dis[i];
				next= i;
			}
		}
		if (min == INF) {  //该点原来就没有路，无法达到其他点
			cost[v] = INF;
			break;
		}
		cost[v] += min;vis[next]=1;
		for (i = 1; i <= N; ++i) {  //更新集合到未被访问的点的最短路径
			if (!vis[i]&&gra[next][i] < dis[i])dis[i] = gra[next][i];
		}
	}
}
 
int main()
{
	freopen("in", "r", stdin);
	int i, j, maxcost=0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j)
			gra[i][j] = INF;
	}
	while (M--) {
		int c1, c2, c, s;
		scanf("%d %d %d %d", &c1, &c2, &c, &s);
		if (s)gra[c1][c2] = gra[c2][c1] = 0;
		else gra[c1][c2] = gra[c2][c1] = c;
	}
	for (i = 1; i <= N; ++i) {
		cost[i] = 0; mintree(i);
		if (cost[i] > maxcost)maxcost = cost[i];
	}
	if (maxcost == 0)printf("0");
	else {
		bool flag = 0;
		for (i = 1; i <= N; ++i) {
			if (cost[i] == maxcost) {
				printf("%s%d", flag ? " " : "", i);
				flag = 1;
			}
		}
	}
    printf("\n");
	return 0;
}