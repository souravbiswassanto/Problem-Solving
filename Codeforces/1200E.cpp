
// Problem: E. Compress Words
// Contest: Codeforces - Codeforces Round #578 (Div. 2)
// URL: https://codeforces.com/contest/1200/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int N = 1e6 + 4;
const ll P = 233;
const int mod = 1e9 + 123;
//const int mod = 1000058831, base = 193;
//const int mod1 = 1000058831, base1 = 193;
//const int mod2 = 1610612741, base2 = 241;
ll h[N], nh[N], pwr[N], inv[N];
//const int mod = 1000000007;

int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int n, q;
char s[N];

//------------ Hash code Starts
ll bigmod (ll a, ll e) {
    if (e == -1) e = mod - 2;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * a % mod;
        a = a * a % mod, e >>= 1;
    }
    return ret;
}

void init_hash(){
    pwr[0] = inv[0] = 1;
    ll INV_P = bigmod(P, -1);
    for (int i = 1; i < N; ++i) {
        pwr[i] = pwr[i - 1] * P % mod;
        inv[i] = inv[i - 1] * INV_P % mod;
    }
}

void build_hash(){ //1based hashing. so input o 1 based neya lagbe. 
    for (int i = 1; i <= n; ++i) {
        h[i] = (h[i - 1] + (s[i] - '0' + 1) * pwr[i]) % mod;
    }
}
ll get_hash(int l, int r){
    ll one = (h[r] - h[l - 1]) * inv[l] % mod;
    if (one < 0) one += mod; 
    return one;
}

ll get_hash1(int l, int r){
    ll one = (nh[r] - nh[l - 1]) * inv[l] % mod;
    if (one < 0) one += mod; 
    return one;
}
// -------------------Hash code ends


int main(){
    int m, cntr;
    scanf("%d", &n);
    scanf("%s", s + 1);
    init_hash();
    string res = ""; res = s + 1;
    m = strlen(s + 1); 
    for (int i = 1; i <= m; ++i) {
        h[i] = (h[i - 1] + (s[i] - '0' + 1) * pwr[i]) % mod;
    }
    cntr = m + 1;
    for(int i = 2; i <= n; i++){
        scanf("%s", s + 1);
        m = strlen(s + 1);
        
        nh[0] = 0;
        for(int j = 1; j <= m; j++){
            nh[j] = add(nh[j - 1], mul(s[j] - '0' + 1, pwr[j]));
        }
        int idx = 0;
        for(int j = m; j >= 1; j--){
            if(j > res.size())continue;
            ll a = get_hash1(1, j);
            ll b = get_hash(cntr - j, cntr - 1);
            if(a == b){
                idx = j; break;
            }
        }
        for(int j = idx + 1; j <= m; j++){
            res += s[j];
            h[cntr] = add(h[cntr - 1], mul(s[j] - '0' + 1, pwr[cntr]));
            cntr++;
        }
    }
    cout << res << "\n";
    
}