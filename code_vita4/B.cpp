/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 08 August 2015 (Saturday) 02:56
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int t;
	cin>>t;
	while(t--){
		long double n , sv , csv , r , cr , sv_ , cv , r_ , ce , ca;
		cin>>n>>sv>>csv>>r>>cr;
		if(n < 20000.00 || n > 10000000.00){
			cout<<"Invalid Input\n";
			continue;
		}
		if(sv < 20.00 || sv > 10000.00){
			cout<<"Invalid Input\n";
			continue;
		}
		if(csv < -2000.00 || csv > 2000.00){
			cout<<"Invalid Input\n";
			continue;
		}
		if(r < 0.01 || r > 99.99){
			cout<<"Invalid Input\n";
			continue;
		}
		if(cr < -10.00 || cr > 10.00){
			cout<<"Invalid Input\n";
			continue;
		}
		if(csv < 0 && cr > 0)
		{
			cout<<"Invalid Input\n";
			continue;
		}
		sv_ = sv - csv;
		sv_ = ceill(sv_*100)/100.00;
		if( sv <0.00 || sv_ < 0.00){
			cout<<"Invalid Output\n";
			continue;
		}
		cv = n*min(sv , sv_);
		r_ = r - cr;
		ce = cv*0.50;
		ca = (ce*min(r , r_))/100.00;
		cv = ceill(cv*100)/100.00;
		ce = ceill(ce*100)/100.00;
		ca = ceill(ca*100)/100.00;
		r_ = ceill(r_*100)/100.00;
		if(sv_ < 20.00 || sv_ > 10000.00){
			cout<<"Invalid Output\n";
			continue;
		}
		if(r_ < 0.01 || r_ > 99.99){
			cout<<"Invalid Output\n";
			continue;
		}
		cout<<fixed<<setprecision(2)<<sv_<<endl<<r_<<endl<<cv<<endl<<ce<<endl<<ca<<endl;
	}
	
	return 0;
}