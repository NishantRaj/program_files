#include <bits/stdc++.h>
using namespace std;
// int Xor(list<int> v){
//     if(v.size() == 0)
//         return false;
//     int an = v[0];
//     for(int i = 1 ; i< v.size() ; i++)
//         an^= v[i];
//     if(an == 0)
//         return true;
//     return false;
// }
int ans(map<list<int> , int> &mp , list<int> v , int val){
    // for(auto x:v)
    //     cout<<x<<" ";
    // cout<<endl;
    auto x = mp.find(v);
    if(x != mp.end())
        return 0;
    int sz = v.size();
    if(sz == 2)
        return (val == 0);
    int cnt = 0;
    if(val == 0)
        cnt+=1;
    mp.insert(make_pair(v , 1));
    auto it = v.begin();
    it++;;
    for(int i = 1 ; i < sz && it!=v.end() ;i++){
        auto tk = it;
        auto tr = it;
        tk--;
        int a = *tk , b = *tr;
        tr++;
        v.insert(tr , a+b);
        v.erase(tk);
        v.erase(it);
        val ^= a;
        val ^= b;
        val ^= (a+b);
        cnt += ans(mp , v , val);
        val ^= a;
        val ^= b;
        val ^= (a+b);
        auto save = tr;
        tr--;
        v.erase(tr);
        tr = save;
        v.insert(tr , b);
        tr--;
        v.insert(tr , a);
        it = save;
    }
    return cnt;
}

int main() {
    int n;
    cin>>n;
    list<int> v;
    for(int i = 0 ;i < n ; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    map<list<int> , int> mp;
    int a = *v.begin();
    auto it = v.begin();
    it++;
    for(; it != v.end() ; it++)
        a ^= *it;
    cout<<ans(mp , v , a)<<endl;
    return 0;
}
