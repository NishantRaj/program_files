#include <bits/stdc++.h>
using namespace std ;
#define MAX 1000000
int z[1000009] , tree[1000009];
void update(int pos)
{
	while(pos)
	{
		tree[pos] += 1;
		pos -= (pos & -pos);
	}
}
int read(int pos)
{
	int res = 0;
	while(pos <= MAX)
	{
		res += tree[pos];
		pos += (pos & -pos);
	}
	return res;
}
void zFunction(char s[] , int n)
{
	int l = 0 , r = 0;
	for(int i = 1 ; i < n ; i ++)
	{
		if(i <= r) z[i] = min ( r - i + 1 , z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++ ;
		if(i + z[i] - 1 > r) l = i , r = i + z[i] - 1;
	}
}
bool Search(int n , char s[])
{
	int flag = 0;
	for(int i = 1 ; i < n  ;i++)
	{
		if(z[i] == n-i)
		{
			int res = read(z[i]);
			if(res)
			{
				flag = 1;
				for(int j = 0 ; j < z[i] ; j++)
					cout<<s[j];
				cout<<endl;
				break;
			}
		}
		update(z[i]);
	}
	if(!flag)
		cout<<"Just a legend\n";
}
int main()
{
	char s[1000009];
	scanf("%s",s);
	int n = strlen(s);
	zFunction(s , n);
	Search(n , s);
	return 0;
}