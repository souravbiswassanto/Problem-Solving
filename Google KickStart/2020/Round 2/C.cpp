
// Problem: Robot Path Decoding
// Contest: Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
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
ll mod = 1000000000;

int main(){
    int test;
    ll LL_MAX = 1e18;
    cin >> test;
    for(int cs = 1; cs <= test; cs++){
        printf("Case #%d: ",cs);
        string s;
        cin >> s;ll sum = 0;
        int n =  s.size();
        ll x = 0, y = 0;
        stack<ll> S;
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                sum = 0;
                while(S.top() != LL_MAX){
                    ll a = S.top(); S.pop();
                    sum += a; sum %= mod;
                    //cout << a <<" "<<sum<<endl;
                }
                S.pop();
                ll a = S.top();
                S.pop();
                S.push((1LL * sum * a)%mod);
                //cout << a<<" last "<<sum<<endl;
            }
            else{
                if(s[i] == '(')S.push(LL_MAX);
                else{
                    ll a;
                    if(s[i] == 'S')a = 1;
                    else if(s[i] =='N')a = -1;
                    else if(s[i] >= 48 and s[i] <= 57){
                        a = s[i] - '0';
                    }
                    else a = 0;
                    S.push(a);
                }
            }
        }
        while(!S.empty()){
            //cout << S.top()<<endl;
            y += (S.top()); S.pop(); y %= mod;
        }
        
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                sum = 0;
                while(S.top() != LL_MAX){
                    ll a = S.top(); S.pop();
                    sum += a; sum %= mod;
                }
                S.pop();
                ll a = S.top();
                S.pop();
                S.push((1LL * sum * a) % mod);
            }
            else{
                if(s[i] == '(')S.push(LL_MAX);
                else{
                    int a;
                    if(s[i] == 'E')a = 1;
                    else if(s[i] =='W')a = -1;
                    else if(s[i] >= 48 and s[i] <= 57){
                        a = s[i] - '0';
                    }
                    else a = 0;
                    S.push(a);
                }
            }
        }
        while(!S.empty()){
            //cout << S.top()<<endl;
            x += (S.top())
            ; S.pop(); x %= mod;
        }
        x += 1; y += 1;
        x = ( x + mod) % mod;
        y = ( y + mod) % mod;
        if(x == 0)x = mod;
        if(y == 0)y = mod;
        cout << x <<" "<<y<<endl;
        
    }
    return 0;
}