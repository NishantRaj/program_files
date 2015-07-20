#include <bits/stdc++.h>
using namespace std;
bool check_palindrome(string s){
	//cout<<s<<endl;
	int len = s.length();
	for(int i = 0 , j = s.length()-1; i<= len/2 ; j--,i++){
		if(s[i] != s[j])
			return false;
	}
	return true;
}
int main(){
	int k;
	string s;
	cin>>s>>k;
	int length = s.length();
	if(length%k != 0){
		cout<<"NO\n";
		return 0;
	}
	int counter = length/k;
	for(int i = 0 ; i < length ; i+=counter){
		//cout<<i+1<<" "<<i+counter<<endl;
		if(!check_palindrome(s.substr(i ,counter))){
			cout<<"NO\n";
			return 0;
		}
		//cout<<s<<endl;
	}
	cout<<"YES\n";
	return 0;
}