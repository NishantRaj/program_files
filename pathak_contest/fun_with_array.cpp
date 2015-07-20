#include <bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin>>t;
	while(t--){

		int n , p;
		cin>>n>>p;

		int arr[n+9] , mod[n+9];
		mod[0] = 0;
		int hash[1000009];
		for(int i = 0 ; i < 1000001 ; i++)
			hash[i] = INT_MAX;
		for(int i = 1 ; i <= n ; i++){
			cin>>arr[i];
			mod[i] = (mod[i-1] + arr[i])%p;

			if(mod[i] == 0)
				hash[mod[i]] = 0;
			hash[mod[i]] = min(hash[mod[i]] , i);
		}
		int max_len = 0;
		for(int i = 1 ; i<= n ; i++){
			int length = 0;
			if(hash[mod[i]] != INT_MAX)
				length = abs(i - hash[mod[i]]);
			max_len = max(max_len , length);
		}

		cout<<max_len<<endl;

	}
	return 0;
}