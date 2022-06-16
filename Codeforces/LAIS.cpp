
// Problem: A. LaIS
// Contest: Codeforces - 2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)
// URL: https://codeforces.com/contest/1468/problem/A
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1int<<62
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

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

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
int Next[MAX];

struct vertex{
    int val;
    int idxx;
    vertex(){
        val = 0;
        idxx = INT_MAX;
    }
} Null;

vector<vertex> tree;
struct segment_tree{
    int n;
    vertex ini ;
    segment_tree(int _n){
        n = _n;
        tree.clear();
        tree.resize(4 * n);
    }
    
    void update(int idx, int b, int e, int key, vertex value){
        if(e < key || key < b)return;
        if(b == e){
            tree[idx] = value;
            return;
        }
        int left, right, mid;
        left = (idx << 1) + 1;
        right = idx * 2 + 2;
        mid = (b + e) >> 1;
        update(left, b, mid, key,value);
        update(right, mid + 1, e, key,value);
        
        tree[idx] = (tree[left].val > tree[right].val)?tree[left] : tree[right];
    }
    vertex query(int idx, int b, int e, int key){
        //cout<<b<<" "<<e<<" "<<idx<<" "<<key<<" "<<tree[idx]<<endl;
        if(b > key) return Null;
        if(b == e){
            return tree[idx];
        }
        if(e <= key) return tree[idx];
        int left,right,mid;
        left = idx * 2 + 1;
        right = idx * 2 + 2;
        mid = (b + e) / 2;
        vertex L = query(left, b, mid, key);
        vertex R = query(right, mid+1, e, key);
        vertex Max = (L.val > R.val)?L : R;
        return Max;
    }
};

int main ()
{
    fastIO();
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cnt=0,cntr=0,sum=0,check=0;
    int Max= 0;
    string s,s1,s3,s4;

    //cin>>n;
    Null.val = -INT_MAX;
    Null.idxx = INT_MAX;
    cin>>t;

    while(t--){
        cin>>n;
        segment_tree st(n);
        for (int i = 1; i <= n; i++){
            cin >> A[i];
            Next[i] = INT_MAX;
        }
        A[0] = 0;
        stack <int> S;
        S.push(0);
        for (int i = 1; i <= n; i++){
            while(!S.empty() and A[S.top()] <= A[i]){
                Next[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }
        Max = 0;
        for (int i = 1; i <= n; i++){
            //cout << Next[i] << " ";
        }//cout << endl;
        for (int i = 0; i <= n; i++){
            vertex ans = st.query(0, 0, n, A[i]);
            vertex change ;
            if(ans.idxx < i){
                change.val = ans.val + 2;
                change.idxx = Next[i];
                Max = max(Max, ans.val + 2);
            }
            else {
                change.val = ans.val + 1;
                change.idxx = Next[i];
                Max = max(Max, ans.val + 1);
            }
            //cout << i << " " << A[i] <<  " "<< change.val << " " << change.idxx << endl;
            st.update(0, 0 , n, A[i], change);
        }
        printf("%d\n", Max - 1);
        
        
    }

    return 0;
}
