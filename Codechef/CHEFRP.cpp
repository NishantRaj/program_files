#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+9];
		bool flag = 0;
		for(int i = 0 ; i < n ; i++){
			cin>>arr[i];
			if(arr[i] < 2)
				flag = 1;
		}
		if(flag){
			cout<<-1<<endl;
			continue;
		}
		sort(arr , arr + n , [](int a , int b){return a > b;});
		ll ans = 0;
		for(int i = 0 ; i < n - 1 ; i++)
			ans += arr[i];
		ans+= 2;
		cout<<ans<<endl;
	}
	return 0;
}