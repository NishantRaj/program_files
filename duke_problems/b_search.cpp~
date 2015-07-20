#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll points[100009][2];
ll total_cost(int type , int from){
	ll res = 0;
	for(int i = 0 ; i < n ; i++)
		res += abs(from - points[i][type]);
	return res;
}
ll min_x_y(int type){
	ll low = 0  , high = 1000000000 , mid;
	while(low < high){
		mid = (low + high)>>1;
		ll at_less , at_mid , at_more;
		at_less = total_cost(type , mid - 1);
		at_mid = total_cost(type , mid);
		at_more = total_cost(type , mid+1);
		if((at_more > at_mid && at_mid > at_less))
			high = mid+1;
		else if ((at_less > at_mid && at_mid > at_more))
			low = mid ;
		else
			return at_mid;
	}
	return low;
}
int main(){
	int cost;
	ios::sync_with_stdio(false);
	cin>>n>>cost;
	for(int i = 0 ; i < n ; i++)
		cin>>points[i][0]>>points[i][1];
	ll cost_x = min_x_y(0) , cost_y = min_x_y(1);
	cout<<(cost_y + cost_x)*cost<<endl;
	return 0;
}
