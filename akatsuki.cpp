/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 20 June 2016 (Monday) 19:53
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int , int>
#define mp make_pair
#define pb push_back
vector<int> hungarianMethod(vector<vector<int> > w) {
    int n = w.size() , m = w[0].size() ,PHI = -1, NOL = -2;
    int INF = INT_MAX;
    bool x[n][m];
    vector<bool> ss(n),st(m);
    vector<int> u(n), v(m), p(m), ls(n), lt(m), a(n);
    int f = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            f = max(f, w[i][j]);

    fill(u.begin(),u.end(), f);
    fill(p.begin(),p.end(), INF);
    fill(lt.begin(),lt.end(), NOL);
    fill(ls.begin(),ls.end(), PHI);
    fill(a.begin(),a.end(), -1);

    while (true) {
        f = -1;
        for (int i = 0; i < n && f == -1; i++)
            if (ls[i] != NOL && !ss[i])
                f = i;

        if (f != -1) {
            ss[f] = true;
            for (int j = 0; j < m; j++)
                if (!x[f][j] && u[f] + v[j] - w[f][j] < p[j]) {
                    lt[j] = f;
                    p[j] = u[f] + v[j] - w[f][j];
                }
        } else {
            for (int i = 0; i < m && f == -1; i++)
                if (lt[i] != NOL && !st[i] && p[i] == 0)
                    f = i;

            if (f == -1) {
                int d1 = INF, d2 = INF, d;
                for (int i : u)
                    d1 = min(d1, i);

                for (int i : p)
                    if (i > 0)
                        d2 = min(d2, i);

                d = min(d1, d2);

                for (int i = 0; i < n; i++)
                    if (ls[i] != NOL)
                        u[i] -= d;

                for (int i = 0; i < m; i++) {
                    if (p[i] == 0)
                        v[i] += d;
                    if (p[i] > 0 && lt[i] != NOL)
                        p[i] -= d;
                }

                if (d2 >= d1)
                    break;
            } else {
                st[f] = true;
                int s = -1;

                for (int i = 0; i < n && s == -1; i++)
                    if (x[i][f])
                        s = i;

                if (s == -1) {
                    for (int l, r; ; f = r) {
                        r = f;
                        l = lt[r];

                        if (r >= 0 && l >= 0)
                            x[l][r] = !x[l][r];
                        else
                            break;

                        r = ls[l];
                        if (r >= 0 && l >= 0)
                            x[l][r] = !x[l][r];
                        else
                            break;
                    }

                    fill(p.begin(),p.end(), INF);
                    fill(lt.begin(),lt.end(), NOL);
                    fill(ls.begin(),ls.end(), NOL);
                    fill(ss.begin(),ss.end(), false);
                    fill(st.begin(),st.end(), false);

                    /*fill(p, INF);
                    fill(lt, NOL);
                    fill(ls, NOL);
                    fill(ss, false);
                    fill(st, false);*/

                    for (int i = 0; i < n; i++) {
                        bool ex = true;
                        for (int j = 0; j < m && ex; j++)
                            ex = !x[i][j];
                        if (ex)
                            ls[i] = PHI;
                    }
                } else
                    ls[s] = f;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (x[i][j]){
                cout<<i<<" "<<j<<endl;
                a[j] = w[i][j];
            }
    return a;
}
int main(){
    int n;
    cin>>n;
    vector<pii > inp1 , inp2;
    for(int i = 0 ; i < n ; i++){
        int inpx , inpy;
        cin>>inpx>>inpy;
        inp1.pb(mp(inpx , inpy));
    }
    for(int i = 0 ; i < n ; i++){
        int inpx , inpy;
        cin>>inpx>>inpy;
        inp2.pb(mp(inpx , inpy));
    }
    vector<vector<int> > w;
    for(int i = 0 ; i < n ; i++){
        vector<int> v;
        for(int j = 0 ; j < n ; j++){
            int dst = abs(inp1[i].first - inp2[j].first) + abs(inp1[i].second - inp2[j].second);
            v.pb(dst);
        }
        w.pb(v);
    }
    for(auto i:w){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    vector<int> v;
    v = hungarianMethod(w);
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
    auto ans = [](vector<int> v) { int sum = 0 ; for(int i = 0 ; i < v.size() ; i++) sum += v[i]; return sum;};
    cout<<ans<<endl;
    return 0;
}