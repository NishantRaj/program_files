/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 14 September 2015 (Monday) 19:32
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define pql priority_queue<int , vector<int> , less<int> > 
#define pqg priority_queue<int , vector<int> , greater<int> >
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int get_median(int stream , int med , pql &left , pqg &right){
    int median = med;
    int balance = left.size() - right.size();
    if(stream == -1){
        if(!left.empty() && !right.empty() &&  median == left.top() && median == right.top()){
            if(left.size() < right.size())
                right.pop();
            else 
                left.pop();
        }
        else if(!left.empty() && median == left.top())
            left.pop();
        else if(!right.empty() && median == right.top())
            right.pop();
        if((left.size() ==0) && (right.size() == 0)){
            return 0;
        } else if(left.size() == right.size()){
            return left.top();
        } else if(left.size() < right.size()){
            return right.top();
        } else if(left.size() > right.size()){
            return left.top();
        }
    }
    if(balance == 0){
        if(stream < median){
            left.push(stream);
            median = left.top();
        } else{
            right.push(stream);
            median = right.top();
        }
    } else if(balance > 0){
        if(stream < median){
            right.push(left.top());
            left.pop();
            left.push(stream);
        } else{
            right.push(stream);
        }
        median = min(left.top() , right.top());
    } else if(balance <  0){
        if(stream < median){
            left.push(stream);
        } else{
            left.push(right.top());
            right.pop();
            right.push(stream);
        }
        median = min(left.top() ,  right.top());
    }
    return median;
}
int main(){
    
    int t;
    //scanf("%d",&t);
    scanint(t);
    while(t--){
        pql left;
        pqg right;
        int n;
        int median = 0;
        while(true){
            //scanf("%d" , &n);
            scanint(n);
            if(n == 0){
                break;
            }
            if(n == -1)
                printf("%d\n", median);
            median = get_median(n , median , left , right);
        }
    }
    return 0;
}