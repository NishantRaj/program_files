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
int sum_fibo[100000];
void gen_fibo(int n){
	int a = 1 , b = 1;
	sum_fibo[1] = 1;
	for(int i = 2 ; i <= n ; i++){
		//fibo[i] = (fibo[i-1] + fibo[i-2])%26;

		sum_fibo[i] = (sum_fibo[i-1] + b)%26;
		int temp = b;
		b = (a+b)%26;
		a = temp;
	}
}
string encrypt(string text , string pass){
	reverse(text.begin() , text.end());
	text.append(pass);
	int len = pass.length();
	for(int j = 0 ;j < (int)text.length() ; j++){
		if(j%2 == 1){
			if(isupper(text[j]))
				text[j] = (char)((text[j] - sum_fibo[len] - 65 + 26)%26 + 65);
			else if(islower(text[j]))
				text[j] = (char)((text[j] - sum_fibo[len] - 97 + 26)%26 + 97);
		} else{
			if(isupper(text[j]))
				text[j] = (char)((text[j] + sum_fibo[len] - 65)%26 + 65);
			else if(islower(text[j]))
				text[j] = (char)((text[j] + sum_fibo[len] - 97)%26 + 97);
		}
	}
	return text;
}
string decrypt(string text , string pass){
	int n = pass.length();
	for(int j = 0 ;j < (int)text.length() ; j++){
		if(j&1){
			if(isupper(text[j]))
				text[j] = (char)((text[j] + sum_fibo[n] - 65)%26 + 65);
			else if(islower(text[j]))
				text[j] = (char)((text[j] + sum_fibo[n] - 97)%26 + 97);
		} else{
			if(isupper(text[j]))
				text[j] = (char)((text[j] - sum_fibo[n]+26 - 65)%26 + 65);
			else if(islower(text[j]))
				text[j] = (char)((text[j] - sum_fibo[n]+26 - 97)%26 + 97);
		}
	}
	int len = text.length() - pass.length();
	string temp = text.substr(len , pass.length());
	if(temp!= pass){
		return "Wrong Password";
	}
	text = text.substr(0 , len);
	reverse(text.begin() , text.end());
	return text;
}
int main(){
	char fileName[100000] , password[100000] , temp, te , wro;
	vector<string> text;
	vector<string> save;
	int n;
	cin>>n;
	cin>>fileName>>password;
	int passLen = password.length();
	gen_fibo(passLen);
	freopen(fileName.c_str() , "r" , stdin);
	int flag=0;
	while(getline(cin , temp)){
		text.pb(temp);
	}
	if(n == 1){
		for(int i = 0;  i < (int)text.size()-1 ; i++)
			cout<<encrypt(text[i] , password)<<endl;
		if(text.size() >=1)
			cout<<encrypt(text[(int)text.size() -1] , password);
	} else if(n==2){
		for(int i = 0 ;i < (int)text.size(); i++){
			temp = decrypt(text[i] , password);
			if(temp == "Wrong Password"){
				cout<<"Wrong Password";
				return 0;
			}
			save.pb(temp);
		}
		for(int i = 0 ; i < (int)save.size() -1 ; i++)
			cout<<save[i]<<endl;
		if(save.size() >=1)
			cout<<save[(int)save.size()-1];
	}
	fflush(stdin);
	return 0;
}