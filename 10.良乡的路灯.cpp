#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int N,L;
typedef struct node
{
	int p,d;
}light;
typedef struct Node
{
	int L,R;
}range;
light a[maxn];
range r[maxn];
int cmp(const void *a,const void *b)
{
	range A=*(struct Node*)a;
	range B=*(struct Node*)b;
	return A.L-B.L;
}
int main()
{
	int ans,index,end,flag;
	scanf("%d%d",&N,&L);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&a[i].p,&a[i].d);
		r[i].L=a[i].p-a[i].d<0?0:a[i].p-a[i].d;
		r[i].R=a[i].p+a[i].d>L?L:a[i].p+a[i].d;
	}
	qsort(r,N,sizeof(r[0]),cmp);
	//for(i=0;i<N;i++)
	//	printf("%d %d\n",r[i].L,r[i].R);
	ans=0,index=0,flag=1,end=0;
	while(end<L)
	{
		int start=end;
		for(int i=index;i<N;i++)
		{
			if(r[i].L<=start)
			{
				if(r[i].R>=start)
					end=r[i].R>=end?r[i].R:end;
			}
			else
			{
				index=i;
				break;
			}
		}
		if(start>=end)
		{
			flag=0;
			break;
		}
		else
			ans++;
	}
	if(flag)
		printf("%d\n",ans);
    else
		printf("-1\n");
	return 0;
}
