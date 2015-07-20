#include <bits/stdc++.h>
using namespace std;
string solve(int x , int y , int n){
	if(y < x)
		swap(x , y);
	if(n == 1) return "GABRIEL";
	if(x == 1 && y == 1) return "RICHARD";
	if(x == 1 && y == 2){
		if(n == 2) return "GABRIEL";
		else return "RICHARD";
	}
	if(x == 1 && y == 3) return "RICHARD";
	if(x == 1 && y == 4){
		if(n == 3 || n == 4) return "RICHARD";
		else return "GABRIEL";
	}
	if(x == 2 && y == 2){
		if(n == 3 || n == 4) return "RICHARD";
		else return "GABRIEL";
	}
	if(x == 2 && y == 3){
		if(n == 2 || n ==3) return "GABRIEL";
		else return "RICHARD";
	}
	if(x == 2 && y == 4){
		if(n == 3 || n == 4) return "RICHARD";
		else return "GABRIEL";
	}
	if(x == 3 && y == 3){ 
		if (n == 2 || n ==4) return "RICHARD";
		else return "GABRIEL";
	}
	if(x == 3 && y == 4) return "GABRIEL";
	if(x == 4 && y == 4){
		if(n == 3) return "RICHARD";
		else return "GABRIEL";
	}
}
int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test++){

		int n , r , c;
		cin>>n>>r>>c;
		cout<<"Case #"<<test<<": "<<solve(r , c , n)<<endl;
	}
	return 0;
}