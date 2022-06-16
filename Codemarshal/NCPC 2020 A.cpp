#include <bits/stdc++.h>
using namespace std;

#define MAX 200010

typedef pair<int, int> ii;
typedef vector<int> vi;
int Log[MAX+1];
int st[MAX][21 + 1];
vector<int> tree[MAX * 4];

void computeLog(){
      Log[1] = 0;
      for (int i = 2; i <= MAX; i++)
        Log[i] = Log[i/2] + 1;
}

class SuffixArray {
private:
  vi RA; 
  //Mergesort Tree part                                        // rank array
  void build(int node, int tb, int te){
	    if(tb > te) return;
		if(tb == te){
			tree[node].push_back(SA[tb]); //value goes here
			return;
		}
		int mid=(tb + te) >> 1; 
		int left = (node * 2);
		int right = node * 2 + 1;
		build(left, tb, mid);
		build(right, mid + 1, te);
		merge(tree[left].begin(),tree[left].end(),tree[right].begin(),tree[right].end(),back_inserter(tree[node]));
	}
	
	// Range query
	int query(int node, int tb, int te, int qb, int qe, int p, int q){
        if(tb > te) return 0;
        if(qb > te || qe < tb)return 0;
        if(qb <= tb && te <= qe){
            int x=lower_bound(tree[node].begin(),tree[node].end(),p)-tree[node].begin();
            int y=upper_bound(tree[node].begin(),tree[node].end(),q)-tree[node].begin();
            return y-x;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        int L = query(left, tb, mid, qb, qe,p, q);
        int R = query(right, mid + 1, te, qb, qe,p, q);
        return L + R;
    }
 // merge sort tree part ends
 
 // Suffix array part
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
  
  //suffix array part ends
  
  //misc starts
  void initRMQ(){
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
  int upper_boundL(int lcp, int pos){
      //ei function r kaj hocce uporer dike kotodur gele lcp beshi ba soman
      // lcp thake.
      // lo 0 kore dilam ar hi = pos korlam. mid obdhi lcp thik thakbe
     int lo = 0, hi = pos, res, mid , val =  pos;                     // range = [0..n-1]
     while (lo <= hi) {                            // find lower bound
          mid = (lo+hi) / 2;                     // this is round down
          res = askRMQ(mid, pos);        // P in suffix SA[mid]?
         if(res >= lcp){
             val = mid - 1;
             hi = mid - 1;
         }
         else  lo = mid + 1;      // notice the >= sign
      }
      return val;
  }
  
  int upper_boundR(int lcp, int pos){
     int lo = pos + 1, hi = n - 1, res, val = pos;                        // range = [0..n-1]
     while (lo <= hi) {                            // find lower bound
         int mid = (lo+hi) / 2;                     // this is round down
          res = askRMQ(pos + 1, mid);        // P in suffix SA[mid]?
         if(res >= lcp){
             val = mid;
             lo = mid + 1;
         }
         else  hi = mid - 1;      // notice the >= sign
      }
      return val;
      
  }

public:
    const char* T;                                 // the input string
    int n;                                   // the length of T
    vi SA;                                         // Suffix Array
    vi LCP; 
    vi rank;
                                           // of adj sorted suffixes
    void init(const char* initialT,  int _n){
        T = initialT;
        n = _n;
        for(int i = 0; i < n * 4; i++)tree[i].clear();
        constructSA();                               // O(n log n)
        computeLCP();
        rank.resize(n);
        for(int i = 0; i < n; i++){
            rank[SA[i]] = i; 
        }
        initRMQ();  
        build(1, 0 , n - 1); 
        solve();                             // O(n)
    }                                             // where P is found
    int askRMQ(int L, int R){
        int j = Log[R - L + 1];
        int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        return minimum;
    }
    void solve(){
        int m;
        scanf("%d", &m);
        int a, b, l, r;
        for(int i = 0; i < m; i ++){
            scanf("%d %d %d %d", &a, &b, &l, &r);
            l--; r--; a--; b--;
            if((r - l) > (b - a)){
                printf("0\n");
                continue;
            }
            b = max(a, b - r + l);
            int left = upper_boundL(r - l + 1, rank[l]);
            int right = upper_boundR(r - l + 1, rank[l]);
            int ans = query(1, 0, n - 1, left, right,a , b);
            printf("%d\n", ans);
            
        }
    }
  
};

const int MAX_N = 200010;                        // can go up to 450K chars

char T[MAX_N];
char P[MAX_N];

int main() {
    int t;
    computeLog();
    scanf("%d", &t);
    while(t--){
        scanf("%s", &T);                               // read T
        int n = (int)strlen(T);                        // count n
        T[n++] = '$';  
                                        // add terminating symbol
        SuffixArray S; 
        S.init(T, n);  
    }
    
    return 0;
}