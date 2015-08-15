/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 05 August 2015 (Wednesday) 20:26
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mod 1000000009
void gen(map<vector<int> , int> &mp , vector<int> v , int n , int pos , int sum , int giv , vector<int> &a){
    if(sum == giv){
        mp.insert(make_pair(v , 1));
		return ;
    } else{
        for(int i = pos ; i < n ; i++){
            v.push_back(a[i]);
            gen(mp , v , n , i+1 , sum+a[i] , giv , a);
            v.pop_back();
        }
    }
}
int main(){
	
	int n , B;
	vector<int> A;
	cin>>n>>B;
	for(int i = 0 ; i < n ; i ++){
		int temp ;
		cin>>temp;
		A.pb(temp);
	}
	sort(A.begin() , A.end());
	map<vector<int> , int> mp;
    vector<int> v;
    vector<vector<int> > ans;
    gen(mp , v , n , 0 , 0 , B , A);
    for(auto it = mp.begin() ; it!= mp.end() ; it++){
        for(int i = 0 ; i < it->first.size() ; i++)
        	cout<<it->first[i]<<" ";
        cout<<endl;
	}
	return 0;
}