
// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round #20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
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
    int vertex, cost;
    node(int a, int b){
        vertex = a;
        cost = b;
    }
    bool operator<(node other)const{
        return cost > other.cost;
    }
};

int n, m, x, y, w;
vector<edge> g[MAX];
priority_queue<node> pq;
ll dist[200005], parent[200005];
void Dijkstra(int source){
    
    for(int i = 1; i <= n; i++) dist[i] = 1e16;
    pq.push(node(source, 0));
    dist[source] = 0;
    
    while(!pq.empty()){
        
        node u = pq.top(); pq.pop();
	    if(u.cost != dist[u.vertex]) continue; //multiple edge thakle eitar karone wrong ans aste pare.
	    for(auto v: g[u.vertex]){
	        
            if(dist[u.vertex] + v.weight < dist[v.vertex]){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(node(v.vertex, dist[v.vertex]));
                parent[v.vertex] = u.vertex;
            }
        }
    }
}
void print(int source, int dest){
    if(source == dest){
        cout<< source <<" "; return;
    }
    print(parent[source], dest);
    cout<< source <<" ";
}
int main()
{
    
    cin>> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> w;
        if(x == y)continue;
        g[x].pb(edge(y, w));
        g[y].pb(edge(x, w));
    }
    Dijkstra(1);
    if(dist[n] == 1e16)cout << -1 << endl;
    else print(n, 1);
    //print(3, 1);
}
