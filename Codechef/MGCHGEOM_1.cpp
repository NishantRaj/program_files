#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pll pair < long long , long long >
#define ll long long
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void pr_uint(unsigned long long  n) {
    if (n / 10 != 0)
        pr_uint(n / 10);
    putchar_unlocked((n % 10) + '0');
}

void pr_int(long long n) {
    if (n < 0) {
        putchar_unlocked('-');
        n = -n;
    }
    pr_uint((unsigned long long) n);
}
long long orientation(pll P,pll Q,pll R){
    return  (Q.first-P.first)*(R.second-P.second)-(R.first-P.first)*(Q.second-P.second);
}
int slope_compare(pll &a , pll &b , pll &c , pll &d){
    if((b.second - a.second)*(d.first - c.first) > (b.first - a.first)*(d.second - c.second))
        return 1;
    return 0;
}
void convex_hull(vector<pll > &P,vector<pll > &l,vector<pll > &u){
    int j=0,k=0,n=P.size();
    sort(P.begin(),P.end());
    u.resize(2*n);
    l.resize(2*n);
    for(int i=0;i<n;i++)
    {
        while(j>=2 && orientation(l[j-2],l[j-1],P[i])<=0)
            j--;
        while(k>=2 && orientation(u[k-2],u[k-1],P[i])>=0)
            k--;
        l[j++]=P[i];
        u[k++]=P[i];
    }
    u.resize(k);
    l.resize(j);
}
long long Dist(pll P ,pll Q){
    return abs(P.first*P.first - Q.first*Q.first)+abs(P.second*P.second - Q.second*Q.second);
}
struct cmp{
    bool operator()(const pll &a , const pll &b){
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }
};
void area(vector<pll > &v){
    long long area = 0;
    int sz = v.size();
    for(int i = 0 ; i < sz ; i++){
        // cout<<v[i].x << " " <<v[i].y<<endl;
        pll p2 = v[(i+1)%sz];
        area += v[i].first*p2.second - v[i].second*p2.first;
    }
    printf("%.1lf\n", abs(area)/2.0);
}
int main()
{
    int t;
    scanint(t);
    while(t--)
    {
        int n;
        scanint(n);
        map<pll , int , cmp> ds;
        while(n--){
            char c;
            scanf("%c ",&c);
            int x , y;
            scanint(x);scanint(y);
            pll pnt = mp(x , y);
            if(c == '+'){
                ds[pnt] +=1;
                vector<pll >v,u,l;
                for(auto it:ds){
                    if(it.second > 0){
                        v.pb(it.first);
                    }
                }
                if(v.size() < 3){
                    printf("0.0\n");
                } else{
                    convex_hull(v , l , u);
                    l.insert(l.end() , u.rbegin()+1 , u.rend() -1 );
                    area(l);
                }
                // for(auto it:v)
                //     cout<<it.first<<" "<<it.second<<endl;
                // cout<<endl<<endl;
                // for(auto it:l)
                //     cout<<it.first<<" "<<it.second<<endl;
                // cout<<endl<<endl;
                // for(auto it:u)
                //     cout<<it.first<<" "<<it.second<<endl;
            } else if(c == '-'){
                ds[pnt] -= 1;
                auto it = ds.find(pnt);
                if(it->second <= 0)
                    ds.erase(it);
                vector<pll >v,u,l;
                for(auto it:ds){
                    if(it.second > 0){
                        v.pb(it.first);
                    }
                }
                if(v.size() < 3){
                    printf("0.0\n");
                } else{
                    convex_hull(v , l , u);
                    l.insert(l.end() , u.rbegin()+1 , u.rend() -1 );
                    area(l);
                }
                // for(auto it:l)
                //     cout<<it.first<<" "<<it.second<<endl;
                // cout<<endl<<endl;
                // for(auto it:u)
                //     cout<<it.first<<" "<<it.second<<endl;
            }
        }
        // vector<pll >v,u,l;
        // int n;
        // scanint(n);
        // int k1;
        // for(int i=0;i<n;i++){
        //     scanint(k1);
        //     v.push_back(make_pair(i+1,k1));
        // }
        // if(n==1){
        //     printf("0\n");
        //     continue;
        // }
        // convex_hull(v,l,u);//conpute convex hull for set of points .
        // int i = 0 , j = l.size() -1;
        // ll ans = 0;
        // l.insert(l.end() , u.begin() , u.end());
        // for(int i = 0 ; i < l.size() ; i++){ // Brute Force to find points having maximum distance.
        //  for(int j = 0 ; j < l.size() ; j++){
        //   ans = max(ans , Dist(l[i] , l[j]));
        //  }
        // }
        // pr_int(ans);
        // putchar_unlocked('\n');
    }
}