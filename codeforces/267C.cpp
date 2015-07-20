#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 5001
LL memo[MAXN];
int n, a[MAXN];
LL solve(int x)
{
	if (x >= n)return 0;
	if (memo[x] != -1)
		return memo[x];
	LL sum = a[x];
	for(int i = x+1; i<n; i++)
	{
		sum = 
	}
}