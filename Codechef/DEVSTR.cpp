#include <bits/stdc++.h>
using namespace std;
void flip(string &s , int pos){
	s[pos] == '0' ? s[pos] = '1' : s[pos] = '0';
}
int main(){

	int t;
	cin>>t;
	while(t--){
		int n , k;
		cin>>n>>k;
		string s;
		cin>>s;
		if(k==1){
			string temp = s , temp1 = s ;
			int ans = 0 , ans1 = 0;
			for(int i = 0 ; i< n ; i++){
				if(i&1){
					if(temp[i] != '0')
						temp[i] = '0' , ans++;
				}
				else
					if(temp[i] != '1')
						temp[i] = '1' , ans++;
			}

			for(int i = 0 ; i< n ; i++){
				if(i&1){
					if(temp1[i] != '1')
						temp1[i] = '1' , ans1++;
				}
				else
					if(temp1[i] != '0')
						temp1[i] = '0' , ans1++;
			}
			if(ans < ans1)
				cout<<ans<<endl<<temp<<endl;
			else
				cout<<ans1<<endl<<temp1<<endl;
			continue;
		}
		s = s[0] + s + s[n-1];
		string s1 = s;
		char c = s[1];
		int count = 1 , ans = 0;
		for(int i = 2 ; i <= n ; i++){
			if(s[i] == c)
				count++;
			else
				c = s[i] , count = 1;
			if(count > k){
				flip(s , i);
				ans++;
				if(s[i+1] == s[i]){
					if(s[i-2] != s[i])
						swap(s[i-1] , s[i]);
				}
				c = s[i] , count = 1;
			}
		}
		c = s1[n];
		count = 1;
		int ans1 = 0;
		for(int i = n -1; i>=1 ; i--){
			if(s1[i] == c)
				count++;
			else
				c = s1[i] , count = 1;
			if(count > k){
				flip(s1 , i);
				ans1++;
				if(s1[i-1] == s1[i]){
					if(s1[i+2] != s1[i])
						swap(s1[i+1] , s1[i]);
				}
				c = s1[i] , count = 1;
			}
		}

		s1 = s1.substr(1 , n);
		s = s.substr(1 , n);
		if(ans1 < ans)
			cout<<ans1<<endl<<s1<<endl;
		else
			cout<<ans<<endl<<s<<endl;
	}
	return 0;
}