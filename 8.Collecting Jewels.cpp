#include<stdio.h>
#include<string.h>
#define maxn 25
#define N 1<<20
int state[N],map[maxn][maxn];
int n,m,k,flag,result=0;

int check(int x,int y);
void dfs1(int x,int y,int vis1,int num1);
void dfs2(int x,int y,int vis2,int num2);

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	int t1,t2;
	t1=k/2,t2=k-t1;
	flag=t2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			memset(state,0,sizeof(state));
			dfs1(i,j,0,t1);
			dfs2(i,j,0,t2);
		}
	}
	printf("%d\n",result);
	return 0;
}


int check(int x,int y)
{
	if(x<1||x>n||y<1||y>m)
		return 0;
	return 1;
}

void dfs1(int x,int y,int vis1,int num1)
{
	if(!check(x,y))
		return;
	if(vis1&(1<<(map[x][y]-1)))
		return;
	else
	{
		vis1+=1<<(map[x][y]-1);
		if(num1==1)
		{
			state[vis1]++;
			return;
		}
		num1--;
		dfs1(x,y+1,vis1,num1);
		dfs1(x,y-1,vis1,num1);
		dfs1(x+1,y,vis1,num1);
		dfs1(x-1,y,vis1,num1);
	}

}

void dfs2(int x,int y,int vis2,int num2)
{
	if(!check(x,y))
		return;
	if(((1<<(map[x][y]-1))&vis2))
		return;
	if(num2==flag||!((1<<(map[x][y]-1))&vis2))
	{
		if(num2!=flag)
			vis2+=1<<(map[x][y]-1);
		if(!num2)
		{
			result+=state[vis2^((1<<k)-1)];
			return;
		}
		num2--;
		dfs2(x-1,y,vis2,num2);
		dfs2(x+1,y,vis2,num2);
		dfs2(x,y+1,vis2,num2);
		dfs2(x,y-1,vis2,num2);
	}
}
