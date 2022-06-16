
// Problem: Moons and Umbrellas
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
using namespace std;
using namespace __gnu_pbds;

#define   ll long long
#define   MAX 500006
#define   pb     push_back
#define   mp     make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))

vector<ll>prime;
bool mark[10000007];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/
string s;
int x, y, sum;
int dp[2000][4], A[2000];
int maxx = 3e6;

int solve(int a, int b, int id){
    if(a == b)return 0;
    int &ret = dp[a][id];
    if(ret != -1)return ret;
    int res = maxx, ress = maxx;
    if(id == 1){
        if(A[a + 1] == 0 or A[a + 1] == 2){
            res = solve(a + 1, b, 2) + x;
        }
        if(A[a + 1] == 0 or A[a + 1] == 1){
            ress = solve(a + 1, b, 1);
        }
    }
    else {
        if(A[a + 1] == 0 or A[a + 1] == 1){
            res = solve(a + 1, b, 1) + y;
        }
        if(A[a + 1] == 0 or A[a + 1] == 2){
            ress = solve(a + 1, b, 2);
        }
    }
    ret = min(ress, res);
    return ret;
}

int main(){
    int test;
    cin >> test;
    for(int cs = 1; cs <= test; cs++){
        printf("Case #%d: ",cs);
        cin >> x >> y >> s;
        int n = s.size();
        sum = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == 'J')A[i] = 2;
            else if(s[i] =='C')A[i] = 1;
            else A[i] = 0;
            }
        mem(dp, -1);
        
        sum = 0;
        
        //cout << solve(0, n -1, 1) <<" uu "<< solve(0, n - 1, 2)<< endl;
        //sum = min(solve(0, n - 1, 1, 1), solve(0, n - 1, 2, 2));
        if(s[0] == '?'){
            sum = min(solve(0, n - 1, 1), solve(0, n - 1, 2));
        }
        else {
            sum = solve(0, n- 1, s[0] == 'J'? 2: 1);
        }
        printf("%d\n", sum);
        
    }
    return 0;
}