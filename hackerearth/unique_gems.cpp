/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 20 July 2015 (Monday) 22:13
===================================================*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int SA[1000009] , rank_array[20][1000009] , lcp[1000009];
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
void lcpArray(char str[] , int n)
{
    int k = 0 , pos = ceil(log(n) / log(2));
    lcp[0] = 0;
    for(int i = 0 ; i < n ; i++ , k?k--:0)
    {
        if(rank_array[pos][i] == n - 1) { k = 0 ; continue;}
        int j = SA[rank_array[pos][i]+1];
        while(i + k < n && j + k < n && str[i+k] == str[j+k]) k++;
        lcp[rank_array[pos][i] + 1] = k;
    }
}
long long count_str(char s[] , int n){
	int last = 0;
    long long ans = 0;
    long long dis = 1L * n * (n + 1L) / 2;
    for (int  i = 1 ; i< n ; i++) {
        int add = lcp[i] - last;
        if(add > 0){
            ans += add;

        }
        last = lcp[i];
        dis -= lcp[i];
    }
    return dis - ans;
}
void solve(){
	char s[100009];
	scanf("%s" , s);
	int n = strlen(s);
	suffixArray(s , n);
	lcpArray(s , n);
	// for(int i = 0 ; i<n ; i++)
 //    {
 //        for(int j = SA[i];j<n;j++)
 //            cout<<s[j];
 //        cout<<" "<<SA[i];
 //        cout<<endl;
 //    }
    // for(int i = 0 ;i<n ; i++)
    //     cout<<lcp[i]<<endl;
	printf("%lld\n" , count_str(s , n));
}
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--){
    	memset(SA , 0 , sizeof SA);
    	memset(lcp , 0 , sizeof lcp);
    	memset(rank_array , 0 , sizeof rank_array);
    	solve();
    }
    return 0;
}