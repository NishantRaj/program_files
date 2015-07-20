#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	long long res = 0;
	res = (6*(n-1) + 5)*k;
	cout<<res<<endl;
	for(int i = 0;i<n;i++)
		cout<<(6*i + 1)<<" "<<(6*i+2)<<" "<<(6*i + 3)<<" "<<(6*i + 5)<<endl;
	return 0;
}