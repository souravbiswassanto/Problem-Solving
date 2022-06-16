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
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}-

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
int check = 0;
vector<int> v;
bool dp[50005][100];
bool vis[50005][100];
map<string, int> bad, Map;
int n, cnt; string str;

bool brute(int i, string s){
    if(i == n){
        if(bad[s])return 0;
        return 1;
    }
    if(bad[s])return 0; 
    if(Map.find(s) == Map.end())Map[s] = cnt++;
    int a = Map[s];
    bool &ret = dp[i][a];
    if(vis[i][a])return ret;
    vis[i][a] = 1;
    ret = 0;
    if(str[i] == '?'){
        s += '1';
        int a, b;
        a = s.size() < 6? 0 : 1;
        b = s.size() < 6? s.size(): 5;
        if (!bad[s] and !bad[s.substr(a, b)])ret |= brute(i + 1, s.substr(a, b));
        s.erase(s.size()-1 , 1);
        s += '0'; 
        if(!bad[s] and !bad[s.substr(a, b)])ret |= brute(i + 1, s.substr(a, b));
    }
    else{
        s += str[i];
        int a, b;
        a = s.size() < 6? 0: 1;
        b = s.size() < 6? s.size(): 5;
        if(!bad[s] and !bad[s.substr(a, b)])ret |= brute(i + 1, s.substr(a, b));
    }
    return ret;
}

int main ()
{
    fastIO();
    ll a, b, c, d, m, k, l, p, q, r, t, x, y;
    ll  cntr = 0, sum = 0,ans = 1, heck = 0;
    ll Max = 0, Min = 2e18;
    
    
    cin >> t;

    while(t--){
        cin >> n;
        cin >> str; 
        Map.clear();
        for(int i = 0; i < 32; i++){
            string s ="", s1;
            for(int j = 0; j < 5; j++){
                if(i & (1<<j))s += '1';
                else s += '0';
            }
            s1 = s; reverse(s1.begin(), s1.end());
            if(s1 == s){
                bad[s] = 1;
                Map[s] = ++cntr;
            }
        }
        for(int i = 0; i < 64; i++){
            string s ="", s1;
            for(int j = 0; j < 6; j++){
                if(i & (1<<j))s += '1';
                else s += '0';
            }
            s1 = s; reverse(s1.begin(), s1.end());
            if(s1 == s){
                bad[s] = 1;
            }
        }
        
        cnt = cntr;
        mem(dp, 0); mem(vis, 0);
        check = brute(0, "");
        cout << "Case #"<<ans++ <<": ";
        if(check)cout <<"POSSIBLE"<<endl;
        else cout <<"IMPOSSIBLE"<<endl;

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

/*

5
8
11?????0
10
??1???????
10
????????11
15
1???????1?????0
15
???????????????

11010000
Case #1: POSSIBLE
0010110000
Case #2: POSSIBLE
0000101111
Case #3: POSSIBLE
111010011010000
Case #4: POSSIBLE
000010110010110
Case #5: POSSIBLE
*/