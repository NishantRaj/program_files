#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int SA[100009] , rank[20][100009] , lcp[100009] , cum[100009];
struct tuple{
	int left , right , pos;
};
void counting_sort(tuple t[] , int n)
{
	int count[MAX+9];
	tuple temp[n+9];
	for(int i = 0 ; i < n ; i++)
		count[t[i].right +1 ]++;
	for(int i = 1 ; i < MAX ; i++)
		count[i] += count[i-1];
	for(int i = 0 ; i < n ; i++)
	{
		temp[count[t[i].right + 1] - 1 ] = t[i];
		count[t[i].right +1 ] --;
	}
	memset(count , 0 , sizeof count);
	for(int i = 0 ; i < n ; i ++)
		count[t[i].left + 1] ++;
	for(int i = 1 ; i < MAX ; i++)
		count[i] += count[i-1];
	for(int i = n-1 ; i>=0 ; i--)
	{
		t[count[temp[i].left +1 ] -1] = temp[i];
		count[temp[i].left + 1]--;
	}
}
bool compare(const tuple &a , const tuple &b)
{
	return a.left == b.left ? a.right < b.right : a.left < b.left ;
}
void suffixArray(char s[] , int n)
{
	tuple t[n+9] ;
	for(int i = 0 ; i < n ; i++)
		rank[0][i] = s[i]-97 ;
	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			t[i].left = rank[stp-1][i];
			t[i].right = i+ cnt < n ? rank[stp-1][i+cnt] : -1;
			t[i].pos = i;
		}
		//counting_sort(t, n);
		sort(t , t+n , compare);
		for(int i = 0 ; i < n ; i++)
			rank[stp][t[i].pos] = i && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i].pos - 1] : i;
	}
	int pos = ceil(log(n) / log(2));
	for(int i = 0; i < n ; i++)
		SA[rank[pos][i]] = i;
}
void lcpArray(char s[] , int n)
{
	int k = 0 , pos = ceil(log(n) / log(2));
	for(int i = 0 ; i < n ; i++ , k?k--:0)
	{
		if(rank[pos][i] == n-1) { k = 0 ; continue;}
		int j = SA[rank[pos][i] + 1];
		while(i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
		lcp[rank[pos][i] + 1] = k;
	}
}
int main()
{
	char s[100009];
	cin>>s;
	int pos , n = strlen(s);
	cin>>pos;
	suffixArray(s , n);
	lcpArray(s , n);
	cum[0] = n  - SA[0];
	for(int i = 1 ; i < n ; i++)
		cum[i] = cum[i-1] + (n - SA[i]);
	if(cum[n-1] < pos)
	{
		cout<<"No such line.\n";
		return 0;
	}
	int posInCum = lower_bound(cum , cum + n , pos) - cum;
	int i , j;
	for(i = SA[posInCum] , j = 0 ; j < pos - cum[posInCum-1] ; j++ , i++)
		cout<<s[i];
	cout<<endl;
	return 0;
}