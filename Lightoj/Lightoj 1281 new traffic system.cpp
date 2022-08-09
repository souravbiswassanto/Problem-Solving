
// Problem: New Traffic System
// Contest: LightOJ
// URL: https://lightoj.com/problem/new-traffic-system
// Memory Limit: 64 MB
// Time Limit: 2000 ms
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
#define   MAX    10006
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
    int vertex, weight, type;
    edge(int a, int b, int c){
        vertex = a; weight = b; type = c;
    }
};
struct node{
    int vertex, cost, newroad;
    node(int a, int b, int c){
        vertex = a;
        cost = b;
        newroad = c;
    }
    bool operator<(node other)const{
        if(cost == other.cost)return newroad < other.newroad;
        return cost > other.cost;
    }
};

int n, m, x, y, w, k, d;
vector<edge> g[MAX];
priority_queue<node> pq;
int dist[MAX][12];
void Dijkstra(int source){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= d; j++){
            dist[i][j] = INT_MAX;
        }
    }
    pq.push(node(source, 0, 0));
    dist[source][0] = 0;
    
    while(!pq.empty()){
        
        node u = pq.top(); pq.pop();
	    if(u.cost != dist[u.vertex][u.newroad]) continue;
	    for(auto v: g[u.vertex]){
	        
            if(dist[u.vertex][u.newroad] + v.weight < dist[v.vertex][u.newroad + v.type]){
                dist[v.vertex][u.newroad + v.type] = dist[u.vertex][u.newroad] + v.weight;
                pq.push(node(v.vertex, dist[v.vertex][u.newroad + v.type], u.newroad + v.type));
                //parent[v.vertex] = u.vertex;
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++){
        scanf("%d %d %d %d", &n, &m, &k, &d); 
        for(int i = 0; i < n; i++){
            g[i].clear();
        }
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d", &x, &y, &w);
            g[x].pb(edge(y, w, 0));
            //g[y].pb(edge(x, w, 0));
        }
        
        for(int i = 1; i <= k; i++){
            scanf("%d %d %d", &x, &y, &w);
            g[x].pb(edge(y, w, 1));
            //g[y].pb(edge(x, w, 0));
        }
        Dijkstra(0);
        int Min = INT_MAX;
        for(int i = 0; i <= d; i++){
            Min = min(Min, dist[n - 1][i]);
        }
        printf("Case %d: ", cs);
        if(Min == INT_MAX)printf("Impossible\n");
        else printf("%d\n", Min);
    }
}
