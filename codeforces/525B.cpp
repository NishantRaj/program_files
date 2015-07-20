#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	ci>>n;
	string s , t;
	cin>>s>>t;
	int total  = 0;
	int save[26][26];
	memset(save , -1 , sizeof save);
	int flag = 0 , index_i , index_j;
	for(int i = 0 ; i < s.size() ; i++){
		int row = s[i] - 97;
		int col = t[i] - 97;
		if(s[i] != t[i]){
			total++;
			for(int j = 0 ; j < 26 ; j++){
				for(int k = 0 ; k < 26 ; k++){
					if(save[j][k] != -1 && flag != 2 && t[save[j][k]] == s[i] && s[save[j][k]] == t[i]){
						flag = 2;
						index_i = save[j][k];
						index_j = i;
					}
					else if(save[j][k] != -1 && flag ==0 && (t[save[j][k]] == s[i] || s[save[j][k]] == t[i])){
						flag = 1;
						index_i = save[j][k];
						index_j = i;
					}
				}
			}
			save[row][col] = i;
		}
		if(flag == 2)
			break;
	}
	if(total == 0)
		cout<<total<<endl<<-1<<" "<<-1<<endl;
	else
		if(flag == 2)
			cout<<total - 2 <<endl<<index_i+1<<" "<<index_j+1<<endl;
		else if(flag == 1)
			cout<<total - 1 <<endl<<index_i+1<<" "<<index_j+1<<endl;
		else
			cout<<total<<endl<<-1<<" "<<-1<<endl;

	return 0;
}