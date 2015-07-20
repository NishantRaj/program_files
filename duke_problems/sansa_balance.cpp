#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	int l , n , m;
	cin>>l>>n>>m;
	ll  right = 0 , left = 0 ,a ,b;
	for(int i = 0 ; i < n ; i++){
		cin>>a>>b;
		if(a < m)
			left += (m - a)*b;
		else if( a  > m)
			right += (a- m)*b;
	}
	if(left > right)
		cout<<"left\n";
	else if(right > left)
		cout<<"right\n";
	else if(right == left)
		cout<<"balanced\n";
	return 0;
}
