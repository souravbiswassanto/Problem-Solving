
// Problem: D. Jzzhu and Cities
// Contest: Codeforces - Codeforces Round #257 (Div. 2)
// URL: https://codeforces.com/contest/450/problem/D
// Memory Limit: 256 MB
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

ll A[MAX], B[MAX], C[MAX];

struct edge{
    int vertex, weight, type;
    edge(int a, int b, int c){
        vertex = a; weight = b; type = c;
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
        if(u.cost > dist[u.vertex]) continue;
	    if(u.cost != dist[u.vertex]) continue; //multiple edge thakle eitar karone wrong ans aste pare.
	    for(auto v: g[u.vertex]){
	        if(dist[u.vertex] + v.weight == dist[v.vertex]){
	            if(B[v.vertex] == 2){
	                B[v.vertex] = v.type;
	                parent[v.vertex] = u.vertex;
	            }
	        }
            if(dist[u.vertex] + v.weight < dist[v.vertex]){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(node(v.vertex, dist[v.vertex]));
                parent[v.vertex] = u.vertex;
                B[v.vertex] = v.type;
            }
        }
    }
}

int main()
{
    int k;
    cin>> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> w;
        if(x == y)continue;
        g[x].pb(edge(y, w, 1));
        g[y].pb(edge(x, w, y));
    }
    for(int i = 1; i <= k ; i++){
        cin >> x >> w;
        A[x]++;
        g[1].pb(edge(x, w, 2));
        g[x].pb(edge(1, w, 2));
    }
    Dijkstra(1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(A[i]){
            if(B[i] == 2)sum += A[i] - 1;
            else sum += A[i];
        }
        
    }
    cout << sum << endl;
}
