#include <bits/stdc++.h>
using namespace std;
#define MAX 40009
int SA[200009] , rank[20][MAX] , lcp[MAX];
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
			t[i].right = i + cnt < n ? rank[stp - 1][i+cnt] : -1;
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
void LCP(string s)
{
    int k=0,sum = 0 , n = s.length();
    vector<int> ran(n,0);
    for(int i=0; i<n; i++) ran[SA[i]]=i;
            lcp[0] = 0;
    for(int i=0; i<n; i++, k?k--:0)
    {
            if(ran[i]==n-1) {k=0; continue;}
            int j=SA[ran[i]+1];
            while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++ ;
            lcp[ran[i] + 1] = k;
    }
}
bool possible(int len , int count , int n)
{
	int total = 1 , ma = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(lcp[i] >= len) total++;
		else{
			ma = max(total , ma);
			total = 1;
		}
	}
	if(ma>= count)
		return true;
	else
		return false;
}
int b_search(int n ,int count)
{
	int low  = 1 , high = n , mid , pos = -1;
	while(low<=high)
	{
		mid = (low + high)>>1;
		if(possible(mid ,count ,  n)){
			pos = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return pos;
}
int max_right(int pos_len , int n , int req)
{
	int count = 1 , ma = SA[0] , result = -1;
	for(int i = 1 ; i <= n ; i ++)
	{ 
		if(lcp[i] >= pos_len)
			ma = max(ma,SA[i]) , count ++;
		else
		{
			if(count >= req)
				result = max(ma , result);
			ma = SA[i];
			count = 1;
		}
	}
	return result;
}
int main()
{
	int test ; 
	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		int count;
		cin>>count;
		int n = s.length();
		memset(SA,0,sizeof SA);
		memset(rank , 0 , sizeof(rank[0][0])*20*MAX);
		memset(lcp , 0 , sizeof lcp);
		suffixArray(s);
		LCP(s);
		int max_len = b_search(n , count);
		if(max_len == -1){
			cout<<"HATE\n";
			continue;
		}
		int res = max_right(max_len , n , count);
		if(count == 1)
			cout<<max_len<<" "<<0<<endl;
		else
			cout<<max_len<<" "<<res<<endl;
	}
	return 0 ;
}