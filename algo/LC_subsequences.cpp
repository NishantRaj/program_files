#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int SA[MAX] , rank[20][MAX] , lcp[MAX];
struct tuple
{
	int left,right,pos;
};
void counting_sort(tuple t[] , int n)
{
	int count[MAX];
	tuple temp[n+9];
	memset(count , 0 , sizeof count);
	for(int i = 0; i<n;i++)
		count[t[i].right + 1] ++;
	for(int i = 1 ; i < MAX ; i++)
		count[i] +=count[i-1];
	for(int i = 0 ; i < n ; i++)
	{
		temp[count[t[i].right + 1] - 1] = t[i];
		count[t[i].right + 1]--;
	}
	memset(count , 0 , sizeof count);
	for(int i = 0 ; i < n ; i++)
		count[t[i].left + 1] ++;
	for(int i = 1 ; i < MAX ; i++)
		count[i] +=count[i-1];
	for(int i = n-1 ; i >=0 ; i--)
	{
		t[count[temp[i].left + 1] - 1] = temp[i];
		count[temp[i].left + 1]--;
	}
}
void suffixArray(int s[] , int n )
{
	for(int i = 0 ; i < n ; i ++)
		rank[0][i] = s[i] + 100;
	tuple t[n+9];
	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
	{
		for(int i = 0 ; i  < n ; i++)
		{
			t[i].left = rank[stp - 1][i]; 
			t[i].right  = i + cnt < n ? rank[stp-1][i + cnt] : -1;
			t[i].pos  = i;
		}
		counting_sort(t,n);
		for(int i = 0 ; i < n ; i++)
			rank[stp][t[i].pos] = i > 0 && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i-1].pos] : i;
	}
	int pos = ceil(log(n) / log(2));
	for(int i = 0 ; i<n;i++)
		SA[rank[pos][i]] = i; 
}
void LCP(int a[] , int n)
{
	int rnk[n+9];
	for(int i = 0 ; i < n ; i ++) rnk[SA[i]] = i;
	for(int i = 0 , k = 0 ; i < n ; i++ , k?k--:0)
	{
		if(rnk[i] == n-1){
			k = 0;
			continue;
		}
		int j = SA[rnk[i] + 1];
		while(i+k < n && j+k < n && a[i+k] == a[j+k]) k++;
		lcp[rnk[i] + 1] = k;
	}
}
int main()
{
	int n , m , temp;
	cin>>n>>m;
	int a[500] , b[200];
	for(int i = 0 ; i < n ; i++)
		cin>>a[i];
	for(int i = 0; i < m ; i++)
		cin>>b[i];
	a[n] = 101;
	for(int i = n+1 ; i <= n+m ; i++)
		a[i] = b[i-n-1];
	int len = n+m + 1;
	suffixArray(a,len);
	LCP(a,len);
	int ma = -1;
	for(int i = 1 ; i < len ; i++)
	{
		if((SA[i-1] > n && SA[i] < n) || (SA[i-1] < n && SA[i] > n))
			ma = max(ma , lcp[i]);
	}
	cout<<ma<<endl;
}