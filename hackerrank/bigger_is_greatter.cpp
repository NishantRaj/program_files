#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		char s[109];
		scanf("%s",s);
		int j = strlen(s) - 1;
		while(j>0 && s[j-1] > s[j])
			j--;
		if(j==0)
			cout<<"no answer\n";
		else{
			for(int i = 0 ; i < j ; i++)
				cout<<s[i];
			cout<<s[j+1]<<s[j];
			for(int i = )
		}
	}
}