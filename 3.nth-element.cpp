#include<stdio.h>
#include<stdlib.h>
int n,a[1000005],b[1000005],op,q,p,x,L,R,k;
int nth_elem(int *a,int low,int high,int n)
{
    int i=low,j=high-1,t;
    t=(high-low)/2+low;
   
    t=a[low];
    while(i!=j)
    {
        while(a[j]>=t&&i!=j)
			j--;
        if(i!=j)
		{
			a[i]=a[j];
			i++;
		}
        while(a[i]<t&&i!=j)
			i++;
        if(i!=j)
		{
			a[j]=a[i];
			j--;
		}
    }
    a[i]=t;
    for(j=i+1;j<high&&a[j]==a[i];j++);
    int t1=i-low,t2=j-i;
    if(t1>=n)
        return nth_elem(a,low,i,n);
    n-=t1;
    if(t2>=n)
        return a[i+n-1];
    return nth_elem(a,j,high,n-t2);
}
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
			scanf("%d%d%d",&L,&R,&k);
			for(i=0;i<=R-L;i++)
				b[i]=a[i+L];
			printf("%d\n",nth_elem(b,0,R-L+1,k));
		}
	}
	return 0;
}
