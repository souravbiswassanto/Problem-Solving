
// Problem: I. Palindrome Pairs
// Contest: Codeforces - Bubble Cup 11 - Finals [Online Mirror, Div. 1]
// URL: https://codeforces.com/problemset/problem/1045/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
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
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2, s3;
    map<string, ll> M; vector<string> vec;
    cin >> n;
    for(int i = 0; i < n ;i++){
        cin >> s;
        s1 = "";
        for(int j = 0; j < s.size();j ++){
            A[s[j] - 97]++;
        }
        for(int j = 0; j < 26; j++){
            if(A[j] % 2)s1 += char(97 + j);
            A[j] = 0;
        }
        //cout << s1 << endl;
        if(s1.size() == 1)cnt++;
        if(s1.size() == 0){
            cntr++;
        } 
        else{
            sum += M[s1]; M[s1]++;
        }
        s2 = s1;
        if(s1.size())vec.pb(s1);
    }
    for(int i = 0; i < vec.size(); i++){
        s = vec[i]; s += 'a'; 
        for(int j = 0; j < 26; j++){
            s[s.size() - 1] = char(97 + j); 
            s2 = s;
            sort(s.begin(), s.end());
            sum += M[s];
            
            s = s2;
        }
    }
    sum += (cntr * (cntr - 1))/2;
    sum += cntr * 1LL * cnt;
    cout << sum << endl;
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
