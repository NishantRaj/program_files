#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define D long double
#define MOD 1000000007

int main()
{   
    D a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    D g = sqrt(a*a + b*b + a*b);
    D h = sqrt(e*e + f*f + e*f);

    D s = (g + h + c + d) / 2.0;
    D A = sqrt((s - g) * (s - h) * (s - c) * (s - d));
    D eq = sqrt(3.0) / 4.0;
    A = A + e * f * eq + a * b * eq;
    D res = A/eq;
    cout << res << endl;
    return 0;
}