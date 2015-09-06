/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 27 August 2015 (Thursday) 15:48
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
string to_string(int x){
	string temp="";
	while(x){
		char c = x%10 + 48;
		x/=10;
		temp = c + temp; 
	}
	return temp;
}
int stoi(string s){
	int x = 0;
	for(size_t i = 0 ; i < s.size() ; i++){
		x = x*10 + (s[i]-48);
	}
	return x;
}
bool compare(const string &a , const string &b){
	if(a.size() < b.size()){
		return true;
	} else if(a.size() > b.size()){
		return false;
	} else{
		return a < b;
	}
}
int main(){
	
	int t;
	scanf("%d ",&t);
	while(t--){
		string inp;
		getline(cin , inp);
		istringstream iss(inp);
		string temp;
		int i = 0;
		vector<string> v , formated , in;
		while(iss>>temp){
			if(i%2==0){
				v.pb(temp);
			} else
				in.pb(temp);
			i++;
		}
		sort(in.begin() , in.end() , compare);
		for(size_t i = 0 ; i < v.size() ; i++){
			string x="";
			for(size_t j = 0 ; j < v[i].size() ; j++){
				char c = tolower(v[i][j]);
				x = x + c;
			}
			formated.pb(x);
		}
		sort(formated.begin() , formated.end());
		string final="";
		for(size_t i = 0 ; i < formated.size() ; i++){
			if(i !=0 )
				final = final + ' ';
			final = final + formated[i];
			final = final + ' ';
			final = final + in[i];
		}
		cout<<final<<endl;
	}
	
	return 0;
}