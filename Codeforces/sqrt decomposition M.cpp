
// Problem: M. Similar Sets
// Contest: Codeforces - 2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)
// URL: https://codeforces.com/contest/1468/problem/M
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main(){
    
    int t;
    scanf("%d", &t);
    loop:
    while(t--){
        int n;
        scanf("%d", &n);
        vector<int> Set[n], values;
        for (int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
            for (int j = 0; j < a; j ++){
                int b;
                scanf("%d", &b);
                Set[i].pb(b);
                values.pb(b);
            }
        }
        sort(values.begin(), values.end());
        values.resize(unique(values.begin(), values.end())- values.begin());
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < Set[i].size(); j ++){
                Set[i][j] = lower_bound(values.begin(),values.end(), Set[i][j]) - values.begin();
            }
        }
        int sz = 316;
        bool found [values.size()];
        for (int i = 0; i < values.size(); i ++){
            found[i] = false;
        }
        for (int i = 0; i < n; i++){
            if (Set[i].size() < sz)continue;
            for (auto b: Set[i])found[b] = true;
            for (int j = 0; j < n; j++){
                if (i == j)continue;
                int cnt = 0;
                for (auto a: Set[j]){
                    if(found[a])cnt++;
                    if(cnt >= 2){
                        printf("%d %d\n", i + 1, j + 1);goto loop;
                    }
                }
            }
            for (auto b: Set[i])found[b] = false;
        }
        vector<int> inv[values.size()]; 
        for (int i = 0; i < n; i++){
            if(Set[i].size() > sz)continue;
            for(auto a: Set[i]){
                inv[a].pb(i);
            }
        } 
        int pos[values.size()];
        for (int i = 0; i < values.size(); i++){
            pos[i] = -1;
        }
        for (int i = 0; i < values.size(); i++){
            for (auto v: inv[i]){
                for (auto j: Set[v]){
                    if (j == i)continue;
                    if(pos[j] == -1){
                        pos[j] = v;
                    }
                    else {
                        printf("%d %d\n", pos[j] + 1, v + 1); goto loop;
                    }
                }
            }
            for (auto v:inv[i]){
                for (auto j: Set[v])pos[j] = -1;
            }
        }
        printf("-1\n");
    }
}