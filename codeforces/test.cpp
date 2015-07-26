#include <bits/stdc++.h>
using namespace std;
int gcd(int a , int b){
    return b == 0 ? a : gcd(b , a%b);
}
int lower(vector<int > A , int key){
    int len = A.size();
    int low = 0 , high = len , mid;
    while(low < high){
        mid = (low+high)>>1;
        if(key <= A[mid])
            high = mid;
        else
            low = mid+1;
    }
    return high;
}
int upper(vector<int > A , int key){
    int len = A.size();
    int low = 0 , high = len , mid;
    while(low < high){
        mid = (low+high)>>1;
        if(A[mid] > key)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}
int count(vector<int > arr,int k,int n)
{
    int p=-1,q = -1;
    for(int a = n ; a>0 ; a/=2){
        while(p+a < n && arr[p+a] < k) p+=a;
        while(q+a < n && arr[q+a] <= k) q+=a;
    }
    cout<<q<<" "<<p<<endl;
    return (q-p);
}
// bool check(int A , vector<int> v , long long mid){
//     int paint_count =0 , n = v.size() , i = 0;
//     long long count = 0 , tot = 1;
//     while(i < n)
//     {
//         if((long long)v[i] > mid)
//             return false;
//         if(count + (long long )v[i] > mid){
//             tot++;
//             count = 0;
//         }
//         if(count <= mid){
//             count += (long long)v[i];
//             i++;
//         }
//     }
//     if(tot <= A)
//         return true;
//     return false;
// }
int search_(vector<int> a){
    int len = a.size();
    int low = 0 , high = len-1  , mid;
    cout<<low<<" "<<high<<endl;
    while(low < high){
        mid = (low+high)>>1;
        int next = (mid+1)%len;
        int prev = (mid + len - 1)%len;
        if(a[low] <= a[high])
            return low;
        if(a[mid] <= a[next]&& a[mid] <= a[prev])
            return mid;
        if(a[mid] <= a[high])
            high = mid;
        else if(a[mid] >= a[low])
            low = mid+1;
    }
    return low;
}
int search_num(vector<int> a , int low , int high , int key){
    int mid;
    while(low < high){
        mid = (low + high)>>1;
        if(a[mid] == key)
            return mid;
        if(a[mid]>key)
            high = mid;
        else
            low = mid+1;
    }
    return -1;
}
int i= 0;
bool digit(string s){
    cout<<"digit "<<s[i]<<endl;
    if(i == s.size())
        return true;
    if(isdigit(s[i])){
        i++;
        if(digit(s))
            return true;
        else
            return false;
    }
    if(s[i] == ' '){
        i++;
        if(digit(s))
            return true;
        else
            return false;
    }
    return false;
}
bool R(string s){
    cout<<"R "<<s[i]<<endl;
    int save = i;
    if(i == s.size())
        return false;
    if(s[i] == '+' || s[i] == '-'){
        i++;
        if(digit(s))
            return true;
        else
            return false;
    }
    if(digit(s))
        return true;
    return false;
}
bool Q(string s){
    cout<<"Q "<<s[i]<<endl;
    int save = i;
    if(isdigit(s[i])){
        i++;
        if(Q(s))
            return true;
        else
            return false;
    }
    i = save;
    if(s[i] == 'e'){
        i++;
        if(R(s))
            return true;
        else
            return false;
    }
    i = save;
    if(s[i] == ' ')
        if(digit(s))
            return true;
        else
            return false;
    if(i == s.size())
        return true;
    return false;
}
bool T(string s){
    cout<<"T "<<s[i]<<endl;
    int save = i;
    if(isdigit(s[i])){
        i++;
        if(T(s))
            return true;
        else
            return false;
    }
    i = save;
    if(s[i] == '.'){
        i++;
        if(isdigit(s[i])){
            i++;
            if(Q(s))
                return true;
            else return false;
        } else return false;
    }
    i = save;
    if(s[i] == 'e'){
        i++;
        if(R(s))
            return true;
        else
            return false;
    }
    if(i == s.size())
        return true;
    else
        return false;
}
bool P(string s){
    cout<<"P "<<s[i]<<endl;
    int save = i;
    if(s[i] == '+' || s[i] == '-'){
        i++;
        if(isdigit(s[i]) || s[i] == '.')
            if(P(s))
                return true;
        return false;
    }
    i = save;
    if(s[i] == '.'){
        i++;
        if(isdigit(s[i])){
            i++;
            if(Q(s))
                return true;
            else return false;
        } else return false;
    }
    i = save;
    if(isdigit(s[i])){
        i++;
        if(T(s))
            return true;
        else
            return false;
    }
    if(i == s.size())
        return true;
    else
        return false;
}
int main(){
    string A = "32467826570812365702673647926314796457921365792637946579269236594265794625762375621765476592146926410592659021465904652.687236478235187653874637824647856428756387264578245676579032657906097542609  ";
    // cin>>A;
    regex digit("(\\+|-)?[[:digit:]]+");
    regex decimal("((\\+|-)?([[:digit:]]+)?)(\\.(([[:digit:]]+)))?");
    regex exponent ("(((\\+|-)?(([[:digit:]]+)|((([[:digit:]]+)?)(\\.(([[:digit:]]+)))))))((e)((\\+|-)?)[[:digit:]]+)?");
    // if(regex_match(A , exponent))
    //     cout<<A<<endl;
    // else
    //     cout<<"No";
    if(P(A))
        cout<<A<<endl;
    else
        cout<<"No\n";
}
// ("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?")