
// Problem: Prefix borders
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/BORDER
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
using namespace std;
using namespace __gnu_pbds;

#define   ll long long
#define   MAX 500006
#define   pb     push_back
#define   mp     make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))

vector<ll>prime;
bool mark[10000007];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/
vector <int> g[MAX];
int pa[21][MAX];
int depth[MAX], q;

struct LCA{
    int n, LN;
    LCA(int _n){
        n = _n;
        LN = 20;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j <= n; j ++){
                pa[i][j] = -1;
            }
        }
        dfs(0, -1);
        build();
        solve();
    }
    void dfs(int cur, int prev, int _depth = 0) {
    	pa[0][cur] = prev;
    	depth[cur] = _depth;
    	//cout <<depth[cur]<<" cd "<< cur<< endl;
    	for(int i=0; i<g[cur].size(); i++){
    		if(g[cur][i] != prev) {
    			dfs(g[cur][i], cur, _depth + 1);
    		}
    	}
    }
    
    void build(){
        for(int i=1; i<LN; i++)
			for(int j=0; j<=n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
    }
    int query(int u, int diff) {
        //cout << diff << endl;
    	for(int i=0; i < LN; i++) if((diff>>i)&1) u = pa[i][u];
    	return u;
    }
    void solve(){
        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);
            int dep = depth[a];
            //cout << dep <<" "<< a << endl;
            if(dep < b){
                printf("-1\n");
            }
            else{
                printf("%d\n", query(a, dep - b));
            }
        }
    }
};


struct KMP{
    
    string text, pattern;
    vector<int> lps;
    KMP(string _pattern){
        pattern = _pattern;
        lps.resize((int)pattern.size() + 3, 0);
        for(int i = 0; i <= pattern.size(); i++)g[i].clear(), depth[i] = 0;
        createlps(pattern);
        solve();
    }
    void createlps(string pattern){
        int index = 0;
        g[0].pb(1);
        for(int i = 1; i <  pattern.length(); ){
            if(pattern[i] == pattern[index]){
                lps[i] = index + 1;
                i++;
                index++;
                
            }
            else {
                if(index != 0){
                    index = lps[index - 1];
                }
                else {lps[i] = 0; i++;}
            }
            
            //cout << lps[i] << " " << i << endl;
        }
    }
    void solve(){
        for(int i = 0; i < pattern.size(); i++){
            g[lps[i]].pb(i + 1);
            //cout << lps[i] <<" " << i + 1 << endl;
            //g[i + 1].pb(lps[i]);
        }
        LCA lca(pattern.size());
    }
    
};

int main(){
    int test;
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        //printf("Case %d: ",cs);
        int n;
        scanf("%d %d", &n, &q);
        char ch[200005];
        scanf("%s", ch);
        KMP kmp(ch);
        
    }
    return 0;
}