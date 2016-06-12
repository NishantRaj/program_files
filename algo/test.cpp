#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int , int , less<int> , rb_tree_tag> Tree;
Tree RearrangArray(Tree &t , int l , int r){
    Tree rightPart , centerPart , d = t;
    d.split(l-1, centerPart);
    centerPart.split(r , rightPart);
    d.join(rightPart);
    centerPart.join(d);
    return centerPart;
}
int main(){
    int n;
    cin>>n;
    Tree t;
    for(int i = 1 ; i <= n ; i++){
        int inp;
        cin>>inp;
        t[i] = inp;
    }
    int q;
    cin>>q;
    while(q--){
        int l , r;
        cin>>l>>r;
        t=RearrangArray(t , l , r);
    }
    for(auto it:t){
        cout<<it.second<<" ";
    }
    return 0;
}