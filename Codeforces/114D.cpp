
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
const int N = 2e3 + 4;
 ll P = (rng() % 15555717 + 233);
const int mod = 1e9 + 123;
//const int mod = 1000058831, base = 193;
const int mod1 = 1000058831, base1 = 193;
//const int mod2 = 1610612741, base2 = 241;
ll h[N], pwr[N], inv[N];
//const int mod = 1000000007;

int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int n, q, m, k;
char s[N], fh[N], sh[N];
int A[N], B[N];
map<ll, int> M;

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
    ll one = (h[r] - h[l - 1]) * inv[l - 1] % mod;
    if (one < 0) one += mod; 
    return one;
}
// -------------------Hash code ends

ll calc(string s1){
    ll  hash = 0;
    for(int i = 1; i <= s1.size(); i++){
        hash = add(hash, mul((s1[i - 1] - '0' + 1), pwr[i]));
    }
    return hash;
}

int main(){
    P = (P% 2)?P: P + 1;
    scanf("%s %s %s", s + 1, fh + 1, sh + 1);
    // strlen(s + 1) korte hobe size er jonno.
    n = strlen(s + 1); m = strlen(fh + 1); k = strlen(sh + 1);
    init_hash();
    build_hash();
    ll fhval = calc(fh + 1);
    ll shval = calc(sh + 1); 
    
    for(int i = 1; i <= n - m + 1; i++){
        ll hash = get_hash(i, i + m - 1);
        if(hash == fhval)A[i] = 1;
    }
    for(int j = k; j <= n; j++){
        ll hash = get_hash(j - k + 1, j);
        if(hash == shval)B[j] = 1;
    }
    for(int i = 1; i <= n; i++){
        //cout << A[i] <<" "<< B[i]<< endl;aba
        if(A[i] == 1){
            for(int j = i + m - 1; j <= n; j++){
                if(i > j - k + 1)continue;
                if(B[j]){
                    //cout << min(i, j - k + 1) <<" d "<< j << endl;
                    ll hash = get_hash(min(i, j - k + 1), j);
                    M[hash] = 1;
                }
            }
        }
    }
    cout << M.size() << endl;
}