#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , c;
	cin>>n>>c;
	int x[n+9] , y[n+9];
	long long sum_x = 0 , sum_y = 0;
	for(int i = 0 ;i < n ; i++){
		cin>>x[i]>>y[i];
		sum_x += x[i];
		sum_y += y[i];
	}
	cout<< ((sum_x/n + sum_y/n)*c)<<endl;
	return 0;
}
