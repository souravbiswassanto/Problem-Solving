#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
using namespace std;
#define pb push_back
#define ll long long

struct DSU{
    //path compression
    int n, comp;
    vector<int> parent, Size;
    vector<pair<int, int>> res;
    DSU(int _n){
        n = _n;
        parent.resize(n + 1, 0);
        Size.resize(n + 1, 0);
        comp = _n;
        for(int i = 1; i <= n; i++)make_set(i);
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    // Size compression
    void make_set(int v) {
        parent[v] = v;
        Size[v] = 1;
    }
    
    void union_set(int a, int b) {
        int x = find_set(a);
        int y = find_set(b);
        if (x != y) {
            parent[y] = x;
            comp--;
        }
        else {
            res.pb({a, b});
            //cout << a <<" " << b << endl;
        }
    }
    void solve(){
        vector<int> leaders;
        for (int i = 1; i <= n; i++){
            if(parent[i] == i){
                leaders.pb(i);
            }
        }
        for(int i = 0; i < leaders.size() - 1; i++){
            cout <<res[i].first<<" " << res[i].second;
            cout<<" " <<leaders[i]<<" " << leaders[i + 1]<< endl;
        }
    }
};

int main ()
{
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    string s,s1,s3,s4;

    //cin>>n;
    t = 1;

    while(t--){
        cin>>n;
        DSU dsu(n);
        for (int i = 1; i < n; i++){
            cin >> a >> b;
            dsu.union_set(a, b);
        }
        cout << dsu.comp - 1 << endl;
        dsu.solve();
    }

    return 0;
}
