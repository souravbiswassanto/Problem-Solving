// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int , int>> g[n];
        int mod = 1e9 + 7;
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        long long dist[n];
        map<pair<int, ll>, ll> M;
        function <void(int, int)> dijkstra = [&] (int source, int idx){
            for(int i = 0; i < n; i++)dist[i] = INT_MAX;
            priority_queue<pair<int, ll>,vector<pair<int, ll>>, greater<pair<int, ll>> >pq;
            pq.push({source, 0}); M[{source, 0}] = 1;
            dist[source] = 0;
            while(!pq.empty()){
                auto u = pq.top();
                pq.pop();
                if(u.second != dist[u.first])continue;
                for(auto v: g[u.first]){
                    if(dist[u.first] + v.second < dist[v.first]){
                        dist[v.first] = dist[u.first] + v.second;
                        pq.push({v.first, dist[v.first]});
                        cout << u.first<<" "<<v.first<<" "<<M[{u.first, u.second}] << endl;
                        M[{v.first, dist[v.first]}] += M[{u.first, u.second}];
                    }
                    else if(dist[u.first] + v.second == dist[v.first]){
                        M[{v.first ,dist[v.first]}] += M[{u.first, u.second}];
                    }
                    
                }
            }
        };
        
        dijkstra(0, 0);
        for(auto it: M){
            //cout << it.first.first <<" " << it.first.second <<" " << it.second<< endl;
        }
        
        //for(int i = 0; i < n; i++)cout << dist[i][0] <<" "<< dist[i][1] << endl;
        int totcost = dist[n - 1];
        return M[{n - 1, totcost}];
        
        
    }
};