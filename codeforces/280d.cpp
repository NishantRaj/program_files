#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
LL gcd(LL a , LL b)
{
	return b == 0? a : gcd(b , a%b);
}
int main()
{
	LL n , x , y , com = 0;
	cin>>n>>x>>y;
	long long arr[n+9];
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	vector<pair<LL , int> > v;
	LL up = (x*y) / gcd(x , y);
	for(LL i = x; i < up ; i+=x)
	{
		com ++;
		v.PB(MP(i,1));
	}
	for(LL i = y ; i< up ;i+=y){
		com++;
		v.PB(MP(i,0));
	}
	v.PB(MP(up , 2));
	v.PB(MP(up , 2));
	com+=2;
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++)
	{
		LL pos = (arr[i])% com;
		if( x == y)
			cout<<"Both\n";
		else if(pos == 0 || pos == com-1)
			cout<<"Both\n";
		else
		{
			pos -- ;
			if(v[pos].second == 1)
				cout<<"Vova\n";
			else if(v[pos].second == 0)
				cout<<"Vanya\n";
		}
	}
	return 0;
}