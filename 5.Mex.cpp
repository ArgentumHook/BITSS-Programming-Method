#include<stdio.h>
#include<string.h>
#define maxn 1000005
int a[maxn],b[maxn],f[maxn];
int n,q,p,x,L,R,op;
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&p,&x);
			a[p]=x;
		}
		else if(op==2)
		{
			scanf("%d%d",&L,&R);
			for(i=L;i<=R;i++)
				b[i-L]=a[i];
			for(i=1;i<=n+1;i++)
				f[i]=0;
			for(i=0;i<=R-L;i++)
				if(b[i]>=1&&b[i]<=n+1)
					f[b[i]]=1;
			for(i=1;i<=n+1;i++)
			{
				if(f[i]==0)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
