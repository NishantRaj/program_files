#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , m;
	cin>>n>>m;
	string s[n+9];
	for(int i = 0 ; i < n ; i++)
		cin>>s[i];
	int arr[n+9][m+9];
	memset(arr , 0 , sizeof arr);
	int ans = 0;
	for(int i = n-1 ; i >= 0 ; i--){
		for(int j = m-1 ; j>=0 ; j--){
			int c = s[i][j] == 'W' ? 1 : -1;
			if(arr[i][j] != c){
				ans++;
				c -= arr[i][j];
				for(int k = 0 ; k <= i ; k++)
					for(int l = 0 ; l <= j ; l++)
						arr[k][l] += c;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}