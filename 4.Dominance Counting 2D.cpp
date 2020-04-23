#include<stdio.h>
#include<stdlib.h>
#define N 100005
typedef struct node
{
	int x;
	int y;
	int unix;
	int id;
	int ans;
}point;
typedef struct temp
{
	int val;
	int id;
}Temp;
point p[N];
Temp a[N];
int n,unia[N],sum[N];
int cmp1(const void *a,const void *b)
{
	Temp A=*(struct temp *)a;
    Temp B=*(struct temp *)b;
    return A.val-B.val;
}
int cmp2(const void *a,const void *b)
{
    point A=*(struct node *)a;
    point B=*(struct node *)b;
	if(A.y!=B.y)
		return A.y-B.y;
	return A.x-B.x;
}
int cmp3(const void *a,const void *b)
{
    point A=*(struct node *)a;
    point B=*(struct node *)b;
	return A.id-B.id;
}
int cmp4(const void *a,const void *b)
{
    point A=*(struct node *)a;
    point B=*(struct node *)b;
    if(A.y!=B.y)
		return A.y-B.y;
	else if (A.x!=B.x)
		return A.x-B.x;
	return B.ans-A.ans;
}
int lowbit(int index)
{
    return index&(-index);
}
void update(int index,int d)
{
    while(index<=n)
    {
        sum[index]=sum[index]+d;
        index=index+lowbit(index);
    }
}
int getsum(int index)
{
    int res=0;
    while(index>0)
    {
        res=res+sum[index];
        index=index-lowbit(index);
    }
    return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
		p[i].ans=0;
		a[i].val=p[i].x;
		a[i].id=i;
		unia[i]=0;
	}
	qsort(a,n,sizeof(a[0]),cmp1);
	unia[a[0].id]=1;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i].val==a[i-1].val)
			unia[a[i].id]=unia[a[i-1].id];
		else
			unia[a[i].id]=++cnt;
	}
	for(int i=0;i<n;i++)
		p[i].unix=unia[p[i].id];
	qsort(p,n,sizeof(p[0]),cmp2);
	for(int i=0;i<n;i++)
	{
		update(p[i].unix,1);
		p[i].ans=getsum(p[i].unix);
	}
	qsort(p,n,sizeof(p[0]),cmp4);
	for(int i=0;i<n-1;i++)
	{
		if(p[i].x==p[i+1].x&&p[i].y==p[i+1].y)
			p[i+1].ans=p[i].ans;
	}
	qsort(p,n,sizeof(p[0]),cmp3);
	for(int i=0;i<n;i++)
		printf("%d\n",p[i].ans);
    return 0;
}
