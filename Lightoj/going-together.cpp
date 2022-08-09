// Author: Saurov Chandra Biswas
// Institution: University of Barishal
// Problem: Going Together
// Contest: LightOJ
// URL: https://lightoj.com/problem/going-together
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int vis[11][11][11][11][11][11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Tuple {
	int fx, fy, sx, sy, tx, ty, cost;
	Tuple (int a, int b, int c, int d, int e, int f, int g) {
		fx = a; fy = b; sx = c; sy = d; tx = e; ty = f; cost = g;
	}
	Tuple () {}
};

void print(Tuple t) {
	cout << t.fx <<" " << t.fy <<" " << t.sx << " " << t.sy << " " << t.tx <<" " << t.ty << endl;
	cout << t.cost << endl;
	cout << endl;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int cs = 1; cs <= test; ++cs) {
		int n, fx, fy, sx, sy, tx, ty, cost, ans = -1;
		printf("Case %d: ", cs);
		scanf("%d", &n);
		char matrix[n + 1][n + 1]; 
		vector<pair<int, int>> dests, sources;
		for (int i = 0; i < n; ++i) {
			char s[12]; scanf("%s", s);
			for (int  j = 0; j < n; ++j) {
				matrix[i][j] = s[j];
				if (matrix[i][j] == 'A' or matrix[i][j] == 'B' or matrix[i][j] == 'C') sources.push_back({i, j});
				if (matrix[i][j] == 'X') dests.push_back({i, j});
			}
		}
		sort(dests.begin(), dests.end());
		memset(vis, 0, sizeof vis);
		fx = sources[0].first; fy = sources[0].second;
		sx = sources[1].first; sy = sources[1].second; 
		tx = sources[2].first; ty = sources[2].second;
		
		Tuple tuple; tuple.cost = 0; 
		tuple.fx = fx; tuple.fy = fy;
		tuple.sx = sx; tuple.sy = sy;
		tuple.tx = tx; tuple.ty = ty;
		
		queue<Tuple> Q; Q.push(tuple);
		vis[fx][fy][sx][sy][tx][ty] = 1;
		
		while (!Q.empty()) {
			Tuple u = Q.front(); Q.pop();
			//cout <<"u" << endl;
			//print(u);
			vector<pair<int, int>> temp;
			temp.push_back({u.fx, u.fy});
			temp.push_back({u.sx, u.sy});
			temp.push_back({u.tx, u.ty});
			
			sort(temp.begin(), temp.end());
			if(temp == dests) {
				ans = u.cost; break;
			}
			
			for (int i = 0; i < 4; ++i) {
				fx = u.fx + dx[i]; fy = u.fy + dy[i];
				sx = u.sx + dx[i]; sy = u.sy + dy[i];
				tx = u.tx + dx[i]; ty = u.ty + dy[i];
				
				if (matrix[fx][fy] == '#' or fx < 0 or fy < 0 or fx == n or fy == n) fx -= dx[i], fy -= dy[i];
				if (matrix[sx][sy] == '#' or sx < 0 or sy < 0 or sx == n or sy == n) sx -= dx[i], sy -= dy[i];
				if (matrix[tx][ty] == '#' or tx < 0 or ty < 0 or tx == n or ty == n) tx -= dx[i], ty -= dy[i];
				
				if ((u.fx == fx and u.fy == fy) and ((fx == sx and fy == sy) or (fx == tx and fy == ty))) {
					if (fx == sx and fy == sy) sx = u.sx, sy = u.sy;
					if (fx == tx and fy == ty) tx = u.tx, ty = u.ty;
				}
				else if ((u.sx == sx and u.sy == sy) and ((fx == sx and fy == sy) or (sx == tx and sy == ty))) {
					if (fx == sx and fy == sy) fx = u.fx, fy = u.fy;
					if (sx == tx and sy == ty) tx = u.tx, ty = u.ty;
				}
				else if ((u.tx == tx and u.ty == ty) and ((fx == tx and fy == ty) or (sx == tx and sy == ty))){
					if (tx == sx and ty == sy) sx = u.sx, sy = u.sy;
					if (fx == tx and fy == ty) fx = u.fx, fy = u.fy;
				}
				if (vis[fx][fy][sx][sy][tx][ty] == 1) continue;
	
				vis[fx][fy][sx][sy][tx][ty] = 1;
				Tuple t = Tuple(fx, fy, sx, sy, tx, ty, u.cost + 1);
				Q.push(t);
			}
		}
		
		if (ans == -1) printf("trapped\n");
		else printf("%d\n", ans);
	}
	
}