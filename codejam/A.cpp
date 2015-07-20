#include <bits/stdc++.h>
using namespace std;
int reached[109][109];
#define mp make_pair
int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test++){
		int n , m;
		cin>>n>>m;
		string s[n+9];
		for(int i = 0 ; i < n ; i++)
			cin>>s[i];
		int count = 0 , count1 = 0  , flag = false;
		bool tt[109][109];
		memset(tt , 0 , sizeof tt);
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				if(s[i][j] == '.'){
					tt[i][j] = true;
				}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				count = count1 = 0;
				for(int k = 0 ; k < n ; k++)
					if(s[k][j] !='.')
						count++;
				for(int k = 0 ; k < m ; k++)
					if(s[i][k] !='.')
						count1++;
				if(count >=2 || count1 >=2){
					for(int k = 0 ; k < n ; k++)
							tt[k][j] = true;
					for(int k = 0 ; k < m ; k++)
							tt[i][k] == true;
				}
				else if(s[i][j] != '.')
				{
					tt[i][j] = false;
				}
			}
		}

		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				if(tt[i][j] == 0){
					flag  = true ;
					break;
				}
		if(flag){
			cout<<"Case #"<<test<<": IMPOSSIBLE"<<endl;
			continue;
		}
		memset(reached , 0 , sizeof reached);
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				//cout<<endl;
				if(!reached[i][j] && s[i][j] != '.'){
					queue<pair<pair<int , int> , char> > q;
					q.push(mp(mp(i , j) , 0));
					while(!q.empty()){
						int r = q.front().first.first;
						int c = q.front().first.second;
						char parent = q.front().second;
						//cout<<s[r][c]<<" ";
						if(reached[r][c] == 1 && s[r][c] != '.'){
							break;
						}
						if(s[r][c] == '<'){
							if(c-1 < 0){
								ans++;
							}
							else{
								q.push(mp(mp(r , c-1) , '<'));
							}
						}
						if(s[r][c] == '>'){
							if(c+1 >= m){
								ans++;
							}
							else{
								q.push(mp(mp(r , c+1) , '>'));
							}
						}
						if(s[r][c] == '^'){
							if(r-1 < 0)
								ans++;
							else{
								q.push(mp(mp(r-1 , c) , '^'));
							}
						}
						if(s[r][c] == 'v'){
							if(r+1 >=n)
								ans++;
							else{
								q.push(mp(mp(r+1 , c) , 'v'));
							}
						}
						if(s[r][c] == '.'){
							if(parent == '^'){
								if(r-1 < 0)
									ans++;
								else{
									q.push(mp(mp(r-1 , c) , '^'));
								}
							}
							else if(parent == 'v'){
								if(r+1 >= n)
									ans++;
								else{
									q.push(mp(mp(r+1 , c) , 'v'));
								}
							}
							else if(parent == '>'){
								if(c+1 >= m){
									ans++;
								}
								else{
									q.push(mp(mp(r , c+1) , '>'));
								}
							}
							else if(parent == '<')
							{
								if(c-1 < 0){
									ans++;
								}
								else{
									q.push(mp(mp(r , c-1) , '<'));
								}
							}
						}
						q.pop();
						reached[r][c] = 1;


 					}
				}
			}
		}
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
	return 0;
}