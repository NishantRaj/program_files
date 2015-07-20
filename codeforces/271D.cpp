#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long
int main()
{
	int t,k;
	cin>>t>>k;
	LL cum[100009];
	LL res[100009];
	memset(cum,0,100009);
	memset(res,0,100009);
	res[0] = 1;
	cum[0] = 0;
	for(int i = 1;i<=100000;i++)
	{
		if(i>=k)
		{
			res[i] = (res[i-1] + res[i-k])%MOD;
			cum[i] = (cum[i-1] + res[i])%MOD;
		}
		else
		{
			res[i] = res[i-1]%MOD;;
			cum[i] = (cum[i-1] + res[i])%MOD;
		}
	}
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<(cum[b] - cum[a-1] + MOD )%MOD<<endl;
	}
	return 0;
}