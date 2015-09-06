/***
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists. 

For example, 
List 1: [4, 10, 15, 24, 26] 
List 2: [0, 9, 12, 20] 
List 3: [5, 18, 22, 30] 

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
***/
#include <bits/stdc++.h>
using namespace std;
int k;
int binary_search(vector<pair<int , int > > &v , bool check[],int start ,int &range){
    int low = start, high = v.size(), mid;
    range = INT_MAX;
    int ans = INT_MAX;
    while(low < high){
        mid = (low + high)/2;
        int count = 0;
        memset(check , 0 , sizeof check);
        for(int i = 0 ; i < v.size() ; i++){
              if(v[i].first >= v[start].first && v[i].first <= v[mid].first && check[v[i].second]==false ){
                  count++;
                  check[v[i].second] = true;
              }
        }
        if(count >= k){
            high = mid;
            range = min(mid - start , range);
            ans = min(ans , mid);
        } else {
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<pair<int , int> > v;
    cin>>k;
    vector<int> list[10];
    int n;
    for(int i = 0 ; i < k ; i++){
        cin>>n;
        for(int j = 0 ; j < n ; j++){
            int temp;
            cin>>temp;
            list[i].push_back(temp);
        }
    }
    bool check[k];
    memset(check , 0 , sizeof check);
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < list[i].size() ; j++){
            v.push_back(make_pair(list[i][j] , i));
        }
    }
    sort(v.begin() , v.end());
    int range = INT_MAX ;
    long long final_ans = INT_MAX;
    pair<int , int> pii;
    for(int i = 0 ; i < v.size() ; i++){
        range = INT_MAX ;
        memset(check , 0 , sizeof check);
        int ans = binary_search(v ,check , i , range);
        if(range < final_ans){
            pii = make_pair(v[i].first , v[ans].first);
        }
    }
    cout<<pii.first<<" "<<pii.second<<endl;
    return 0;
    
}