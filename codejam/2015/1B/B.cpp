#include <bits/stdc++.h>
using namespace std;
int x[4] = { 0 , 0 , -1 , 1};
int y[4] = {-1 , 1 , 0 , 0 };
int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test++){
		int r , c , n;
		cin>>r>>c>>n;
		int arr[r+9][c+9], arr1[r+9][c+9], count = 0 , count1 = 0;
		memset(arr , 0 , sizeof arr);
		memset(arr1 , 0 , sizeof arr1);

		for(int i = 1 ; i <= r ; i++){
			int start = i&1 ? 1 : 2;
			for(int j = start ; j<= c ; j+=2)
				arr[i][j] = 1 , count++;
		}
		for(int i = 1 ; i <= r ; i++){
			int start = i&1 ? 2 : 1;
			for(int j = start ; j<= c ; j+=2)
				arr1[i][j] = 1 , count1++;
		}
		if(n <= count){
			cout<<"Case #"<<test<<": "<<0<<endl;
			continue;
		}
		vector<int> save , save1;
		for(int i = 1 ; i <= r ; i++)
		{
			for(int j = 1 ; j <= c ; j++){
				if(arr[i][j] == 0){
					for(int k = 0 ; k < 4 ; k++){
						int row = i+x[k];
						int col = j+y[k];
						if(row>= 1 && row<= r && col>=1 && col<=c)
							arr[i][j] +=1;
					}
					save.push_back(arr[i][j]);
				}
				if(arr1[i][j] == 0){
					for(int k = 0 ; k < 4 ; k++){
						int row = i+x[k];
						int col = j+y[k];
						if(row>= 1 && row<= r && col>=1 && col<=c)
							arr1[i][j] +=1;
					}
					save1.push_back(arr1[i][j]);
				}
			}
		}
		sort(save.begin() , save.end());
		sort(save1.begin() , save1.end());

		int remain = n - count ,remain1 = n - count1 ,ans = 0 , ans1 = 0;
		for(int i = 0 ; i < remain ; i++)
			ans += save[i];
		for(int i = 0 ; i < remain1 ; i++)
			ans1 += save1[i];
		cout<<"Case #"<<test<<": "<<min(ans , ans1)<<endl;
	}
	return 0;
}