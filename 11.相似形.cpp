#include<stdio.h>
#include<string.h>
#define maxn 1005
char s1[maxn], s2[maxn];
int dp[maxn][maxn];

int min(int a, int b)
{
	if (a >= b)
		return b;
	return a;
}

int main()
{
	scanf("%s", s1);
	scanf("%s", s2);
	int m = strlen(s1);
	int n = strlen(s2);
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++)
		dp[i][0] = i;
	for (int i = 1; i <= n; i++)
		dp[0][i] = i;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
	printf("%d\n", dp[m][n]);
	return 0;
}
