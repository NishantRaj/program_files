#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
bool compare(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first == b.first ? a.second < b.second : a.first < b.first ;
}
bool cmp1(const pair<int,int> &a,const int &b)
{
	return a.first < b;
}
bool cmp2(const pair<int,int> &a,const int &b)
{
	return a.second < b;
}
int main()
{
	int n,a,b,k;
	cin>>n>>k;
	vector<pair<int ,int> > v;
	int points[n+9];
	for(int i=0;i<n;i++)
		cin>>points[i];
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		if(a<b)
			v.PB(MP(a,b));
		else
			v.PB(MP(b,a));
	}
	sort(v.begin(),v.end(),compare);
	int x[n+9],y[n+9];
	for(int i=0;i<k;i++)
	{
		x[i] = v[i].first;
		y[i] = v[i].second;
	}
	for(int i=0;i<n;i++)
	{
		int start = lower_bound(x,x+k,points[i]) -x;
		int end = upper_bound(x,x+k,points[i]) - x;
		int first = lower_bound(y,y+start,points[i]) - y;
		//if(x[first] <= points[i] && )
		cout<<start<<"  "<<first<<"  "<<end<<endl;
	}
	return 0;
}