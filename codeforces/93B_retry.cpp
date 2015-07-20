/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 20 July 2015 (Monday) 00:18
===================================================*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int SA[1000009] , rank[20][1000009] , lcp[1000009];
struct tuple{
    int left , right , pos;
};
void counting_sort(tuple t[] , int n)
{
    int count[MAX + 9];
    memset(count , 0 , sizeof count);
    tuple temp[n+9];
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
bool compare(const tuple &a , const tuple & b)
{
    return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void suffixArray(char str[] , int n)
{
    tuple t[n+9] ;
    for(int i = 0 ; i < n ; i++)
        rank[0][i] = str[i] - 97;
    for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            t[i].left = rank[stp-1][i];
            t[i].right = i + cnt < n ? rank[stp-1][i + cnt] : -1;
            t[i].pos = i;
        }
        counting_sort(t , n);
        //sort(t , t + n , compare);
        for(int i = 0 ; i < n ; i ++)
            rank[stp][t[i].pos] = i > 0 && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i-1].pos] : i ;
    }
    int pos = ceil(log(n) / log(2));
    for(int i = 0 ; i < n ; i++)
        SA[rank[pos][i]]  = i;
}
void lcpArray(char str[] , int n)
{
    int k = 0 , pos = ceil(log(n) / log(2));
    lcp[0] = 0;
    for(int i = 0 ; i < n ; i++ , k?k--:0)
    {
        if(rank[pos][i] == n - 1) { k = 0 ; continue;}
        int j = SA[rank[pos][i]+1];
        while(i + k < n && j + k < n && str[i+k] == str[j+k]) k++;
        lcp[rank[pos][i] + 1] = k;
    }
}
bool check(int n , int len)
{
    bool flag[3];
    flag[1] = flag[2] = flag[3] = false;
    for(int i = 2 ; i < n ; i++)
    {
        if(lcp[i] >= len){
            if(SA[i] == 0 || SA[i-1] ==0 || SA[i-2]==0)
                flag[0] = true;
            if(SA[i] == n - len || SA[i-1] == n-len || SA[i-2]==n-len)
                flag[2] = true;
            if((SA[i] != 0 && SA[i] != n-len ) || (SA[i-1] != 0 && SA[i-1] != n-len ) || (SA[i-2] != 0 && SA[i-2] != n-len ))
                flag[1] = true;
            if( flag[0] && flag[1] && flag[2])
                return true;
        }
        else
        {
            if( flag[0] && flag[1] && flag[2])
                return true;
            else
                flag[0] = flag[1] = flag[2] = false;
        }
    }
    return false;
}
int binary_search(int n)
{
    int low = 0 , high = n - 1 , mid , ans = -1;
    // fflush(stdin);
    while( low < high)
    {
        mid = (low + high)/2;
        if(check(n , mid))
        {
            low = mid + 1 ; 
            ans = max(ans , mid);
        }
        else
            high = mid;
        fflush(stdin);
    }
    return ans;
}
int main()
{
    char s[1000009];
    scanf("%s",s);
    int n = strlen(s);
    suffixArray(s , n );
    lcpArray(s , n);
    // cout<<check(n , 6)<<endl;
    // for(int i = 0 ; i<n ; i++)
    // {
    //     for(int j = SA[i];j<n;j++)
    //         cout<<s[j];
    //     cout<<" "<<SA[i];
    //     cout<<endl;
    // }
    // for(int i = 0 ;i<n ; i++)
    //     cout<<lcp[i]<<endl;
    int res = binary_search(n);
    if(res == -1)
        cout<<"Just a legend\n";
    else{
        for(int i = 0 ; i < res ; i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}