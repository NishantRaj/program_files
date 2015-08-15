/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 12 August 2015 (Wednesday) 23:01
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
class node{
public:
	int pos , left , right;
};
bool compare(const node &a , const node &b){
	return a.left == b.left? a.right < b.right : a.left < b.left;
}
int Rank[20][100009] , SA[100009] , LCP[100009];
void suffix_array(string &s){
	int len = s.size();
	node arr[len+9];
	for(int i = 0 ; i < len ; i++)
		if(s[i] == '#')
			Rank[0][i] = INT_MAX;
		else
			Rank[0][i] = s[i] - 97;
	for(int cnt = 1 , stp = 1 ; (cnt>>1) < len ; cnt<<=1 , stp++){
		for(int i = 0 ; i < len ; i++){
			arr[i].left = Rank[stp-1][i];
			arr[i].right = i + cnt < len ? Rank[stp-1][i+cnt] : -1;
			arr[i].pos = i;
		}
		sort(arr , arr+len , compare);
		for(int i = 0 ; i < len ; i++)
			Rank[stp][arr[i].pos] = i > 0 && arr[i].left == arr[i-1].left && arr[i].right == arr[i-1].right ? Rank[stp][arr[i-1].pos] : i;
	}
	int pos = ceil(log(len)/log(2));
	for(int i = 0 ; i < len ; i++)
		SA[Rank[pos][i]] = i;
}
void calculate_lcp(string &s){
	int len = s.size();
	int pos = ceil(log(len)/log(2));
	for(int i = 0 , k = 0 ; i < len ; i++ , k?k--:0){
		if(Rank[pos][i] == len-1){ k = 0 ; continue;}
		int j = SA[Rank[pos][i]+1];
		while(i + k < len && j + k < len && s[i+k]==s[j+k]) k++;
		LCP[Rank[pos][i]+1] = k;
	}
}
int main(){
	
	int n;
	ios::sync_with_stdio(false);
	cin>>n;
	string temp , s="";
	int cum[n+9];
	cin>>temp;
	int count = temp.size();
	cum[0] = count++;
	s.append(temp);
	s.push_back('#');
	for(int i = 1 ; i < n ; i++){
		cin>>temp;
		count+=temp.size();
		cum[i] = count;
		count++;
		temp.push_back('#');
		s.append(temp);
	}
	cout<<s<<endl;
	suffix_array(s);
	calculate_lcp(s);
	int cum1[s.size()+9] , pos;
	pos = lower_bound(cum , cum+n , SA[0]) - cum;
	cum1[0] = cum[pos] - SA[0];
	for(int i = 1 ; i < s.size() ; i++){
		pos = lower_bound(cum , cum+n , SA[i]) - cum;
		cum1[i] = cum1[i-1] + (cum[pos] - SA[i] -LCP[i]);
	}
	for(int i = 0 ; i < s.size() ; i ++){
		cout<<SA[i]<<" ";
		for(int j = SA[i] ; j< s.size() ; j++)
			cout<<s[j];
		cout<<" "<<LCP[i]<<endl;
	}
	for(int i = 0 ; i < n ; i++)
		cout<<cum[i]<<" ";
	cout<<endl;
	for(int i = 0 ; i < s.size() ; i++)
		cout<<cum1[i]<<" ";
	cout<<endl;
	int q;
	cin>>q;
	while(q--){
		int sz = s.size();
		int a ;
		cin>>a;
		int pos = lower_bound(cum1,cum1+sz,a)- cum1;
		int i , j;
		for(i = SA[pos] ,j = 0 ; j <  LCP[pos] ; j++ , i++)
			cout<<s[i];
		for(int j = 0 ; j< a - cum[pos-1] ; j++,i++)
			cout<<s[i];
		printf("\n");
	}
	return 0;
}