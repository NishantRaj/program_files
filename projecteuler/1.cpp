#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n--;
		long long multiple_3_count = n / 3 , multiple_5_count = n / 5;
		//cout<<multiple_3_count<<" " << multiple_5_count<<endl;
		long long multiple_3_sum = 3 * ( (multiple_3_count * ( multiple_3_count + 1 ) ) / 2) ;
		long long multiple_5_sum = 5 * ( (multiple_5_count * ( multiple_5_count + 1 ) ) / 2) ;
		long long common_count = n / 15;
		long long common_sum = 15 * ( ( common_count * ( common_count + 1 ) ) / 2) ;
		//cout<<multiple_3_sum<<" "<<multiple_5_sum<<" "<< common_sum<<endl;
		cout<<multiple_3_sum + multiple_5_sum - common_sum<<endl;
	}
	return 0;
}
