
// Problem: F. Mathematical Marathon
// Contest: CodeMarshal - Technocracy 2019 by RUET, IUPC
// URL: https://algo.codemarshal.org/contests/ruet-iupc-19/problems/F
// Memory Limit: 1500 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed

struct edge{
    int vertex, weight;
    edge(int a, int b){
        vertex = a; weight = b;
    }
};
struct node{
    int vertex, cost, gcd;
    node(int a, int b, int c){
        vertex = a;
        cost = b;
        gcd = c;
    }
    bool operator<(node other)const{
        return cost > other.cost;
    }
};

int n, m, x, y, w;
vector<edge> g[MAX];
ll Dijkstra(int dest, int source, int gcd){
    priority_queue<node> pq;
    map<pair<int, int>, ll> dist;
    map<pair<int, pair<int, int>>, ll> mm;
    for(auto v: g[source]){
        int a = __gcd(v.weight, gcd);
        if(a != v.weight)continue;
        pq.push({v.vertex, v.weight, v.weight});
        dist[{v.vertex, v.weight}] = v.weight;
        mm[{v.vertex, {v.weight, v.weight}}] = v.weight;
    }
    while(!pq.empty()){
        
        node u = pq.top(); pq.pop(); ll ucost = dist[{u.vertex, u.gcd}];
        if(u.vertex == dest)return u.cost;
	    if(u.cost != ucost) continue;
	    for(auto v: g[u.vertex]){
	        int a = __gcd(v.weight, u.gcd);
	        if(a != u.gcd)continue;
	        int vv = mm[{u.vertex, {a, u.cost}}];
	        if(vv > v.weight)continue;
	        ll val = 1e14;
	        if(dist.find({v.vertex, a}) != dist.end())val = dist[{v.vertex, a}];
            if(ucost + v.weight < val){
                val = ucost + v.weight;
                pq.push(node(v.vertex, val, a));
                dist[{v.vertex, a}] = val;
                mm[{v.vertex, {a, val}}] = v.weight;
            }
        }
    }
    return 1e14;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d", &x, &y, &w);
            g[x].pb(edge(y, w));
            g[y].pb(edge(x, w));
        }
        int a, b, c;
        printf("Case %d: ", cs);
        scanf("%d %d %d", &a, &b, &c);
        if(a == b){
           printf("0\n"); continue;
        }
        ll ans = Dijkstra(a, b , c);
        
        if(ans > 1e11){
            printf("impossible\n");
        }
        else printf("%lld\n", ans);
        
    }
}
