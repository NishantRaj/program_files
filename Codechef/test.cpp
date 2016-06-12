/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 June 2016 (Friday) 20:05
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int generate(int n , vector<int> &initial_vector){
	map<vector<int> , int> m;
	m.insert(mp(initial_vector , 1));
	int i = 1;
	while(i <= n){
		vector< vector< int> > vv;
		for(auto it:m){
			vector<int> v = it.first;
			for(int j = 0 ; j < v.size() ; j++){
				v[j] = -1*v[j];
				vv.pb(v);
				v = it.first;
			}
		}
		m.clear();
		for(auto it:vv){
			m.insert(mp(it , 1));
		}
		cout<<"k = "<<i<<" : "<<m.size()<<endl;
		for(auto it:m){
			for(auto x:it.first)
				cout<<x<<" ";
			cout<<endl;
		}
		i++;
	}
	return m.size();
}
int power10(int p){
	int res = 1;
	for(int i = 0 ; i < p ; i++)
		res *= 10;
	return res;
}
int FindFirstDigit(long long arr[] , int n){
	long double x = 1.0;
	for(int i = 0 ; i < n ; i++){
		int len = to_string(arr[i]).length();
		len--;
		long double y = (long double)arr[i] / (long double)power10(len);
		cout<<arr[i]<<" "<<y<<" ";
		x *= y;
		if(x >= 10.00){
			x /= 10;
		}
		cout<<x<<endl;
	}
	return (int) x;
}
void chk(int n){
	long long count = 0;
	for(int i =1 ; i<= n/2 - 1 ; i++){
		for(int j = 0 ; 1 + j*i <= n ; j++)
			count++;
	}
	cout<<count<<endl;
}
int main(){
	int n;
	cin>>n;
	chk(n);
	return 0;
}

//http://stackoverflow.com/questions/25121878/2d-segment-quad-tree-explanation-with-c