#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len = s.length();
	int flag = 0;
	int ans = 0;
		for(int i = 0 ; i < len ; i++){
			for(int j = i+1 ; j< len ; j++){
				for(int k = j+1 ; k<len ; k++){
					int num = ((s[i]-48)*10 +  s[j]-48)*10 + s[k]-48;
					if(num%8 == 0){
						flag = 1;
						ans = num;
					}
				}
			}
		}
		for(int i = 0 ; i < len ; i++){
			for(int j = i+1 ; j< len ; j++){
				int num = (s[i]-48)*10 +  s[j]-48;
				if(num%8 == 0){
						flag = 1;
						ans = num;
					}
			}
		}
		for(int i = 0 ; i < len ; i++){
			if((s[i]-48) %8 == 0){
				flag = 1;
				ans = s[i]-48;
			}
		}	
	if(flag){
		cout<<"YES\n"<<ans<<endl;
	}
	else
		cout<<"NO\n";
	return 0;
}