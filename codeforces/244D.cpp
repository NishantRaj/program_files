#include <bits/stdc++.h>
using namespace std;
int rank[20][10009];
int SA[10009];
int lcp[10009];
struct tuple{
	int left , right , pos;
};
bool compare(const tuple &a , const tuple &b)
{
	return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void suffixArray(char str[] , int n)
{
	tuple t[n+9];
	for(int i = 0 ; i < n ; i++){
		if(str[i] == '#')
			rank[0][i] = 0;
		else
			rank[0][i] = str[i] - 96;
	}
	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			t[i].left = rank[stp-1][i];
			t[i].right = i + cnt < n ? rank[stp-1][i+cnt] : -1;
			t[i].pos  = i;
		}
		sort(t , t+n , compare);
		for(int i = 0 ; i < n ; i ++)
			rank[stp][t[i].pos] = i > 0 && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i-1].pos] : i;
	}
	int pos = ceil(log(n) / log(2));
	for(int i = 0 ; i < n ; i++)
		SA[rank[pos][i]] = i;
}
void lcpArray(char str[] , int n)
{
	int ran[n+9];
	for(int i = 0 ; i < n ; i++)
		ran[SA[i]] = i;
	int k = 0 ;
	lcp[0] = 0;
	for(int i = 0 ; i < n ; i++,k?k--:0)
	{
		if(ran[i] == n-1){k = 0 ; continue;}
		int j = SA[ran[i] + 1];
		while(i+k < n && j+k < n && str[i+k] == str[j+k]) k++;
		lcp[ran[i] + 1] = k;
	}
}
int  check(int first , int total )
{
	int res = 99999999;
	lcp[total] =0;
	for(int i = 1 ; i < total ; i++)
	{
		if((SA[i-1] > first && SA[i] < first ) || (SA[i-1] < first && SA[i] > first ))
		{
			if(max(lcp[i-1] , lcp[i+1]) + 1 <= lcp[i]){
				res = min(res , max(lcp[i-1] , lcp[i+1]) + 1);
			}
		}
	}
	return res;
}
int main()
{
	char  s[10009] , s1[5001];
	scanf("%s",s);
	scanf("%s",s1);
	int first = strlen(s);
	strcat(s , "#");
	strcat(s , s1); 
	int total = strlen(s);
	suffixArray(s , total);
	lcpArray(s , total);
	int res = check(first , total);
	if(res == 99999999)
		cout<<-1<<endl;
	else
		cout<<res<<endl;
	return 0;
}