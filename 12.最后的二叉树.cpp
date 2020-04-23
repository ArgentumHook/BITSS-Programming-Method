#include<stdio.h>
#include<string.h>
#define maxn 20005
typedef long long ll;
const int mod = 1e9+7;
ll fac[maxn] = {1}, n; 
 
ll qmod(ll x, ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p%2) 
			ans = ans*x%mod;
        x = x*x%mod;
        p /= 2;
    }
    return ans;
}
 
int main()
{
	ll res;
    for(int i = 1; i < maxn; i++)
        fac[i] = fac[i-1]*i%mod;
    while(~scanf("%d",&n))
    {
    	res=fac[2*n]*qmod(fac[n+1], mod-2)%mod*qmod(fac[n], mod-2)%mod;
        printf("%lld\n", res);
    }
    return 0;
}
