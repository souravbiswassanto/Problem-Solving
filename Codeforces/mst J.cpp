#include<bits/stdc++.h>
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
using namespace std;
#define MAX 200006
#define ll long long

struct edge {

    int vertex1;
    int vertex2;
    int weight;
    edge(int a,int b,int c){
        vertex1=a;
        vertex2=b;
        weight=c;
    }
};

bool sourav(edge A,edge B){
    return A.weight<B.weight;
}


vector<edge>graph, g;
int parent[200006],A[MAX], B[MAX], C[MAX];
ll sum, k;

void makeparent(int n){
    parent[n]=n;
}

int fr(int n){

    if(parent[n]==n)return n;
    else return parent[n]=fr(parent[n]);
}

void kruskalmst(int n,struct edge ab){
    sort(graph.begin(),graph.end(),sourav);
     //g.push_back(ab);
    for (int i = 0; i < graph.size(); i++) g.push_back(graph[i]);
    for(int i=1;i<=n;i++)makeparent(i);

    for(int i=0;i<g.size();i++){
        int u=fr(g[i].vertex1);
        int v=fr(g[i].vertex2);
        //cout << g[i].vertex1 << " " << g[i].vertex2 << endl;
        if(u!=v){
            parent[v]=u;
            sum += (ll)max(0LL, g[i].weight - k);
            //cout << sum << endl;
        }
    }

}

int main (){
    
    int t;
    cin >> t;
    while(t--){
        int n,m,a,b,w;
    
        cin>>n>>m >> k;
        struct edge ab(0,0,0);
        int idx = -1, val, Min = INT_MAX;
        for(int i=1; i<=m; i++){
            cin >> A[i] >> B[i] >> C[i];
            val = abs(C[i] - k);
            if (val < Min){
                idx = i;
                Min = val;
                ab.vertex1 = A[i];
                ab.vertex2 = B[i];
                ab.weight = C[i];
            }
        }
        for (int i = 1; i <= m; i++){
            //if(i == idx)continue;
            graph.push_back(edge(A[i], B[i], C[i]));
        }
        kruskalmst(n, ab);
        if(sum == 0){
            ll Min = INT_MAX;
            for (int i = 0; i < g.size(); i++){
                Min = min(abs(k -g[i].weight), Min);
            }
            sum += Min;
        }
        cout << sum << endl; sum = 0;
        graph.clear(); g.clear();
    }
    return 0;
}
