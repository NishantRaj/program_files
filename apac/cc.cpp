#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define inf 1000000000
int main()
{
	int t,p=0;
	cin>>t;
	while (t--){
		int n,m;
		cin>>n>>m;
		map<pair<int,int>,vector<int> > mm;
		map<int,int> mmm;
		int mat[n+1][n+1],used[n+1][n+1];
		vector<int> num[n+1][n+1];
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				mat[i][j] = inf;
		memset(used,-1,sizeof(used));
		vector<int> v;
		for (int i = 0; i<n; i++) mat[i][i] = 0;
		for (int i = 0; i<m; i++){
			int a,b,c;
			cin>>a>>b>>c;
			if (mat[a][b] == inf){
				mat[a][b] = c;
				mat[b][a] = c;
				mm[mp(a,b)].pb(i);
				mm[mp(b,a)].pb(i);
			}
			else if (mat[a][b] != inf){
				if (c < mat[a][b]){
					mat[a][b] = c;
					mat[b][a] = c;
					mm[mp(a,b)].clear();
					mm[mp(b,a)].clear();
					mm[mp(a,b)].pb(i);
					mm[mp(b,a)].pb(i);
				}
				else if (c == mat[a][b]){
					mm[mp(a,b)].pb(i);
					mm[mp(b,a)].pb(i);
				}
			}
		}
		cout<<"Case #"<<p+1<<":\n";
		for (int k = 0; k<n; k++){
			for (int i = 0; i<n; i++){
				for (int j = 0; j<n; j++){
					if (mat[i][j] > mat[i][k] + mat[k][j]){
						mat[i][j] = mat[i][k] + mat[k][j];
						mm.erase(mp(i,j));
						mm.erase(mp(j,i));
					}
				}
			}
		}
		for (auto it = mm.begin(); it != mm.end(); it++){
			for (int i = 0; i<it->second.size(); i++)
				mmm[it->second[i]] = 1;
		}
		for (int i = 0; i<m; i++){
			if (mmm.find(i) == mmm.end())
				cout<<i<<endl;
		}
		p++;
	}
	return 0;
}