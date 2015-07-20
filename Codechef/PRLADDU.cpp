#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n+9];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int sum = 0;
		long long dist = 0;
		sum = arr[0];
		for(int i=1;i<n;i++)
		{
			dist+=abs(sum);
			sum+=arr[i];
		}
		printf("%lld\n",dist);
	}
	return 0;
}