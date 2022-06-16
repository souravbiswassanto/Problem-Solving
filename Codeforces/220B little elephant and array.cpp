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

int blocksize;
int occ[100006];
struct query{
    int l, r, idx;
    bool operator <(query other) const {
        if(l / blocksize != other.l / blocksize) return l < other.l;
        return l / blocksize % 2? r > other.r : r < other.r;
    }
    
}queries[200006];

struct MO{
   vector<int> ans;
   vector<int> input,Copy;
   int n, q, l, r, distinct;
   MO(int _n, int _q){
      n = _n; l = 0; r = -1;
      distinct = 0; q = _q;
      blocksize = sqrt(n);
      input.clear();
   } 
   void add(int a){
        occ[a]++;
        if(occ[a] == Copy[a] or occ[a] == Copy[a] + 1){
            if(occ[a] == Copy[a])distinct++; 
            else distinct--;
        }
   }
   void remove(int a){
       if(occ[a]==Copy[a] or occ[a] + 1==Copy[a]){
           if(occ[a] == Copy[a])distinct++;
           else distinct--;
       }
   }
   void mo(){
       for (int i = 0; i < q; i++){
            int a;
            while(l > queries[i].l) {
                a = input[--l];
                add(a);
            }
            while(r < queries[i].r){
                a = input[++r];
                add(a);
            } 
            while(l < queries[i].l){
                a = input[l];
                occ[a]--;
                l++;
                remove(a);
            }
            while(r > queries[i].r){
                a = input[r];
                occ[a]--;
                r--;
                remove(a);
            } 
            ans[queries[i].idx] = distinct;
        }
    }
    void Resize(){
        Copy = input;
        sort(Copy.begin(), Copy.end());
        Copy.resize(unique(Copy.begin(), Copy.end())- Copy.begin());
        for(int i = 0; i < n; i++){
            int idx = lower_bound(Copy.begin(), Copy.end(), input[i]) - Copy.begin();
            input[i] = idx;
        }
    }
    void solve(){
        int a, b;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            input.pb(a);
        }
        
        Resize();
        ans.resize(q, 0);
        for (int i = 0; i < q; i++){
            scanf("%d %d", &a, &b);
            a--; b--;
            queries[i].l = a; 
            queries[i].r = b; 
            queries[i].idx = i;
        }
        sort(queries, queries + q);
        mo();
        for (auto it: ans){
            printf("%d\n", it);
        }
    }
};

int main ()
{
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cnt=0,cntr=0,sum=0,ans=1,check=0;
    string s,s1,s3,s4;

    scanf("%d %d", &n, &q);
    MO mos(n, q);
    mos.solve();

    return 0;
}
