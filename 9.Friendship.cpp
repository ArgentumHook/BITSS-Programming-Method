#include<stdio.h>
#define N 55
int map[N][N],color[N],res[N],black[N];
int nodeNum,edgeNum,Max,x,beg,end;
int dfs(int *u,int dep,int tot)
{
	int k,t[N];
	if(tot==0)
	{
		if(Max<dep)
		{
			Max=dep;
			for(int i=0;i<x;i++)
				black[i]=res[i];
			return 1;
		}
		return 0;
	}
	for(int i=0;i<tot;i++)
	{
		if(dep+tot-i<=Max)
			return 0;
		if(dep+color[u[i]]<=Max)
			return 0;
		k=0;
		res[x++]=u[i];
		for(int j=i+1;j<tot;j++)
		{
			if(map[u[i]][u[j]]!=0)
				t[k++]=u[j];
		}
		if(dfs(t,dep+1,k)!=0)
			return 1;
		x--;
	}
	return 0;
}
int main()
{
	int i,j,k,u[N];
	for(i=0;i<N;i++)
		color[i]=0;
	scanf("%d%d",&nodeNum,&edgeNum);
	for(i=1;i<=nodeNum;i++)
	{
		map[i][i]=0;
		for(j=i+1;j<=nodeNum;j++)
		{
			map[i][j]=1;
			map[j][i]=1;
		}
	}
	for(i=1;i<=edgeNum;i++)
	{
		scanf("%d%d",&beg,&end);
		map[beg][end]=0;
		map[end][beg]=0;
	}
	Max=0;
	for(i=nodeNum;i>=1;i--)
	{
		k=0;
		x=0;
		for(j=i+1;j<=nodeNum;j++)
		{
			if(map[i][j]!=0)
				u[k++]=j;
		}
		res[x++]=i;
		dfs(u,1,k);
		color[i]=Max;
	}
	printf("%d\n",Max);
	return 0;
}
