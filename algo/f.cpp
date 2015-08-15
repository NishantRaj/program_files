/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 08 August 2015 (Saturday) 00:15
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
ll fibo[1000000];
ll sum_fibo[100000];
void gen_fibo(int n){
	fibo[1] = 1;
	sum_fibo[1] = 1;
	for(int i = 2 ; i <= n.length() ; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2])%26;
		sum_fibo[i] = (sum_fibo[i-1] + fibo[i])%26;
	}
}
string encrypt(string text , string pass){
	reverse(text.begin() , text.end());
	text.append(pass);
	int len = pass.length();
	for(int j = 0 ;j < text.length() ; j++){
		if(i&1){
			if(isupper(text[j]))
				text[j] = (text[j] - sum_fibo[len] - 65 + 26)%26 + 65;
			else if(islower(text[j]))
				text[j] = (text[j] - sum_fibo[len] - 97 + 26)%26 + 97;
		} else{
			if(isupper(text[j]))
				text[j] = (text[j] + sum_fibo[len] - 65)%26 + 65;
			else if(islower(text[j]))
				text[j] = (text[j] + sum_fibo[len] - 97)%26 + 97;
		}
	}
	return text;
}
string decrypt(string text , string pass){
	int n = pass.length();
	for(int j = 0 ;j < text.length() ; j++){
		if(i&1){
			if(isupper(text[j]))
				text[j] = (text[j] + sum_fibo[n] - 65)%26 + 65;
			else if(islower(text[j]))
				text[j] = (text[j] + sum_fibo[n] - 97)%26 + 97;
		} else{
			if(isupper(text[j]))
				text[j] = (text[j] - sum_fibo[n]+26 - 65)%26 + 65;
			else if(islower(text[j]))
				text[j] = (text[j] - sum_fibo[n]+26 - 97)%26 + 97;
		}
	}
	int len = text.length() - pass.length();
	string temp = text.substr(len , pass.length());
	if(temp!= pass){
		return "Wrong Password";
	}
	return text.substr(0 , len);
}
int main(){
	
	int n;
	cin>>n;
	string fileName , password;
	cin>>fileName>>password;
	int passLen = password.length();
	gen_fibo(passLen);
	fstream ff(filename);
	while(getline(ff , temp)){
		if(n==1){
			cout<<encrypt(temp , password)<<endl;
		} else if(n == 2){
			cout<<decrypt(temp , password)<<endl;
		}
	}
	return 0;
}