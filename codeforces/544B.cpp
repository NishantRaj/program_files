#include <bits/stdc++.h>
using namespace std;
int main(){

	int n , k;
	cin>>n>>k;
	int total = 0;
	char  s[n][n+1] , temp;
	char c;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			s[i][j] = 'S';
		s[i][n] = '\n';
	}
	s[n-1][n] = 0; 
	for(int i = 0 ; i < n && total < k; i++){
		int start = i&1 ? 1 : 0;
		for(int j = start ; j< n && total<k; j+=2){
				s[i][j] = 'L' , total++;
		}
	}
	if(total < k)
		cout<<"NO\n";
	else{
		cout<<"YES\n"<<s[0];
	}
	return 0;
}