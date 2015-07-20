#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , m;
	cin>>n>>m;
	string s[n+9];
	for(int i = 0 ; i < n ; i++)
		cin>>s[i];
	int count = 0;
	for(int i = 0 ; i< n-1 ; i++){
		for(int j = 0 ;  j < m -1 ; j++){
			vector<char > v;
			v.push_back(s[i][j]);
			v.push_back(s[i][j+1]);
			v.push_back(s[i+1][j]);
			v.push_back(s[i+1][j+1]);
			sort(v.begin() , v.end());
			int len = v.size();
			if(len == 4 && v[0] == 'a' && v[1] == 'c' && v[2] == 'e'&& v[3] == 'f'){
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}