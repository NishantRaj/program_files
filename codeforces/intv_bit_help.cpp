#include <bits/stdc++.h>
using namespace std;
#define ll long long
char is_possible(vector<int > &A,int B,long long pages )
{
    // long long pg=0,j=0;//j-> books which needs to be given
    // for( int i=0;i<B;++i)
    // {
    //     pg=0;
    //     for(;j<A.size();++j)
    //     {
    //         if(pg+A[j]<=pages)
    //         {
    //             pg+=A[j];
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
       
    // }
    //  if(j<A.size())
    //     {
    //         return 'b';//not able to give all books
    //     }
        
    //     return 'p';//possible to give all book to all students
    
    long long count = 0 , total_student = 1;
    int i = 0;
    while(i < A.size())
    {
        if(A[i] > pages)
            return 'f';
        if(count + A[i] > pages){
            count = 0;
            total_student++;
        }
        if(count <= pages){
            count += A[i];
            i++;
        }
    }
    if(total_student <= B){
        return 't';
    }
    else
        return 'f';
}



int books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = A.size();
    if(A.size() ==0)
        return NULL;
    cout<<"j";
    if(len < B)
        return -1;
    cout<<"k";
    unsigned long long sum=0;
    for(int i=0;i<A.size();++i)
    {
        sum+=A[i];
    }
    
    unsigned long long st=1,ed=sum+1,mid , ans = LLONG_MAX;
    while(st<ed)
    {
        mid=(st+ed)/2;
        cout<<mid<<" "<<ans<<endl;
        char k=is_possible(A,B,mid);
        
        if(k=='f')
        {
            st=mid+1;
        }
        else if(k=='t')
        {
            ans = min(ans , mid);
            ed=mid;
        }
    }
    return ans;  
}
int main(){
	int n , b;
	cin>>n>>b;
	vector<int> v;
	for(int i = 0 ; i < n ; i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	cout<<books(v , b)<<endl;
}