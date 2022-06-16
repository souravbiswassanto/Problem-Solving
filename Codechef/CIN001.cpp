
// Problem: RACHIT AND NIGHT TUITION
// Contest: CodeChef - Code IT NITJ
// URL: https://www.codechef.com/NITJ2021/problems/CIN001
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 

using namespace std;
using Lint = long long;
using Frac = double;
const int MAX_N = 500006;

#define   pb          push_back
#define   mp          make_pair
#define   mem(a, v)   memset(a, v, sizeof(a))

vector <Lint> prime;
bool mark[10000008];

void seive (){ Lint N = 1e7; int limit = sqrt(N*1.0)+2;mark[1] = 1;for(int i = 4;i <= N; i += 2)mark[i] = 1; prime.push_back(2); for(int i = 3; i <= N; i += 2){if(!mark[i]){prime.push_back(i); if(i <= limit){for(int j = i * i; j <= N; j += i * 2)mark[j] = 1;}}}}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase;
    cin >> testCase;
    Lint a, b, c, d, k, l, m, n, p, q, r, x, y;
    Frac X, Y, P, Q, R, Pi, G,theta,  val, avg;
    
    while (testCase--){
        cin >> a >> b>> c >> r;
        
        Lint sum = 0, ans = 0, cntr = 0, cnt = 0;
        p = min(a,b);
        q = max(a,b);
        x = c - r;
        y = c + r;
        if(r == 0 || y < p || x > q){
            cout << abs(a -b) << " "; continue;
        }
        //cout << x << endl;
        sum = (max(0LL, x - p) + max(0LL, q - y));
        cout << sum << " ";
        
    }

    return 0;
}
