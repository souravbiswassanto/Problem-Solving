
// Problem: Sorting Segments
// Contest: CodeChef - SnackDown 2021 - Online Elimination Round (Rated for all)
// URL: https://www.codechef.com/SNCKEL21/problems/SORTSEGS
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> k;
        cntr = 0; check = 0;
        
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            if(i != A[i])check = 1;
        }
        if(check == 0){
            cout <<0<<"\n";continue;
        }
        cntr = 0; cnt = 0; c = 0;
        for(int i = 1; i <= n; i++){
            if(A[i] != i)break;
            cntr++;cnt++;
        }
        for(int i = n; i>= 1; i--){
            if(A[i] != i)break;
            cntr++; c++;
        }
        if(cntr + k >= n){
            cout << 1 << endl; continue;
        }
        vector<int> vec;
        for(int i = cnt + 1; i <= n - c; i++){
            vec.pb(A[i]- cnt);
        }
        n = vec.size();
        //cout << n <<" n"<< endl;
        a = n - k; check = 0; int flag = 0;
        for(int i = 0; i < n; i++){
            if(vec[i] > k){
                if(i  + k >= n)check = 1;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(vec[i] <= a){
                if(i - k < 0){
                    //cout << i<<" d" << endl;
                    flag = 1;
                }
                break;
            }
        }
        //cout << check <<" "<<flag<<endl;
        if(flag or check)cout << 2 << endl;
        else cout << 3 << endl; 
        /*
        vec.clear();
        for(int i = cnt + 1; i <= n - c; i++){
            vec.pb(A[i]);
        } n = vec.size();
        sort(vec.begin() + a, vec.end());
        sort(vec.begin(), vec.begin() + k);
        
        if(is_sorted(vec.begin(), vec.end())){
            cout << 2 << endl; continue;
        }
        vec.clear();
        cout << 3 << endl;*/
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
