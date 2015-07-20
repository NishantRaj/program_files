int *Z_function(char s[])
{
    int *z;
    z = (int*)calloc((strlen(s)+9),sizeof(int));
    int l=0,r=0,n = strlen(s);
    z[0] = n;
    for(int i=1;i<n;i++)
    {
        if(i<=r)
            z[i] = min(r-i+1 , z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if(i+z[i]-1 > r)
            l = i, r = i+ z[i] - 1;
    }
    return z;
}