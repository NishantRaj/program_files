#include <bits/stdc++.h>
using namespace std;
int main()
{
	long  n;
	cin>>n;
	long long total = 0 , count = 0 , i = 1;
	while(total <= n){
		total += (i*(i+1))/2;
		count++;
		i++;
	}
	cout<<count - 1<<endl;
	return 0;
}