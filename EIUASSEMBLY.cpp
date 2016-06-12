/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 June 2016 (Friday) 10:26
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int , int>
#define ll long long
#define mp make_pair
#define pb push_back
bool check(vector<int> &p, vector<int> &m, ll &total_cost, ll level){
    ll total = 0;
    for(int i = 0 ; i < p.size() ; i++){
        ll diff = level - p[i];
        if(diff > 0)
            total += diff*(ll)m[i];
        if(total > total_cost)
            return false;
    }
    return true;
}
ll b_search(vector<int> &p, vector<int> &m , ll total_cost){
    ll low = 0 , high = (LLONG_MAX/10), mid , ans = -1;
    while(low < high){
        mid = (low + high) >> 1;
        if(check(p, m, total_cost , mid)){
            low = mid+1;
            ans = max(mid , ans);
        } else high = mid;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n , total_cost;
        scanf("%lld%lld", &n , &total_cost);
        vector<int> p(n) , m(n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d" , &p[i] , &m[i]);
        }
        printf("%lld\n" , b_search(p , m , total_cost));
    }
    return 0;
}