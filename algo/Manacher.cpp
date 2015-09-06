/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 29 July 2015 (Wednesday) 04:11
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
string longest_palindromic_substring(string s){
	string temp;
	if(s.length() == 0)
		temp = "&$";
	else temp = "&";
	for(int i = 0 ; i < s.length() ; i++)
		temp = temp + "#" + s[i];
	temp+= "#$";
	int len = temp.length() , c=1 , r = 0 , max_len = 0 , pos = 0;
	int *arr = new int[len];
	for(int i = 1 ; i < len-1 ; i++){
		if(r > i) arr[i] = min(r-i , arr[2*c-i]);
		while(temp[i + arr[i] + 1] == temp[i - arr[i] - 1]) arr[i]++;
		if(i+arr[i] > r) c = i , r = i + arr[i];

		if(max_len < arr[i]) max_len = arr[i] , pos = i;
	}
	delete[] arr;
	return s.substr((pos - 1 - max_len)/2 ,max_len); 
}
int main(){
	string s;
	cin>>s;
	cout<<longest_palindromic_substring(s)<<endl;
	
	return 0;
}