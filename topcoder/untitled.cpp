#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int total = 1 , count = 0 , i = 1;
	while(total <= n){
		total += (i*(i+1))/2;
		count++;
		i++;
	}
	cout<<count<<endl;
	return 0;
}