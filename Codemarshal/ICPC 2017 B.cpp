
// Problem: B. Bracket Sequence
// Contest: CodeMarshal - ACM ICPC 2017 Dhaka Regional Contest
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-17/problems/B
// Memory Limit: 1500 MB
// Time Limit: 1000 ms
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
        printf("Case %d:\n",cs);
        char s[100006];
        scanf("%s", s);
        int n = strlen(s);
        stack <int> S;
        map<char,char>M;
        M[')'] = '(';
        M['>'] = '<';
        M[']'] = '[';
        M['}'] = '{';
        int L[n + 10], R[n + 10], ans[n + 10];
        for(int  i = 0; i <= n + 2; i++){
            L[i] = i;
            R[i] = 0;
            ans[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(s[i] =='<' or s[i] =='(' or s[i] =='[' or s[i] == '{'){
                S.push(i);
            }
            else {
                if(S.empty())continue;
                int pos = S.top();
                if(s[pos] == M[s[i]]){
                    R[pos] = i;
                    S.pop();
                }
                else S.push(i);
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(R[i] <= L[i])continue;
            ans[i] = R[i] - L[i] + 1 + ans[R[i] + 1];
        }
        for(int i = 0; i < n; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}