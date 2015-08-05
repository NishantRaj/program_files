#include <bits/stdc++.h>
using namespace std;
int mark[1000009];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    if(n == 1){
        cout<<0<<endl;
        return 0;
    }
    int arr[n+9];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    stack<int> s , temp;
    s.push(0);
    for(int i = 1 ; i < n ; i++){
        if(!s.empty() && arr[s.top()] >= arr[i]){
            s.push(i);
        }
    }
    vector<int> v;
    v.push_back(0);
    while(!s.empty()){
        mark[s.top()] = 1;
        //cout<<arr[s.top()]<<endl;
        // v.push_back(s.top());
        s.pop();
    }
    int ans = 0 , count = 0 , mi = INT_MAX , save = 0;
    // for(int i = 1 ; i < n ; i++){
    //     //cout<<count<<endl;
    //     if(!mark[i] && arr[i-1] >= arr[i]){
    //         if(arr[i] <= mi){
    //             count = max(count , save+1);
    //         }else
    //             count++;
    //     } else if(!mark[i] && arr[i-1] < arr[i]){
    //         mi = min(arr[i-1] , mi);
    //         ans = max(ans , count);
    //         save = ans;
    //         count = 1;
    //     }
    //     else {
    //         ans = max(count , ans);
    //         count = 0;
    //     }
    // }
    for(int i = 0 ; i < n ; i++){
        if(!mark[i]){
            if(s.empty() || s.top() >= arr[i]){
                s.push(arr[i]);
                int count = 0;
                while(!temp.empty()){
                    count++;
                    temp.pop();
                }
                ans = max(count , ans);
            }
            else if(!s.empty() && s.top() < arr[i]){
                temp.push(arr[i]);
            }
        }
        else{
            count = 0;
            while(!s.empty()){
                s.pop();
                count++;
            }
            ans = max(ans , count);
            count = 0;
            while(!temp.empty()){
                temp.pop();
                count++;
            }
            ans = max(ans , count);
        }
    }
    count = 0;
    while(!s.empty()){
        count++;
        s.pop();
    }
    ans = max(ans , count);
    count = 0;
    while(!temp.empty()){
        count++;
        temp.pop();
    }
    ans = max(ans , count);
    cout<<ans<<endl;
    return 0;
}
