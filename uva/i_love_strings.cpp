/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 20 July 2015 (Monday) 15:07
===================================================*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define MAX 100009
int SA[100009] , rank_arr[20][100009];
using namespace std;
class node{
public:
	int left , right , pos;
};
void counting_sort(node t[] , int n)
{
    int count[MAX + 9];
    memset(count , 0 , sizeof count);
    node temp[n+9];
    for(int i  = 0 ; i < n ; i ++)
        count[t[i].right + 1] ++;

    for(int i = 1 ; i <= MAX ; i ++)
        count[i] += count[i-1];

    for(int i = 0 ; i < n ; i++)
    {
        temp[count[t[i].right + 1] - 1] = t[i];
        count[t[i].right + 1]--;
    }

    memset(count , 0 , sizeof count);

    for(int i = 0 ; i < n ; i++)
        count[t[i].left + 1] ++;

    for(int i = 1 ; i <= MAX ; i++)
        count[i] += count[i-1];

    for(int i = n-1 ; i >= 0 ; i--)
    {
        t[count[temp[i].left + 1] - 1] = temp[i];
        count[temp[i].left + 1]--;
    }
}
void suffix_array(char s[] ,  int n){
	for(int i = 0 ; i<n;i++)
		rank_arr[0][i] = s[i] - 65;
	node arr[n+9];
	int stp = 1;
	for(int  cnt = 1;(cnt>>1)<n ; cnt<<=1 ,stp++){
		for(int i = 0 ; i < n ; i++){
			arr[i].left = rank_arr[stp-1][i];
			arr[i].right = i+cnt<n ? rank_arr[stp-1][i+cnt] : -1;
			arr[i].pos = i;
		}
		counting_sort(arr , n);
		for(int i = 0 ; i < n ; i++)
			rank_arr[stp][arr[i].pos] = i>0 && arr[i].left == arr[i-1].left && arr[i].right == arr[i-1].right ? rank_arr[stp][arr[i].pos-1] : i;
	}
	stp--;
	for(int i = 0 ; i < n ; i++)
		SA[rank_arr[stp][i]] = i;
}
bool search(char patt[] , char text[] , int len){
	int patt_len = strlen(patt);
	int low = 0 , high = len-1 , mid;
	while(low < high){
		mid = (low+high)>>1;
		int res = strncmp(patt , text+SA[mid] , patt_len);
		if(res == 0)
			return true;
		else if(res < 0)
			high = mid;
		else
			low = mid+1;
	}
	return false;
}
int main(){
	
	int t;
	cin>>t;
	while(t--){
		char s[100009];
		scanf("%s" , s);
		int n = strlen(s);
		suffix_array(s , n);
		int q;
		scanf("%d ",&q);
		while(q--){
			char patt[1009];
			scanf("%s" , patt);
			if(search(patt, s , n))
				printf("y\n");
			else 
				printf("n\n");
		}
	}
	
	return 0;
}