
// Problem: D. Powerful array
// Contest: Codeforces - Yandex.Algorithm 2011: Round 2
// URL: https://codeforces.com/problemset/problem/86/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   uint    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   aint(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl

int A[MAX];
int B[MAX];
int C[MAX];
vector< int >V;
vector< int >Ans;
vector< pair<int,int> >VP;
map< int,int >M;
vector<int>prime;
bool mark[MAX1];
int N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

int blocksize;
int occ[1000006];
struct query{
    int l, r, idx;/*
    query(int a, int b, int c){
        l = a; r = b; idx = c;
    }
    */
    bool operator <(query other) const {
        if(l / blocksize != other.l / blocksize) return l < other.l;
        return l / blocksize % 2? r > other.r : r < other.r;
    }/*
    bool cmp(Query A, Query B){
  if (A.l / S ！= B.l / S) return A.l < B.l;
  return A.l / S % 2 ? A.r > B.r : A.r < B.r; 
}*/
    
}queries[200006];
/*
bool compare (query a, query b){
    if(a.l / blocksize == b.l/ blocksize)return a.r < b.r;
    return a.l < b.l;
}
*/
struct MO{
   //vector<query> queries;
   vector<ll> ans;
   vector<int> input;
   int n, q, l, r, distinct;
   long long sum ;
   MO(int _n, int _q){
      n = _n; l = 0; r = -1;
      distinct = 0; q = _q;
      blocksize = sqrt(n);
      input.clear(); sum = 0;
   } 
   void mo(){
       for (int i = 0; i < q; i++){
            int a;
            while(l > queries[i].l) {
                a = input[--l];
                sum -= (1LL * a * (occ[a]) * (occ[a]));
                occ[a]++;
                sum += (1LL * a * (occ[a]) * (occ[a]));
            }
            //cout << distinct << endl;
            while(r < queries[i].r){
                a = input[++r];
                
                sum -= (1LL * a * (occ[a]) * (occ[a]));
                occ[a]++;
                sum += (1LL * a * (occ[a]) * (occ[a]));
            } 
            while(l < queries[i].l){
                a = input[l];
                sum -= (1LL * a * (occ[a]) * (occ[a]));
                occ[a]--;
                sum += (1LL * a * (occ[a]) * (occ[a]));
                l++;
                
            }
            while(r > queries[i].r){
                a = input[r];
                sum -= (1LL * a * (occ[a]) * (occ[a]));
                occ[a]--;
                sum += (1LL * a * (occ[a]) * (occ[a]));
                r--;
            } 
            ans[queries[i].idx] = sum;
        }
    }
    void add(int x) { 
        //sum += a[x]; 
    }
    void remove(int x) {
        //sum -= a[x];
    }
    void solve(){
        int a, b;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            input.pb(a);
        }
        ans.resize(q, 0);
        for (int i = 0; i < q; i++){
            scanf("%d %d", &a, &b);
            a--; b--;
            queries[i].l = a; 
            queries[i].r = b; 
            queries[i].idx = i;
            //queries.pb(query(a,b,i));
        }
        sort(queries, queries + q);
       // for (auto it: queries)cout << it.l<<" " << it.r <<" " << it.idx << endl;
        mo();
        for (auto it: ans){
            printf("%lld\n", it);
        }
        
        //
    }
};

int main ()
{
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cnt=0,cntr=0,sum=0,ans=1,check=0;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%d %d", &n, &q);
    MO mos(n, q);
    mos.solve();

    return 0;
}
