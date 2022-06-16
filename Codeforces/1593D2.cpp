// Problem: D2. Half of Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/D2
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
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     int
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

//template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[45], B[2000001], C[MAX];

int main ()
{
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e8;
    string s, s1, s2;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        int lim = 2e6;
        Min = INT_MAX; Max = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]); A[i] += 1e6;
            B[A[i]]++;
            Max = max(Max, B[A[i]]);
        }
        check = 0; 
        sort(A, A + n);
        for(int i = 0; i < n; i++){
            B[A[i]]--;
            A[i] -= 1e6;
        }
        if(Max >= n / 2){
            printf("%d\n", -1); continue;
        }
        ans = -1; b = n / 2;
        int arr[n + 3];
        for(int i = lim; i >= 1; i--){
            int mm = 0;
            cntr = 0;
            for(int j = 0; j < n; j++){
                a = A[j] % i;
                if(a < 0)a += i;
                B[a]++; 
                
                arr[cntr++] = a;
            }
            for(int j = 0; j < n; j++){
                a = arr[j];
                mm = max(mm, B[a]);
                B[a]--;
            }
            
            /*for(int j = 0; j < vec.size();j++){
                mm = max(mm, B[vec[j]]);
                B[vec[j]] = 0;
            }*/
            if(mm >= b){
                ans = max(ans, i); break;
            }
        }
        printf("%d\n", ans);

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