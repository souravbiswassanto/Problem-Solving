
// Problem: Reversort Engineering
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
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

int main(){
    int test;
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        printf("Case #%d: ",cs);
        int n, c;
        scanf("%d %d", &n, &c);
        int sum = 0, maxx = 0, minn = n - 1;
        for(int i = n ; i >= 2; i--)maxx += i;
        sum = maxx;
        if(c < minn or c > maxx){
            printf("IMPOSSIBLE\n");continue;
        }
        int A[ n + 3];
        vector<int> V;
        for(int i = n; i >= 2; i--){
            //cout << c <<" "<< i << endl;
            if((i + i - 2) <= c){
                c -= i;
                A[i] = i;
                V.pb(i);
            }
            else {
                c--;
                V.pb(1);
                A[i] = 1;
            }
        }
        //for(auto v: V)cout <<v  <<" "; cout << endl;
        int ptr1= 1, ptr2 = n, tuple = 0, B[n +5];
        for(int i = 0; i < V.size(); i++){
            if(V[i] > 1) tuple ^= 1;
            if(tuple){
                B[ptr2] = i + 1;
                ptr2--;
            }
            else {
                B[ptr1] = i + 1;
                ptr1++;
            }
        }
        B[ptr1] = n;
        for(int i = 1; i <= n; i++){
            printf("%d ", B[i]);
        }
        printf("\n");
        
    }
    return 0;
}