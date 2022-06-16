
// Problem: Word Collection
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/COLWORD
// Memory Limit: 256 MB
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
bool endpoint[MAX];
int autom[200005][27];
char t[1000006], p[1000006];

void kmp(string text,string pattern){
       
     for(int i=0;i<26;i++)
        autom[0][i] = 0;
     for(int i=0;i<pattern.size();i++) {
        int nx = autom[i][pattern[i]-'a'];
        autom[i][pattern[i]-'a'] = i+1;
        for(int j=0;j<26;j++) {
          autom[i+1][j] = autom[nx][j];
        }
      }
    int i=0,j=0,Counter=0;

    while(i<text.size()){
        endpoint[i] = false;
        j = autom[j][text[i] - 'a'];
        if(j==pattern.size()){
            j = autom[j - 1][text[i]-'a'];
            Counter++;   
            endpoint[i] = true;
        }
        i++;
    }
    
}

int main(){
    int test;
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        
        scanf("%s %s", t, p);
         int n;
         n = strlen(t);
         int m;
         m = strlen(p);
         ll dp[n + 4];
         mem(dp, 0);
         kmp(t, p);
         ll ans = 0;
         ll mod = 1e9 + 7;
         
         for(int i = 1; i <= n; i++){
             if(endpoint[i - 1]){
                 dp[i] = (dp[i - 1] + dp[i - m] + 1) % mod;
             }
             else dp[i] = dp [i -1];
             //cout << dp[i] << endl;
         }   
         printf("%d\n", dp[n]);
        //printf("Case %d: ",cs);
        
    }
    return 0;
}