#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int SA[100009] , tree[100009] , rank[20][100009];
struct tuple{
	int left , right , pos;
};
bool compare(const tuple &a , const tuple &b)
{
	return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void suffixArray(char s[] , int n)
{
	tuple t[n+9];
	for(int i = 0 ; i < n  ; i++)
		rank[0][i] = s[i] - 97;
	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; stp ++ , cnt <<=1)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			t[i].left = rank[stp-1][i];
			t[i].right = i + cnt < n ? rank[stp-1][i+cnt] : -1;
			t[i].pos = i;
		}
		sort(t , t+n , compare);
		for(int i = 0 ; i < n ; i++)
			rank[stp][t[i].pos] = i && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i-1].pos] : i;
	}
	int pos = ceil(log(n) / log(2));
	for(int i = 0 ; i < n ; i++)
		SA[rank[pos][i]] = i;
}
void lcpArray(char str[] , int n)
{
	int k = 0 , pos = ceil(log(n) / log(2));
	for(int i = 0 ; i < n ; i ++ , k?k--: 0)
	{
		if(rank[pos][i] == n - 1){ k = 0 ; continue ;}
		int j = SA[rank[pos][i]+1];
		while(i + k < n && j + k < n && s[i]+k] == s[j+k]) k++;
		lcp[rank[pos][i] + 1] = k;
	}
}
