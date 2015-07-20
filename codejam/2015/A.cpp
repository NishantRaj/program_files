#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test<= t ; test++){

		int n;
		string s;
		cin>>n>>s;
		int count = 0 , sum = s[0] - 48;
		for(int i = 1 ; i<= n ; i++){
			if(sum <= i && s[i] != '0'){
				count += (i - sum);
				sum += count + (s[i] - 48);
			}
			else
				sum += (s[i] - 48);
		}
		cout<<"Case #"<<test<<": "<<count<<endl;
	}
	return 0;
}