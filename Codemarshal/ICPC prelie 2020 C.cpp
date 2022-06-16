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

#define   ll     int
#define   pb     push_back
#define   mp     make_pair
#define   MAX    200006
#define   mem(a,v)   memset(a,v,sizeof(a))

const int mod1 = 999983, base1 = 31;
const int mod2 = 9999991, base2 = 19;
int pwr1[MAX], pwr2[MAX];
int inv1[MAX], inv2[MAX];

int add(int a, int b, int mod) {a += b;  if( a < 0) a += mod; if(a >= mod) a -= mod; return a;}
int sub(int a, int b, int mod) { if( a < 0) a += mod; a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b, int mod) {
	return int(a * 1ll * b % mod);
}

int bin_pow(int o, int s, int mod) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2, mod);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

void init_hash(){
    pwr1[0] = inv1[0] = 1;
    pwr2[0] = inv2[0] = 1;
    int INV_P1 = bin_pow(base1, mod1 - 2, mod1);
    int INV_P2 = bin_pow(base2, mod2 - 2, mod2);
    for (int i = 1; i < MAX; ++i) {
        pwr1[i] = mul(pwr1[i - 1], base1, mod1);
        inv1[i] = mul(inv1[i - 1], INV_P1, mod1);
        
        pwr2[i] = mul(pwr2[i - 1], base2, mod2);
        inv2[i] = mul(inv2[i - 1], INV_P2, mod2);
    }
}

int get(int x, int n){
    return n - x;
}

struct BIT{
    string str;
    int N; vector<int> bt1, bt2;
    void init(string _str, int _N){
        str = _str; N = _N;
        Clear(); updatebt();
    }
    void Clear(){
        bt1.clear(); bt2.clear();
        bt1.resize(N + 2, 0);
        bt2.resize(N + 2, 0);
    }
    void updatebt(){
        for(int i = 1; i < N; i++){
            int val1 = mul(str[i] - 96, pwr1[i], mod1);
            int val2 = mul(str[i] - 96, pwr2[i], mod2);
            update(i, val1, val2);
        }
    }
    void update(int x, int delta1, int delta2){
        for(; x < N; x += x&-x) {
            bt1[x] = add(bt1[x], delta1, mod1);
            bt2[x] = add(bt2[x], delta2, mod2);
        }
    }
    pair<int, int> query(int x){
        int sum1 = 0; int sum2 = 0;
        for(; x > 0; x -= x&-x){
             sum1 = add(sum1, bt1[x], mod1);
             sum2 = add(sum2, bt2[x], mod2);
        }
        return mp(sum1, sum2);
    }
    pair<int, int> querysum(int l, int r){
        pair<int, int> R, L, res;
        R = query(r); L = query(l - 1);
        res.first = sub(R.first, L.first, mod1);
        res.second = sub(R.second , L.second, mod2);
        res.first = mul(res.first, inv1[l], mod1);
        res.second = mul(res.second, inv2[l], mod2);
        return res;
    }
};
int main ()
{
    int a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    int cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    int Max = 0, Min = 0;
    string s, s1, s2,str, revstr;
    int test; char ch;
    init_hash();
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        char st[200005];
        printf("Case %d:\n", cs);
        scanf("%s", st); set<int> ps, ns;
        s = ""; n = strlen(st) + 1; 
        for(int i = 0; st[i] != '\0'; i++)s += st[i];
        str = '$' + s + '#'; reverse(s.begin(), s.end());
        revstr = '$' + s + '#';
        ps.insert(1); ns.insert(-1);
        ps.insert(n); ns.insert(0);
        BIT fh, rh;
        fh.init(str, n); 
        rh.init(revstr, n);
        
        for(int i = 2; i < n; i++){
            if(str[i - 1] != str[i]){
                ps.insert(i); ns.insert(-i);
            }
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d", &p); int revl, revr;
            if(p == 1){
                scanf("%d %d", &l, &r);
                revl = get(r, n); int ql = l;
                revr = get(l, n);
                pair<int, int> h1, h2, h3, h4;
                h1 = fh.querysum(l, r);
                h2 = rh.querysum(revl, revr);
                if(h1.first == h2.first and h1.second == h2.second){
                    printf("0\n");continue;
                }
                int lo = 0, hi = r - l, mid;
                while(lo <= hi){
                    mid = (lo + hi) / 2;
                    int newr = l + mid;
                    revr = revl + mid;
                    h1 = fh.querysum(l, l + mid);
                    h2 = rh.querysum(revl, revr);
                    if(h1.first == h2.first and h1.second == h2.second){
                        lo = mid + 1; 
                    }
                    else hi = mid - 1;
                } 
                int mismatchl = l + lo;
                int mismatchr = r - lo;
                auto it = ns.lower_bound(-mismatchl);
                int idx = *ns.lower_bound(-mismatchr) * - 1;
                l = mismatchl + 1;
                r = mismatchr;
                revl = get(r, n);
                revr = get(l, n);
                h1 = fh.querysum(l, r);
                h2 = rh.querysum(revl, revr);
                l = mismatchl; r = mismatchr - 1;
                revl = get(r, n);
                revr = get(l, n);
                h3 = fh.querysum(l, r);
                h4 = rh.querysum(revl, revr);
                a = *it * -1;
                if(a < ql)a = ql;
                if(h1.first == h2.first and h1.second == h2.second){
                    printf("%d\n", a);
                }
                else if(h3.first == h4.first and h3.second == h4.second){
                    printf("%d\n", idx);
                }
                else printf("-1\n");
                
            }
            else{
                scanf("%d %c", &l, &ch);
                if(str[l] == ch)continue;
                a = ch - str[l];
                str[l] = ch;
                revl = get(l, n);
                fh.update(l, mul(a, pwr1[l], mod1), mul(a, pwr2[l], mod2));
                rh.update(get(l, n), mul(a, pwr1[revl], mod1), mul(a, pwr2[revl], mod2));
                int sl, sr, ssl, ssr; 
                if(str[l - 1] == str[l] and str[l] == str[l + 1]){
                    if(ps.find(l) != ps.end()){
                        ps.erase(l); ns.erase(-l);
                    }
                    if(ps.find(l + 1) != ps.end()){
                        ps.erase(l + 1); ns.erase(-l - 1);
                    }
                }
                if(str[l] == str[l - 1] and str[l] != str[l + 1]){
                    if(ps.find(l) != ps.end()){
                        ps.erase(l); ns.erase(-l);
                    }
                    ps.insert(l + 1); ns.insert((l + 1) * - 1);
                }
                if(str[l] != str[l - 1] and str[l] == str[l + 1]){
                    if(ps.find(l + 1) != ps.end()){
                        ps.erase(l + 1); ns.erase(-l - 1);
                    }
                    ps.insert(l); ns.insert(l * - 1);
                }
                if(str[l] != str[l - 1] and str[l] != str[l + 1]){
                    ps.insert(l); ps.insert(l + 1);
                    ns.insert(-l); ns.insert(-l - 1);
                }
            }
        }
        
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
