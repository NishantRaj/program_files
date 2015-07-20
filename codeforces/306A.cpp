#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	map<int , int> mp , m;
	vector<int>v , b;
	for(int i = 0 ; i < s.length()-1 ; i++){
		if(s[i] == 'A' && s[i+1]=='B'){
			v.push_back(i);
		}
		if(s[i] == 'B' && s[i+1] =='A'){
			b.push_back(i);
		}
	} 
	int flag = 0 , flag2 = 0;
	for(int i = 0 ; i< v.size() ; i++){
		for(int j = 0;  j<b.size() ; j++){
			flag2 = 1;
			if((v[i] <= b[j] && v[i]+1 >= b[j]) || (v[i]<=b[j]+1 && v[i]+1 >= b[j]+1) || (b[j] <= v[i] && b[j]+1 >= v[i])|| (b[j]<=v[i]+1 && b[j]+1>=v[i]+1)){}
			else{
				flag = 1;
				break;
			}
		}
	}
	if(flag && flag2)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}