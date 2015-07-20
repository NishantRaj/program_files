#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , l , r , x;
	cin>>n>>l>>r>>x;
	int arr[n+9];
	for(int i = 0  ; i < n ; i++){
		cin>>arr[i];
	}
	long long ans = 0;
	for(int i = 0 ; i< (1<<n) ; i++){
		int temp = i;
		int count = 0;
		int j = 0;
		int mi = 1000000099 , mx  = -1 , sum = 0;
		while(temp){
			if(temp%2 == 1){
				sum += arr[j];
				mx = max(mx , arr[j]);
				mi = min(mi , arr[j]);
				count++;
			}
			temp/=2;
			j++;
		}
		if(count>=2 && sum>= l && sum<= r && (mx - mi) >=x){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;	
}