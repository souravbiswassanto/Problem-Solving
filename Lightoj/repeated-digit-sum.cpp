
// Problem: Repeated Digit Sum
// Contest: LightOJ
// URL: https://lightoj.com/problem/repeated-digit-sum
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

string intst(ll n){
    string s ="";
    while(n){
        int rem = n % 10;
        n /= 10;
        s += char(48 + rem);
    }
    reverse(s.begin(), s.end());
    return s;
}

string sod(string n){
    ll sum = 0; int i = 0;
    while(i < n.size()){
        int a = n[i] - 48;
        sum += a;
        i++;
    }
    n = intst(sum);
    return n;
}

ll f(string n) {
  while (n.size() >= 2) {
    n = sod(n);
  }
  ll a = n[0] - 48;
  return a;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> s >> s1;
        n = s.size();
        m = s1.size();
        sum = 0;
        cout <<"Case "<<++cnt<<": ";
        a = f(s);
        if(s.size() == 1 and s[0] == '0'){
            cout << 0 << endl; continue;
        }
        else if(s1.size() == 1 and s1 == "0"){
            cout << 1 << endl; continue;
        
        }
        if(a == 1){
            cout << 1 << endl;
        }
        else if(a == 2){
            int arr[] = {0, 2,4,8,7,5,1};
            int rem = 0;
            for(int i = 0; i < m; i++){
                c = s1[i] - '0';
                d = rem * 10 + c;
                rem = d % 6;
            }
            if(rem == 0)rem = 6;
            cout << arr[rem] << endl;
        }
        else if(a == 3 or a == 6){
            if(s1 == "1"){
                if(a == 3) cout << 3 << endl;
                else cout << 6 << endl;
            } 
            else cout << 9 << endl;
        }
        else if(a == 4){
            int arr[] = {0,4,7,1};
            int rem = 0;
            for(int i = 0; i < m; i++){
                c = s1[i] - '0';
                d = rem * 10 + c;
                rem = d % 3;
            }
            if(rem == 0)rem = 3;
            cout << arr[rem] << endl;
        }
        else if(a == 5){
            int arr[] = {0, 5,7,8,4,2,1};
            int rem = 0;
            for(int i = 0; i < m; i++){
                c = s1[i] - '0';
                d = rem * 10 + c;
                rem = d % 6;
            }
            if(rem == 0)rem = 6;
            cout << arr[rem] << endl;
        }
        else if(a == 7){
            int arr[] = {0,7,4,1};
            int rem = 0;
            for(int i = 0; i < m; i++){
                c = s1[i] - '0';
                d = rem * 10 + c;
                rem = d % 3;
            }
            if(rem == 0)rem = 3;
            cout << arr[rem] << endl;
        }
        else if(a == 8){
            a = s1[m - 1] - '0';
            if(a % 2)cout << 8 << endl;
            else cout << 1 << endl;
        }
        else cout << 9 << endl;

    }
    /* 
        precedence : ! * / % + - << >> 
        < > <= >= == != & ^ | && ||
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
