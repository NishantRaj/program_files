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
bool is_valid(string s){
    char delim = '.';
    istringstream iss(s);
    string temp;
    while(getline(iss , temp , delim)){
        if(temp.size() == 0)
            return false;
        if(temp.size() > 1 &&  temp[0] == '0')
            return false;
        int num = stoi(temp);
        // cout<<num<<endl;
        if(num < 0 || num > 255)
            return false;
    }
    return true;
}
string int_to_roman(int a){
    int m = 0;
    string ans = "";
    if(a >= 1000){
        m = a / 1000;
        while(m){
            ans = ans + "M";
            a -= 1000;
            m--;
        }
    }
    if(a>= 900){
        ans = ans + "CM";
        a-=900;
    } else if(a >= 500){
        m = a/500;
        while(m){
            ans = ans + "D";
            a-=500;
            m--;
        }
    }
    if(a>= 400){
        ans = ans + "CD";
        a-=400;
    } else if(a >= 100){
        m = a/100;
        while(m){
            ans = ans + "C";
            a-=100;
            m--;
        }
    }
    if(a >= 90){
        ans = ans + "XC";
        a-=90;
    } else if(a>=50){
        m = a/50;
        while(m){
            ans = ans + "L";
            a-=50;
            m--;
        }
    }
    if(a>=40){
        ans=ans+"XL";
        a-=40;
    } else if(a>=10){
        m = a/10;
        while(m){
            ans = ans + "X";
            a-=10;
            m--;
        }
    }
    if(a>=9){
        ans=ans+"IX";
        a-=9;
    } else if(a>=5){
        m = a/5;
        while(m){
            ans = ans + "V";
            a-=5;
            m--;
        }
    }
    if(a>=4){
        ans = ans+"IV";
        a-=4;
    } else if(a>=1){
        m = a;
        while(m){
            ans = ans+"I";
            m--;
        }
    }
    return ans;
}
void add_b(int a , int b , int &c , int &v){
    // cout<<a<<" "<<b<<" "<<c<<" "<<v<<endl;
    int val = a+b+c;
    if(val == 3){
        c = 1;
        v = 1;
        return ;
    }
    if(val == 2){
        c = 1 ;
        v = 0;
        return ;
    }
    if(val == 1){
        v = 1;
        c = 0;
        return; 
    }
    if(val == 0){
        v = 0;
        c = 0;
        return ;
    }
}
string add(string a , string b){
    int l = a.length() , m = b.length();
    if(l < m)
        swap(a , b);
    if(l < m)
        swap(l , m);
    int i = m-1 , c =0, v =0, f , s, j = 0;
    // cout<<a<<" "<<b<<endl;
    string result="";
    while(i>=0){
        f = a[l - 1 - j]-48;
        s = b[i]-48;
        j++;
        i--;
        add_b(f , s , c, v);
        char temp = v+48;
        result = temp + result;
    }
    i = l - m - 1;
    while(i>=0){
        f = a[i]-48;
        s = 0;
        // cout<<f<<" "<<c<<endl;
        add_b(f , s , c , v);
        char temp = v+48;
        // cout<<v<<" "<<c<<endl;
        result = temp + result;
        i--;
    }
    if(c){
       char temp = c+48;
        result = temp + result; 
    }
    i = 0;
    while(i < result.length() && result[i] == '0')
        i++;
    return result.substr(i);
}
string divide(string s , bool &rem){
    int num = 0 , r;
    string result;
    for(int i = 0 ; i < s.length() ; i++){
        num = num*10 + s[i]-48;
        int q = num/2;
        num = num%2;
        result += to_string(q);
    }
    if(num)
        rem = 1;
    else rem = 0;
    int i=0;
    while(i < result.size() && result[i] == '0')
        i++;
    return result.substr(i);
}
bool check_pow(string s){
    if(s.length() == 0)
        return false;
    string binary= s;
    int i = 0 ;
    bool rem = 0;
    while(true){
        binary = divide(binary , rem);
        // cout<<binary<<endl;
        if(rem)
            return false;
        if(binary.length() == 0)
            return false;
        if(binary == "1")
            return true;
    }
}
string sum(string a , string b , int shift){
    int l = a.length() , m=b.length();
    if(a.length() == 0)
        return b;
    string result = "";
    int carry = 0 , num , count = 0;
    while(count < shift){
        result = a[l-1-count] + result;
        count++;
    }
    int i  , k = 0;
    for(i = l-1-count,k=0 ; i>= 0 ;k++, i--){
        num = a[i] - 48 + b[m-k-1] - 48 + carry;
        char c = num%10 + 48;
        carry = num/10;
        result = c + result;
    }
    while(k < m){
        num = b[m-k-1] - 48 + carry;
        char c = num%10 + 48;
        carry = num/10;
        result = c + result;
        k++;
    }
    // cout<<result<<endl;
    if(carry)
    {
        result = to_string(carry) + result;
    }
    return result;
}
string multiply(string a , string b){
    if(a.length() < b.length())
        swap(a , b);
    int l = a.length() , m=b.length() , carry = 0;
    string temp = "" , result = "";
    for(int i = m-1, k = 0 ; i>= 0 ;k++, i--){
        int mult = b[i] - 48;
        temp = "" , carry=0;
        for(int j = l-1 ; j>=0 ; j--){
            int num = a[j]-48;
            int res = num*mult + carry;
            char c = res%10 + 48;
            temp = c + temp;
            carry = res/10;
        }
        if(carry)
            temp = to_string(carry) + temp;
        cout<<temp<<endl;
        // cout<<temp<<" "<<result<<endl;
        result = sum(result , temp , k);
        cout<<result<<endl;
    }
    int i = 0 ;
    while(i < result.size() && result[i] == '0')
        i++;
    if( i == result.size())
        return "0";
    return result.substr(i);

}
vector<string> print_string(vector<string> v , int a){
    int len = v.size() , count = 0;
    vector<string> ans ,temp;
    string x="";
    for(int i = 0 ; i < len+1 ; i++){
        if(i==len || count + v[i].length()>a){
            int l = temp.size();
            int space = a - count + l;
            if(l == 0)
                return ans;
            if(l == 1){
                x = x + temp[0];
                for(int j = 0 ; j < a - temp[0].length(); j++)
                    x = x + " ";
                ans.push_back(x);
                x = "";
                temp.clear();
            } else{
                int dist = space / (l-1);
                int rem = space%(l-1);
                if(i == len){
                    dist = 1;
                    rem = 0;
                }
                for(int j = 0 ; j < l ; j++){
                    x = x + temp[j];
                    for(int k = 0 ; k < dist && j !=l-1; k ++)
                        x = x + " ";
                    if(rem>0){
                        x = x + " ";
                        rem--;
                    }
                }
                if(i == len){
                    rem = a - count;
                    while(rem >=0 )
                        x = x + " " , rem--;
                }
                ans.push_back(x);
                x = "";
                temp.clear();
            }
            count = 0;
        } 
        if (i<= len-1 && count <= a){
            count += v[i].length() + 1;
            temp.push_back(v[i]);
        }
    }
    return ans;
}
int dvd(int dividend, int divisor) {
    long long divid = dividend , divis = divisor;
    int flag = 0;
    if((divid < 0LL)  && (divis < 0LL))
        flag = 0;
    else if(divid < 0LL || divis < 0LL )
        flag = 1;
    divid = abs(divid);
    divis = abs(divis);
    int count = 0;
    if(divis == 0)
        return INT_MAX;
    if(divis == 1){
        if(flag)
            return -divid;
        else{
            if(divid >INT_MAX)
                return INT_MAX;
            else
                return divid;
        }
    }
    while(divid > divis){
        divid-=divis;
        count++;
    }
    if(flag)
        return -count;
    else
        return count;
}
vector<string> jason(string a){
    int len = a.length() , indent=0;
    vector<string>ans;
    if(len == 0)
        return ans;
    string temp = "";
    char t = '\t';
    for(int i = 0 ; i < len ; i++){
        if(a[i] == '[' || a[i] == '{'){
            if(temp.length() > indent)
                ans.push_back(temp);
            temp = "";
            int ind = indent;
            while(ind){
                temp = temp +t;
                ind--;
            }
            temp = temp + a[i];
            indent++;
            ans.push_back(temp);
            ind = indent;
            temp="";
            while(ind){
                temp += t;
                ind--;
            }
        } else if(a[i] == ','){
            temp += ',';
            ans.push_back(temp);
            int ind = indent;
            temp = "";
            while(ind){
                temp += t;
                ind--;
            }
        } else if(a[i]==']' || a[i] == '}'){
            if(temp.length() > indent){
                ans.push_back(temp);
            }
            temp = "";
            int ind = indent-1;
            while(ind){
                temp = temp +t;
                ind--;
            }
            temp = temp + a[i];
            if(i+1 < a.length() && a[i+1] == ',')
                    temp+="," , i++;
            indent--;
            ans.push_back(temp);
            temp="";
            ind = indent;
            while(ind){
                temp += t;
                ind--;
            }
        }
        else if(a[i] != 32){
            temp += a[i];
        }
    }
    return ans;
}
char count_(vector<int> a , long long mid , int k){
    int count = 0 ,count1 = 0 , flag=0;
    // cout<<mid<<endl;
    for(int i = 0 ; i <a.size() ; i++){
        if(a[i] <= mid)
            count++;
        if(a[i] < mid)
            count1++;
        if(a[i] == mid){
            flag = 1;
        }
    }
    if(count >= k-1 && count1 <= k-1 && flag == 1)
        return 't';
    if(count >= k-1)
        return 'l';
}
int b_search(vector<int> a , int k){
    long long low = 0 , mid , high = INT_MAX;
    while(low < high){
        mid = (low + high)>>1;
        // cout<<mid<<" "<<low<<" "<<high<<endl;
        // cout<<count_(a , mid , k)<<endl;
        if(count_(a , mid , k) == 't'){
            return mid;
        } else if(count_(a , mid , k ) =='l')
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int sum_arr(vector<int> A , int B , int C){
    vector<long long>v;
    long long temp = 0;
    v.push_back(0);
    for(int i = 0 ; i <A.size() ; i++){
        temp += A[i];
        v.push_back(temp);
        // cout<<temp<<" ";
    }
    // cout<<endl;
    int count = 0;
    for(int i = 0 ; i < v.size() ; i++){
        long long low = v[i] + B , high = v[i]+C;
        int left = lower_bound(v.begin()+i+1 , v.end() , low) - v.begin();
        int right = upper_bound(v.begin()+i +1, v.end() , high) - v.begin();
        // cout<<low<<" " << high<<" "<<left<<" "<<right<<endl;
        count += right - left;
    }
    return count;
}
string longest_palindrome(string s){
    string s_;
    if(s.length() == 0)
        s_ = "&#";
    else
        s_ = "&";
    for(int i = 0 ; i < s.length() ; i++){
        s_ = s_ +"#"+s[i];
    }
    s_ += "#$";
    int len = s_.length();
    int c=1 , r = 0 , ans = 0;
    int arr[len+9];
    int pos = 0;
    memset(arr , 0 , sizeof arr );
    for(int i = 1 ; i < len-1 ; i++){
        int mirror = 2*c-i;
        if(r>i) arr[i] = min(r-i , arr[mirror]);
        while(s_[i + arr[i] + 1] == s_[i - arr[i] - 1]) arr[i]++;
        if(i + arr[i] > r) c = i , r = i+arr[i];
        if(ans < arr[i]){
            pos = i;
            ans = arr[i];
        }
    }
    // cout<<pos<<" "<<ans<<endl;
    return s.substr((pos - 1  - ans)/2 , ans);
}
int erase_val(vector<int> A){
    if(A.size() <=1){
        return A.size();
    }
    auto i =A.begin()+1, j = A.begin() ;
    int count=0;
    while(i!= A.end()){
        cout<<*j<<" "<<*i<<endl;
        if(*i == *j){
            // cout<<*i<<" ";
            i++;
            count++;
        }
        else
        {
            // cout<<*j<<" "<<count<<endl;
            auto save = i;
            A.erase(j , j+count);
            count = 0;
            j = save;
            // cout<<*j<<" "<<*i<<endl;
            // i++;
        }
    }
    for(int i = 0 ; i < A.size() ; i++)
        cout<<A[i]<<" ";
    // cout<<endl;
    return A.size();
}
bool braces(string A){
    stack<char> s;
    for(int i = 0 ; i < A.length() ; i++){
        if(A[i] == ')'){
            if(s.top() == '(')
                return true;
            else{
                while(!s.empty() && s.top()!= '('){
                    cout<<s.top()<<endl;
                    s.pop();
                }
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else
            s.push(A[i]);
    }
    return false;
}
string file_path(string A){
    stack<char> s;
    s.push('/');
    for(int i = 0 ; i < A.length() ; i++){
        if(!s.empty() && A[i] == '/'){
            char a = 0 , b = 0;
            if(!s.empty() && s.top() == '/')
                s.pop();
            if(!s.empty() && s.top() == '.'){
                a = '.';
                s.pop();
            }
            if(!s.empty() && s.top() == '.'){
                b = '.';
                s.pop();
            }
            if(a == '.' &&  b == '.'){
                if(!s.empty() && s.top() == '/')
                    s.pop();
                while(!s.empty() && s.top() != '/')
                    s.pop();
                if(!s.empty()) s.pop();
            } else if( a == '.'){
                if(!s.empty() && s.top() == '/')
                    s.pop();
            }
            s.push(A[i]);
        }
        else s.push(A[i]);
    }
    string ans="";
    while(!s.empty()){
        ans = s.top() + ans;
        s.pop();
    }
    if(ans.size() > 0 && ans[ans.size() -1] == '/')
        return ans.substr(0 , ans.size()-1);
    return ans;
}
int sol(vector<int> A){
    stack<int>s;
    int start = 0 , ans = 0;
    while(start < A.size() && A[start] == 0)
        start++;
    while(start < A.size()){
        // cout<<start<<endl;
        if(s.empty() || A[start]< A[s.top()])
            s.push(start++);
        else{
            int pos = s.top();
            s.pop();
            if(!s.empty())
                ans += (start - s.top() -1)*(min(A[start] , A[s.top()]) - A[pos]);
            cout<<ans<<" "<<start<<endl;
        }
        // cout<<start<<endl;
    }
    return ans;
}
std::vector<int> sliding_max(vector<int> A , int B){
    vector<int> ans;
    if(B >= A.size())
    {
        ans.push_back(*max_element(A.begin() , A.end()));
        return ans;
    }
    stack<int>s;
    for(int i = 0 ; i < B ; i++){
        while(!s.empty() && A[s.top()] < A[i])
            s.pop();
        if(s.empty() || A[i] >= A[s.top()])
        s.push(i);
    }
    for(int i = B ; i<A.size() ; i++){
        ans.push_back(A[s.top()]);
        while(!s.empty() && A[s.top()] < A[i])
            s.pop();
        while(!s.empty() && s.top() <= i - B)
            s.pop();
        if(s.empty() || A[s.top()] <= A[i])
            s.push(i);
    }
    if(!s.empty())
        ans.push_back(A[s.top()]);
    return ans;

}
int main(){
    int n , w;
    std::vector<int> A;
    string s;
    cin>>n>>w;
    // getline(cin , s);
    // cout<<file_path(s)<<endl;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    vector<int> j = sliding_max(A , w);
    for(auto i : j){
        cout<<i<<" ";
    }
    cout<<endl;
    // int i = 0 , k =0 , min = INT_MAX;
    // long long ans = 0;
    // for(i = 0 ; i <A.size() ; ){
    //     while(k < A.size() && A[k] <= A[i]){
    //         k++;
    //         mi = min()
    //     }
    //     if(k != A.size())
    //         ans = max(ans, (long long)(k-i)*A[i]);
    //     // cout<<i<<" "<<k<<" "<<ans<<endl;
    //     i = k;
    // }
    // for(int i = A.size() -1 ; i>=0 ; ){
    //     while(k >=0 && A[k] <= A[i])
    //         k--;
    //     if(k!=-1)
    //         ans = max(ans , (long long )(i-k+1)*A[i]);
    //     // cout<<i<<" "<<k<<" "<<ans<<endl;
    //     i = k;
    // }
    // cout<<ans<<endl;
    // cout<<erase_val(v)<<endl;
    // regex digit("(\\+|-)?[[:digit:]]+");
    // regex decimal("((\\+|-)?([[:digit:]]+)?)(\\.(([[:digit:]]+)))?");
    // regex exponent ("(((\\+|-)?(([[:digit:]]+)|((([[:digit:]]+)?)(\\.(([[:digit:]]+)))))))((e)((\\+|-)?)[[:digit:]]+)?");
    // if(regex_match(A , exponent))
    //     cout<<A<<endl;
    // else
    //     cout<<"No";
    // if(P(A))
    //     cout<<A<<endl;
    // else
    //     cout<<"No\n";
    // int len = A.size();
    // vector<string> v;
    // if(len <= 0 && len > 12)
    //     return 0;
    // string temp;
    // for(int i = 1 ; i < len ; i++){
    //     for(int j = i+1 ; j < len ; j++)
    //         for(int k = j+1 ; k < len ; k++){
    //             temp = A.substr(0 , i) + "."+A.substr(i , j-i)+"."+A.substr(j , k - j) + "." + A.substr(k);
    //             if(is_valid(temp)){
    //                 v.push_back(temp);
    //                 cout<<temp<<endl;
    //             }
    //         }
    // }
    // return 0;
    // cout<<int_to_roman(A)<<endl;
    // cout<<sum_arr(v , b , c)<<endl;
}
// ("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?")
// {"attributes":[{"nm":"ACCOUNT","lv":[{"v":{"Id":null,"State":null},"vt":"java.util.Map","cn":1}],"vt":"java.util.Map","status":"SUCCESS","lmd":13585},{"nm":"PROFILE","lv":[{"v":{"Party":null,"Ads":null},"vt":"java.util.Map","cn":2}],"vt":"java.util.Map","status":"SUCCESS","lmd":41962}]}