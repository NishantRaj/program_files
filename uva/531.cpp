#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	string text;
	int count_hash = 0;
	vector<string> v1 , v2;
	v1.pb("0");
	v2.pb("0");
	while(getline(cin , text)){
		if(text == "#")
			count_hash++;
		else{
			istringstream iss(text);
			string s;
			while(iss>>s){
				if(count_hash&1)
					v2.pb(s);
				else
					v1.pb(s);
			}
		}
		if(count_hash >= 2 && count_hash%2 == 0){
			int l1 , l2;
			l1 = v1.size();
			l2 = v2.size();
			int arr[109][109][2];
			for(int i = 0; i <102; i++)
				arr[i][0][0] = 0 ,arr[0][i][0] = 0;

			for(int i = 1 ; i<l1 ; i++){
				for(int j = 1 ; j<l2 ; j++){
					if(v1[i] == v2[j]){
						arr[i][j][1] = 3;
						arr[i][j][0] = arr[i-1][j-1][0] + 1;
					}
					else{
						if(arr[i-1][j][0] > arr[i][j-1][0]){
							arr[i][j][1] = 1;
							arr[i][j][0] = arr[i-1][j][0];
						} else {
							arr[i][j][1] = 2;
							arr[i][j][0] = arr[i][j-1][0];
						}
					}
				}
			}
			vector<string>ans(arr[l1-1][l2-1][0]+9);
			int k = arr[l1-1][l2-1][0];
			int i=l1-1 , j=l2-1;
			while(k){
				if(arr[i][j][1] == 3){
					i--;
					j--;
					ans[k] = v1[i];
					k--;
				} else if(arr[i][j][1] == 1){
					i--;
				} else j--;
			}
			for(i = 1 ; i<= arr[l1-1][l2-1][0] ; i++)
				cout<<ans[i]<<" ";
			cout<<endl;
			v1.clear();
			v2.clear();
			v1.pb("0");
			v2.pb("0");
			count_hash = 0;
		}
	}
	return 0;
}