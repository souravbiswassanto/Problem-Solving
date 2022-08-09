
// Problem: Toll Management
// Contest: LightOJ
// URL: https://lightoj.com/problem/toll-management
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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
    int vertex, weight;
    edge(int a, int b){
        vertex = a; weight = b;
    }
};
struct node{
    int vertex, cost;
    node(int a, int b){
        vertex = a;
        cost = b;
    }
    bool operator<(node other)const{
        return cost > other.cost;
    }
};

int n, m, x, y, w, s, t , p;
vector<edge> g[MAX], rev[MAX];
ll dist[MAX], tmp[MAX];
void Dijkstra(int source){
    priority_queue<node> pq;
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    pq.push(node(source, 0));
    dist[source] = 0;
    
    while(!pq.empty()){
        
        node u = pq.top(); pq.pop();
	    //if(u.cost != dist[u.vertex]) continue;
	    for(auto v: g[u.vertex]){
	        
            if(dist[u.vertex] + v.weight < dist[v.vertex]){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(node(v.vertex, dist[v.vertex]));
            }
        }
    }
}

void Dijkstra1(int source){
    priority_queue<node> pq;
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    pq.push(node(source, 0));
    dist[source] = 0;
    
    while(!pq.empty()){
        
        node u = pq.top(); pq.pop();
	    //if(u.cost != dist[u.vertex]) continue;
	    for(auto v: rev[u.vertex]){
	        
            if(dist[u.vertex] + v.weight < dist[v.vertex]){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(node(v.vertex, dist[v.vertex]));
            }
        }
    }
}

int main()
{
    int cs, test;
    scanf("%d", &test);
    for(cs = 1; cs <= test; cs++){
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
        vector<pair<int, pair<int, int>>> v;
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d", &x, &y, &w);
            g[x].pb(edge(y, w));
            rev[y].pb(edge(x, w));
            v.push_back({w, {x, y}});
        }
        sort(v.rbegin(), v.rend());
        Dijkstra(s);
        for(int i = 1; i <= n; i++){
            tmp[i] = dist[i];
        }
        int res = -1;
        Dijkstra1(t);
        
        for(int i = 0; i < m; i++){
            x = v[i].first; y = v[i].second.first; w = v[i].second.second;
            ll a =  tmp[y] + dist[w];
            if(a + x <= p){
                res = x; break;
            }
        }
        //cout << ans << endl;
        printf("Case %d: %d\n", cs, res);
        for(int i = 1; i <= n; i++){
            g[i].clear();
            rev[i].clear();
        }
    }
}
