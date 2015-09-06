/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 31 August 2015 (Monday) 13:37
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int binary_search(int arr[] , int index[] , int pos , int L){
	int low =1 , high =L , mid;
	while(low <= high){
		mid = (low + high)>>1;
		if(arr[index[mid]] < arr[pos])
			low = mid+1;
		else
			high = mid-1;
	}
	return low;
}
int main(){
	
	int n;
	cin>>n;
	int arr[n+9];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	int index[n+9] ,  parent[n+9];
	memset(index , 0 , sizeof index);
	memset(parent , 0 , sizeof parent);
	int l = 0;
	for(int i = 0 ; i < n ; i++){
		int pos = binary_search(arr , index , i , l);
		parent[i] = index[pos-1];
		index[pos] = i;
		if(pos > l)
			l = pos;
	}
	int k = index[l];
	for(int i = 0 ; i < l ; i++){
		cout<<arr[k]<<" ";
		k = parent[k];
	}
	cout<<endl;
	return 0;
}