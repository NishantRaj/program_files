#include <bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin>>t;
	for(int test = 1 ; test<= t ; test++){

		int n;
		cin>>n;
		int arr[n+9];
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];
		long long res1 = 0 , res2 = 0 , rate = 0;
		for(int i = 1 ; i < n ; i++){
			res1 += max(0 , arr[i-1] - arr[i]);
			rate = max(rate , (long long)arr[i-1] - arr[i]);
		}

		for(int i = 0 ; i < n-1 ; i++)
			res2 += min(rate , (long long)arr[i]);
		cout<<"Case #"<<test<<": "<<res1<<" "<<res2<<endl;
	}
	return 0;
}