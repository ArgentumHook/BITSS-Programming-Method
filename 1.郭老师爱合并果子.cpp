#include<stdio.h>
#include<stdlib.h>
long long a[1000010];
int main()
{
    long long sum=0,ans=0,n,i,h,r,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
	{
        scanf("%lld",&a[i]);
         r=i;
        while(r>1&&a[r]<a[r/2])
		{
            h=a[r];
            a[r]=a[r/2];
            a[r/2]=h;
            r/=2;
        }
    }
    int len=n;
    for(i=1;i<n;i++)
	{
        sum=a[1];
        a[1]=a[len];
        len--;
        r=1;
        while((r*2<=len&&a[r]>a[r*2])||(r*2+1<=len&&a[r]>a[r*2+1]))
		{
            j=r*2;
            if(j+1<=len&&a[j]>a[j+1])j++;
            h=a[r];
            a[r]=a[j];
            a[j]=h;
            r=j;
        }
        sum+=a[1];
        a[1]=a[len];
        len--;
        r=1;
        while((r*2<=len&&a[r]>a[r*2])||(r*2+1<=len&&a[r]>a[r*2+1]))
		{
            j=r*2;
            if(j+1<=len&&a[j]>a[j+1])j++;
            h=a[r];
            a[r]=a[j];
            a[j]=h;
            r=j;
        }
        ans+=sum;
        a[++len]=sum;
        r=len;
        while(r>1&&a[r]<a[r/2])
		{
            h=a[r];
            a[r]=a[r/2];
            a[r/2]=h;
            r/=2;
        }
    }
    printf("%lld\n",ans);
}
