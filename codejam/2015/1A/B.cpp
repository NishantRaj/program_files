#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll b , n , max_total;
ll array[1009];
ll count_total(ll t){
	ll total = 0;
	for(int i = 0 ; i < b ; i++)
		total = t/array[i] + 1;

	return total;
}
ll b_search(){

	ll low = -1 , high = max_total , mid ;
	while(low < high){
		mid = (low+high)>>1;
		if(count_total(mid) < n)
			low = mid + 1;
		else
			high = mid;
	}
	return high;
}
int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test ++){

		cin>>b>>n;
		for(int i = 0 ; i < b ; i++)
			cin>>array[i];

		
	}
}