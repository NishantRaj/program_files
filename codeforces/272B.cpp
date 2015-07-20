#include <bits/stdc++.h>
using namespace std;
long long fact(int a)
{
    if(a==0)
        return 1;
    long long res = 1;
    for(int i = 1;i<=a;i++)
        res*=i;
    return res;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int a = 0;
    for(int i=0;i<s1.size();i++)
        if(s1[i]=='+')
            a++;
        else
            a--;
    int re = 0,count = 0;
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i] == '+')
            re++;
        else if(s2[i] == '-')
            re--;
        else
            count++;
    }
    double res = 0;
    long long arr[100][100];
    memset(arr,0,sizeof(arr));
    if(re == a && count == 0)
        res = 1.0;
    else if(count>=1)
    {
        double total=0,sum = (1<<count);
        for(int i=1;i<=10;i++){
            for(int j = 0;j<=i;j++){
                arr[i][j] = fact(i)/(fact(j)*fact(i-j));
            }
        }
        for(int i = -1*count,cnt = 0; i<=count ; i+=2,cnt++)
        {
            if((i+re) == a)
                total += arr[count][cnt];
        }
        res = total / sum;
    }
    else
        res = 0;
    printf("%.9lf\n",res);
    return 0;
}