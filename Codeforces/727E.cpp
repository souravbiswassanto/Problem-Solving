
// Problem: E. Games on a CD
// Contest: Codeforces - Technocup 2017 - Elimination Round 1 (Unofficially Open for Everyone, Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/727/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

const ll N = 2e6 + 4;
const ll P[2] = {39, 47};
const ll mod[2] = {1000000123, 1000058831};
//const ll mod = 1000058831, base = 193;
//const ll mod1 = 1000058831, base1 = 193;
//const ll mod2 = 1610612741, base2 = 241;
ll h[N][2], pwr[N][2], inv[N][2], ans[N];
//const ll mod = 1000000007;

ll add(ll a, ll b, ll MOD) {a += b; if(a >= MOD) a -= MOD; return a;}
ll sub(ll a, ll b, ll MOD) { a -= b; if( a < 0) a += MOD; return a;}
ll mul(ll a, ll b, ll MOD) {
	return (a * 1ll * b % MOD);
}

ll n, q, k, sz;
string s, queryS;
map<ll, ll>M;
map<ll, int> f;

map<ll, ll>M1;
map<ll, int> f1;

//------------ Hash code Starts
ll bigmod (ll a, ll e, ll MOD) {
    if (e == -1) e = MOD - 2;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * a % MOD;
        a = a * a % MOD, e >>= 1;
    }
    return ret;
}
ll gsh(string s){
    ll hash = 0;
    for(ll i = 1; i <= s.size(); i++){
        hash = add(hash, mul(s[i - 1] - 'a' + 1, pwr[i - 1][0], mod[0]), mod[0]);
        // eikhane pwr[i - 1] ar pwr[i] er bepar ta age dekhte hobe.
    }
    return hash;
}
ll gsh1(string s){
    ll hash = 0;
    for(ll i = 1; i <= s.size(); i++){
        hash = add(hash, mul(s[i - 1] - 'a' + 1, pwr[i - 1][1], mod[1]), mod[1]);
    }
    return hash;
}

void init_hash(){
    pwr[0][0] = inv[0][0] = 1LL;
    pwr[0][1] = inv[0][1] = 1LL;
    ll INV_P = bigmod(P[0], -1, mod[0]);
    for (ll i = 1; i < N; ++i) {
        pwr[i][0] = pwr[i - 1][0] * P[0] % mod[0];
        inv[i][0] = inv[i - 1][0] * INV_P % mod[0];
    }
    INV_P = bigmod(P[1], -1, mod[1]);
    for (ll i = 1; i < N; ++i) {
        pwr[i][1] = pwr[i - 1][1] * P[1] % mod[1];
        inv[i][1] = inv[i - 1][1] * INV_P % mod[1];
    }
}

void build_hash(){ 
    for (ll i = 1; i <= sz; ++i) {
        h[i][0] = (h[i - 1][0] + (s[i - 1] - 'a' + 1) *1LL* pwr[i][0]) % mod[0];
        h[i][1] = (h[i - 1][1] + (s[i - 1] - 'a' + 1) *1LL * pwr[i][1]) % mod[1];
    }
}
ll gh(ll l, ll r){
    ll one = mul(sub(h[r][0], h[l - 1][0], mod[0]), inv[l][0], mod[0]);
    if (one < 0) one += mod[0]; 
    return one;
}

ll gh1(ll l, ll r){
    ll one = sub(h[r][1], h[l - 1][1], mod[1]) * inv[l][1] % mod[1];
    if (one < 0) one += mod[1]; 
    return one;
}


int main(){
    cin >> n >> k;
    cin >> s;
    sz = n * k; 
    for(ll i = 0; i < sz; i++){
        s += s[i];
    }
    sz += sz;
    init_hash();
    build_hash();
    
    cin >> q;
    for(ll i = 1; i <= q; i++){
        cin >> queryS;
        ll x = gsh(queryS);
        ll y = gsh1(queryS);
        M[(x << 32) + y] = i;
    }
    bool res = false;
    for(ll i = 1; i <= k; i++){
        bool flag = true;
        //cout << i << endl;
        for(ll j = 1; j <= n; j++){
            ll l = (j - 1) * k + i;
            ll r = l + k - 1;
            ll x = gh(l, r);
            ll y = gh1(l, r);
            //cout << l <<" "<< r << endl;
            //cout << mhash <<" "<<mhash1 << endl;
            if((M.find((x << 32) + y) == M.end()) or (f.find((x << 32) + y) != f.end())){
                flag = false; break;
            }
            ans[j] = M[(x << 32) + y];
            f[(x << 32) + y] = 1;
            //f1[mhash1] = 1;
        }
        if(flag){
            res = true; break;
        }
        f.clear();
        f1.clear();
    }
    
    if(res){
        yes;
        for(ll i = 1; i <= n; i++){
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    else no;
    
    return 0;
}