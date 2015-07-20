#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define PB push_back
#define MP make_pair
int rank[20][MAX];
struct tuple
{
	int pos;
	int firstHalf,secondHalf;
};
bool compare(const tuple &a , const tuple &b)
{
	return a.firstHalf == b.firstHalf ?a.secondHalf < b.secondHalf :a.firstHalf < b.firstHalf;
}
/*void counting_sort(tuple t[] , int n)
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
}*/
int * suffix_array(tuple t[] , char s[], int length	)
{
	int pos = 0;
	int *arr = (int*)calloc(length+9,sizeof(int));
	for(int i=0;i<length;i++){
		rank[0][i] = s[i] - 'a';
	}
	for(int cnt = 1,stp = 1;(cnt>>1) < length ; cnt<<=1,stp++)
	{
		for(int i = 0;i<length ; i++)
		{
			t[i].firstHalf = rank[stp-1][i];
			t[i].secondHalf = i+cnt < length ? rank[stp-1][i+cnt] : -1;
			t[i].pos = i;
		}
		sort(t,t+length,compare);
		int rnk = 0;
		for(int i = 0 ; i<length ; i++)
		{
			if((i > 0) && (t[i-1].firstHalf == t[i].firstHalf && t[i].secondHalf == t[i-1].secondHalf))
				rnk = rank[stp][t[i-1].pos];
			else
				rnk = i;
			rank[stp][t[i].pos] = rnk;
		}
	}
	pos = ceil(log(length)/log(2));
	for(int i=0;i<length;i++)
		arr[rank[pos][i]] = i;
	return arr;
}
int LCP(int i,int j,int n)
{
	int res = 0;
	if(i==j)
		return n - i;
	for(int stp = ceil(log(n)/log(2)) ; stp>=0 && i < n && j < n ; stp--)
		if(rank[stp][i] == rank[stp][j])
		{
			res += 1<<stp;
			i += 1<<stp;
			j += 1<<stp;
		}
	return res;
}
int LCParray(char s[],int p[],int n)
{
	int sum = 0;
	for(int i = 1 ; i < n ; i++){
		sum += (LCP(p[i-1],p[i],n));
		cout<<(LCP(p[i-1],p[i],n))<<endl;
	}
	return sum;
}
int main()
{
	int l;
	scanf("%d",&l);
	while(l--)
	{
		char *s;
		int n;
		s = (char *)calloc(100009,sizeof(char));
		scanf("%s",s);
		char *str;
		str = (char *)calloc(200020 , sizeof(char));
		strcat(str,s);
		n = strlen(str);
		//cout<<n<<" "<<str<<endl;
		//strcat(str,s);
		//int n = strlen(s);
		//memset(rank,0,sizeof rank);
		tuple t[n + 9];
		int *p;
		p = suffix_array(t,str,n);
		for(int i = 0 ; i < 20 ; i ++)
		{
			for(int j = 0 ; j < n ; j ++)
				cout<<rank[i][j]<<" ";
			cout<<endl;
		}
		cout<<"her\n";
		for(int i = 0;i<n;i++)
		{
			for(int j = p[i] ; j<n ; j++)
				cout<<str[j];
			cout<<endl;
		}
		//printf("%d\n",p[0]);
		long long lcp_sum = 0,suffix_sum = 0;
		lcp_sum = LCParray(s,p,n);
		for(int i=0;i<n;i++)
			suffix_sum += p[i];
		printf("%lld\n",(long long)n*n - lcp_sum - suffix_sum);
		free(str);
		free(s);
	}
	return 0;
}