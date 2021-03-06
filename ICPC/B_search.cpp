#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
long long a[1000010];
long long get(long long num,int n)
{
    int ans=upper_bound(a,a+n,num)-a;
    ans--;
    return ans;
}
bool isSquare(long long x)
{
    int p=(int)(sqrt(x*1.0)+1e-8);
    if ((long long)p*p==x||(long long)(p-1)*(p-1)==x||(long long)(p+1)*(p+1)==x) return true;
    return false;
}
int getPos(long long x)
{
    int p=(int)(sqrt(x*1.0)+1e-8)+10;
    while ((long long)p*p>x) p--;
    return p;
}
int main()
{
    long long Up=1;
    for (int i=1;i<=5;i++)
        Up=Up*3141;
    int cnt=0;
    for (int i=2;(long long)i*i*i<=Up;i++)
    {
        long long x=(long long)i*i;
        while (x<=Up/i)
        {
            x*=i;
            if (!isSquare(x)) a[cnt++]=x;
        }
    }
    sort(a,a+cnt);
    cnt=unique(a,a+cnt)-a;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        long long x;
        scanf("%lld",&x);
        if (x==0||x==1)
        {
            printf("%d",x==0?2:1);
        }
        else{
        long long pos=get(x,cnt);
        if (a[pos]==x||isSquare(x))
        {
            pos+=getPos(x)-1;
            printf("%d",pos+1);
        }
        else
        {
            int ans=0;
            pos+=getPos(x)-1;
            x-=pos+1;
            x++;
            long long R=1LL;
            while (R<x)
            {
                ans++;
                R*=2;
            }
            if (R==x) printf("%d",ans);
            else
            {
                long long L=R/2;
                while (L<R)
                {
                    long long M=(L+R)/2;
                    ans++;
                    if (M==x) break;
                    else if (M<x) L=M;
                    else R=M;
                }
                printf("%d",ans);
            }
        }}
        if (i!=n-1) printf(" ");
        else puts("");
    }
    return 0;
}