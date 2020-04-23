#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	double x,y;
}point;
int N;
point p[100005];
double calulate(double x)
{
	double r=0;
	for(int i=0;i<N;i++)
		r=r>sqrt((x-p[i].x)*(x-p[i].x)+p[i].y*p[i].y)?r:sqrt((x-p[i].x)*(x-p[i].x)+p[i].y*p[i].y);
	return r;
}
double search(double left,double right)
{
	if(right-left>0.00001)
	{
		double t1=(2*left+right)/3;
		double t2=(left+2*right)/3;
		if(calulate(t1)>calulate(t2))
			search(t1,right);
		else
			search(left,t2);
	}
	else
		return calulate(left);
}
int main()
{
	double l=10000,r=-10000;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=0;i<N;i++)
	{
		if(r<=p[i].x)
			r=p[i].x;
		if(l>=p[i].x)
			l=p[i].x;
	}
	printf("%.4lf\n",search(l,r));
	return 0;
}
