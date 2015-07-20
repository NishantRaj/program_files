#include <bits/stdc++.h>
using namespace std;
bool compare (const pair<long long , long long> &a , const pair<long long , long long> &b)
{
	return a.second < b.second;
}
int main()
{
	long long n , r , avg ;
	cin>> n >> r >> avg;
	vector<pair<long long  , long long> > v;
	long long sum = 0, total = 0 , count = 0;
	for(int i = 0 ; i< n ; i++)
	{
		int a , b;
		cin>>a>>b;
		v.push_back(make_pair(a , b));
		sum += a;
	}
	sort(v.begin() , v.end() , compare);
	long long  need = avg * n - sum , i=0;
	while(total < need)
	{
		long long a = v[i].first ; 
		long long b = v[i].second;
		if(a < r){
			long long nee = need - total;
			nee = min(nee , r - a);
			total += nee;
			count+= nee*b;
		}
		i++;
	}
	cout<<count<<endl;
	return 0;
}