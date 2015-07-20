/*
========================================
Name :- Nishant Raj
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Batch :- 2012-2016
========================================*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int cumu[1000009];
int cumu_pos[1000009][2];
int main(){
    int n;
    cin>>n;
    int arr[n+9];
    int max_count=0;
    for(int i= 1;i<=n;i++){
        cin>>arr[i];
        if(cumu[arr[i]]==0)
        {
            cumu_pos[arr[i]][0]=i;
        }
        cumu_pos[arr[i]][1]=i;
        cumu[arr[i]]++;
        max_count =max(max_count , arr[i]);
    } 
    int max_ans=0,max_len=99999999,l,r;
    for(int i = 1 ; i<=max_count;i++){
        max_ans=max(cumu[i],max_ans);
    }
    for(int i = 1 ;i<= max_count;i++){
        if(cumu[i]==max_ans){
            int len = cumu_pos[i][1]-cumu_pos[i][0]+1;
            if(len<max_len){
                l = cumu_pos[i][0],r= cumu_pos[i][1];
                max_len=len;
            }
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}