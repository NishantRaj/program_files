/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 21 July 2015 (Tuesday) 15:27
===================================================*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
int SA[1000009] , rank_array[22][1000009] , lcp[1000009];
struct node{
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
bool compare(const node &a , const node & b)
{
    return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void suffixArray(char str[] , int n)
{
    node t[n+9] ;
    for(int i = 0 ; i < n ; i++)
        rank_array[0][i] = str[i] - 97;
    for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            t[i].left = rank_array[stp-1][i];
            t[i].right = i + cnt < n ? rank_array[stp-1][i + cnt] : -1;
            t[i].pos = i;
        }
        counting_sort(t , n);
        //sort(t , t + n , compare);
        for(int i = 0 ; i < n ; i ++)
            rank_array[stp][t[i].pos] = i > 0 && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank_array[stp][t[i-1].pos] : i ;
    }
    int pos = ceil(log(n) / log(2));
    for(int i = 0 ; i < n ; i++)
        SA[rank_array[pos][i]]  = i;
}
int search_l(char patt[] , char text[] , int len){
	int patt_len = strlen(patt);
	int low = 0 , high = len , mid;
	while(low < high){
		mid = (low+high)>>1;
		int res = strncmp(patt , text+SA[mid] , patt_len);
		if(res <= 0)
			high = mid;
		else
			low = mid+1;
		// cout<<patt<< " " << text+SA[mid]<< " "<<res<<" "<<low<<" "<<high<<" "<<mid<<endl;
	}
	// cout<<high<<endl;
	return high;
}
int search_h(char patt[] , char text[] , int len){
	int patt_len = strlen(patt);
	int low = 0 , high = len , mid;
	bool flag = false;
	while(low < high){
		mid = (low+high)>>1;
		int res = strncmp(patt , text+SA[mid] , patt_len);
		if(res == 0)
			flag = true;
		if(res < 0)
			high = mid;
		else
			low = mid+1;
		// cout<<patt<< " " << text+SA[mid]<< " "<<res<<" "<<low<<" "<<high<<" "<<mid<<endl;
	}
	// cout<<low<<" "<<flag<<endl;
	if(low == len-1 && flag)
		low++;
	return low;
}
char s[1000009];
int main()
{
    scanf("%s" , s);
    int n = strlen(s);
    suffixArray(s , n);
    // for(int i = 0 ; i<n ; i++)
    // {
    // 	cout<<i<<" ";
    //     for(int j = SA[i];j<n;j++)
    //         cout<<s[j];
    //     cout<<" "<<SA[i];
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
    	string patt , temp;
    	cin>>patt;
    	int count = 0;
    	count = search_h(&patt[0] , s , n) - search_l(&patt[0] , s , n);
    	// cout<<patt<<" "<<search_l(&patt[0] , s , n)<< " " <<search_h(&patt[0] , s , n)<<endl;
    	for(int i = 1 ; i < patt.size() ; i++){
    		temp = patt.substr(i , n-i)+patt.substr(0 , i);
    		// cout<<temp<< " " << patt<< " " <<search_l(&temp[0] , s , n)<< " " << search_h(&temp[0] , s , n)<<endl;
    		if(temp != patt){
    			count += search_h(&temp[0] , s , n) - search_l(&temp[0] , s , n);
    		} else
    			break;
    	}
    	cout<<count<<endl;
    }
    return 0;
}