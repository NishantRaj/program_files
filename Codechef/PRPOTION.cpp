#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int R,G,B,M;
		cin>>R>>G>>B>>M;
		long long r[109],g[109],b[109];
		vector<long long> v;
		long long ma = -1;
		for(int i=0;i<R;i++)
		{
			cin>>r[i];
			ma = max(ma,r[i]);
		}
		v.push_back(ma);
		ma = -1;
		for(int i=0;i<G;i++)
		{
			cin>>g[i];
			ma = max(ma,g[i]);
		}
		v.push_back(ma);
		ma = -1;
		for(int i=0;i<B;i++)
		{
			cin>>b[i];
			ma = max(ma,b[i]);
		}
		v.push_back(ma);
		sort(v.begin(),v.end());
		long long  res = v[2],mi = v[2];
		while(M--)
		{
			v[2]/=2;
			sort(v.begin(),v.end());
			res = v[2];
			mi  = min(mi , res);
		}
		cout<<mi<<endl;
	}
	return 0;
}