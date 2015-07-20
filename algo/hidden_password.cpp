#include <bits/stdc++.h>
using namespace std;
#define MAX 200009
int SA[200009] , rank[20][MAX];
struct tuple
{
	int left , right , pos;
};
bool compare(const tuple &a , const tuple &b)
{
	return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void counting_sort(tuple t[] , int n)
{
	int count[MAX+9];
	tuple temp[n + 9];
	memset(count , 0 , sizeof count);

	for(int i = 0 ;i < n ; i++)
		count[t[i].right + 1]++;

	for(int i = 1 ; i  < MAX ; i++)
		count[i] += count[i-1];

	for(int i = 0 ; i<n ; i++)
	{
		temp[count[t[i].right +1] - 1] = t[i];
		count[t[i].right + 1]--;
	}	

	memset(count , 0 , sizeof count);

	for(int i = 0 ; i < n ; i ++)
		count[t[i].left + 1] ++;

	for(int i = 1 ; i<MAX ; i++)
		count[i] += count[i-1];

	for(int i = n- 1; i>=0 ; i--)
	{
		t[count[temp[i].left + 1] - 1] = temp[i];
		count[temp[i].left + 1]--;
	}
}
void suffixArray(string s)
{
	int n = s.length();

	tuple t[n+9];
	for(int i = 0 ; i<n ; i++)
		rank[0][i] = s[i] - 97;
	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
	{
		for(int i = 0 ; i< n ;i++)
		{
			t[i].left = rank[stp-1][i];
			t[i].right = i + cnt < n ? rank[stp - 1][i+cnt] : 200001;
			t[i].pos = i;
		}
		counting_sort(t,n);
		for(int i = 0 ; i < n ; i ++)
			rank[stp][t[i].pos] = i>0 && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i-1].pos] : i;
	}
	int pos = ceil(log(n) / log(2));
	for(int i = 0 ; i<n ; i++)
		SA[rank[pos][i]] = i;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		s = s + s;
		memset(SA,0,sizeof SA);
		memset(rank , 0 , sizeof(rank[0][0])*20*MAX);
		suffixArray(s);
		cout<<SA[0]<<endl;
	}
	return 0 ;
}