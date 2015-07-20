#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MAX 100000
int tree[100009];
void update(int pos)
{
	while(pos)
	{
		tree[pos] += 1;
		pos -=(pos & -pos);
	}
}
int read(int pos)
{
	int res = 0;
	while(pos <= MAX)
	{
		res += tree[pos] ;
		pos +=(pos & -pos);
	}
	return res;
}
vector<int> z_function(char s[] , int n)
{
	int l = 0  , r = 0;
	vector<int> v(n+9);
	v[0] = n;
	update(n);
	for(int i = 1 ; i < n ; i++)
	{
		if(i <= r)
			v[i] = min(r - i + 1 , v[i - l]);
		while(i + v[i] < n && s[v[i]] == s[i+v[i]])
			v[i]++;
		if(i + v[i] - 1 > r)
			l = i , r = i + v[i] -1;
		update(v[i]);
	}
	return v;
}
int main()
{
	char s[100009];
	scanf("%s",s);
	int n = strlen(s);
	vector<int > v;
	vector<pair<int , int> > res;
	v = z_function(s , n);
	int count = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(v[i] == n - i)
		{
			count++;
			int occur = read(v[i]);
			res.push_back(make_pair(v[i] , occur));
		}
	}
	sort(res.begin() , res.end());
	cout<<count<<endl;
	for(int i = 0 ; i < count ; i ++)
		cout<<res[i].first<<" "<<res[i].second<<endl;
	return 0;
}