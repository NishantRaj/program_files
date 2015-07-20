
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int , int >
bool check[109][109];
int main(){
    int n , m;
    cin>>m>>n;
    string s[n+9];
    for(int i = 0 ; i < n ; i++)
        cin>>s[i];

    pii source , dest;
    bool first = 1;
    for(int i = 0 ; i < n  ; i ++){
        for(int j = 0 ; j < m ; j++)
            if(s[i][j] == 'C'){
                if(first)
                    source = mp(i , j) , first = 0;
                else{
                    dest = mp(i , j);
                    break;
                }
            }
    }
    
    queue<pair<int , int > > q;
    q.push(source);
    int res = 0;
    int dist[109][109];
    for(int i = 0 ; i < 109 ; i++)
        for(int j = 0 ; j < 109 ; j++)
            dist[i][j] = INT_MAX;

    dist[source.first][source.second]=0;
    while(!q.empty()){
        int i , j ; 
        i = q.front().first;
        j = q.front().second;
        int u = i, v = j;
        while(u+1 < n && s[u+1][j]!='*'  ){
            if( dist[u+1][j] > dist[i][j] + 1){
                q.push(mp(u+1 , j));
                dist[u+1][j] = dist[i][j] +1;
            }
            u++;
        }
        u = i;
        while(u-1 >=0 && s[u-1][j]!='*'  ){
            if(dist[u-1][j] > dist[i][j] + 1){
                q.push(mp(u-1 , v) );
                dist[u-1][j] = dist[i][j] +1;
            }
            u--;
        }
        while(v+1 < m && s[i][v+1]!='*' ){
            if( dist[i][v+1] > dist[i][j] + 1){
                q.push(mp(i , v+1));
                dist[i][v+1] = dist[i][j] +1;
            }
            v++;
        }
        v = j;
        while(v-1 >= 0 && s[i][v-1]!='*'  ){
            if(dist[i][v-1] > dist[i][j] + 1){
                q.push(mp(i , v-1) );
                dist[i][v-1] = dist[i][j] + 1;
            }
            v--;
        }
        q.pop();
    }
    cout<<dist[dest.first][dest.second]-1<<endl;
    return 0;
}