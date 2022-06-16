
// Problem: Chef and String
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/CHSTR
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    50006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed

typedef pair<int, int> ii;
typedef vector<int> vi;
int Log[MAX+1];
int st[MAX][21 + 1];
ll dp[5004];
void computeLog(){
  Log[1] = 0;
  for (int i = 2; i <= MAX; i++)
    Log[i] = Log[i/2] + 1;
}
char special[] = {'@','$','#', '&', '*','^', '?','\0'};

const int mod = 1000000007;
int inv[MAX],fact[MAX];

int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

void pre(){
	fact[0] = inv[0] = 1;
	for(int i = 1; i < MAX; i++){
		fact[i] = mul(fact[i - 1], i);
	}
	inv[MAX - 1] = bin_pow(fact[MAX - 1], mod - 2);
	for(int i = MAX - 2; i >= 1; i--){
		inv[i] = mul(inv[i + 1] , (i + 1));
	}
}
int ncr(int n, int r){
    if(n < 0 || r < 0 || n < r) return 0;
	int x = fact[n];
	int y = mul(inv[r],inv[n-r]);
	return mul(x, y);
}

class SuffixArray {
private:
  vi RA;                                         // rank array
  
  void countingSort(int k) {                     // O(n)
    int maxi = max(300, n);                      // up to 255 ASCII chars
    vi c(maxi, 0);                               // clear frequency table
    for (int i = 0; i < n; ++i)                  // count the frequency
      ++c[i+k < n ? RA[i+k] : 0];                // of each integer rank
    for (int i = 0, sum = 0; i < maxi; ++i) {
      int t = c[i]; c[i] = sum; sum += t;
    }
    vi tempSA(n);
    for (int i = 0; i < n; ++i)                  // sort SA
      tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    swap(SA, tempSA);                            // update SA
  }

  void constructSA() {                           // can go up to 400K chars
    SA.resize(n);
    iota(SA.begin(), SA.end(), 0);               // the initial SA
    RA.resize(n);
    for (int i = 0; i < n; ++i) RA[i] = T[i];    // initial rankings
    for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
      // this is actually radix sort
      countingSort(k);                           // sort by 2nd item
      countingSort(0);                           // stable-sort by 1st item
      vi tempRA(n);
      int r = 0;
      tempRA[SA[0]] = r;                         // re-ranking process
      for (int i = 1; i < n; ++i)                // compare adj suffixes
        tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
          ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i]+k] == RA[SA[i-1]+k])) ?
            r : ++r;
      swap(RA, tempRA);                          // update RA
      if (RA[SA[n-1]] == n-1) break;             // nice optimization
    }
  }

  void computeLCP() {
    vi Phi(n);
    vi PLCP(n);
    PLCP.resize(n);
    Phi[SA[0]] = -1;                             // default value
    for (int i = 1; i < n; ++i)                  // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];                      // remember prev suffix
    for (int i = 0, L = 0; i < n; ++i) {         // compute PLCP in O(n)
      if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
      while ((i+L < n) && (Phi[i]+L < n) && (T[i+L] == T[Phi[i]+L]))
        ++L;                                     // L incr max n times
      PLCP[i] = L;
      L = max(L-1, 0);                           // L dec max n times
    }
    LCP.resize(n);
    for (int i = 0; i < n; ++i)                  // compute LCP in O(n)
      LCP[i] = PLCP[SA[i]];                      // restore PLCP
  }
  
  void initRMQ(){
      // jhamela hoile eitare clear kore neya jaite pare.
      for (int i = 0; i < n; i++){
          st[i][0] = LCP[i];
      }
      int K = log2(n) + 1;
      for (int j = 1; j <= K; j++){
          for (int i = 0; i + (1 << j) <= n; i++){
              st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
          }
      }
  }

public: // bar bar input nile const ta change kora lagte pare may be
    const char* T;                                 // the input string
    int n;                               // the length of T specail character included
    vi SA;                                         // Suffix Array
    vi LCP;                                        // of adj sorted suffixes
    void init(const char* initialT,  int _n){
        T = initialT;
        n = _n;
        constructSA();                               // O(n log n)
        computeLCP();
        initRMQ();                                // O(n)
    }                                             // where P is found
    int askRMQ(int L, int R){
        // amar mone hoi L + 1 kore query korte hobe
        // jemon 1 theke 3 er modde lcp lagle 2 theke 3 query korte hobe
        int j = Log[R - L + 1];
        int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        return minimum;
    }
    void solve(int q){
        int a, cntr, A[n + 3] = {0};
        int N = n - 1;
        for(int i = 1; i < N; i++){
            int l = 1; cntr = 0;
            for(int j = 1; j < n - 1; j++){
                a = askRMQ(l + 1, j + 1);
                if(a >= i)cntr++;
                else {
                    if(cntr)A[cntr + 1]++;
                    cntr = 0; l = j + 1;
                }
            }
            if(cntr)A[cntr + 1]++;
        }
        dp[1] = (N * (N + 1)) / 2;
        while(q--){
            int query;
            scanf("%d", &query);
            if(n <= query){
                printf("0\n"); continue;
            }
            if(dp[query] != -1){
                printf("%lld\n", dp[query]); continue;
            }
            ll sum = 0;
            for(int i = N; i >= 2; i--){
                if(!A[i] and i < query)continue;
                ll comb = ncr(i, query);
                sum = add(sum,mul(A[i], comb));
            }
            dp[query] = sum;
            printf("%lld\n", dp[query]);
        }
    }
  
};

const int MAX_N = 450010;                        // can go up to 450K chars

char T[MAX_N];
char P[MAX_N];

int main() {
    // suffix array te prothome 0 index a thakbe special character
    // then thakbe jeita choto seita...
    // LCP array te pasha pashi duita SA[i] SA[i + 1] er LCP thakbe.
    computeLog();
    int t; pre();
    scanf("%d", &t);
    while(t --){
        int n, q; mem(dp, -1);
        scanf("%d %d", &n, &q);
        scanf("%s", &T);                               // count n
        T[n++] = '$';  
                                        // add terminating symbol
        SuffixArray S; 
        S.init(T, n);                          // construct SA+LCP
        S.solve(q);
        
    }
    
    return 0;
}