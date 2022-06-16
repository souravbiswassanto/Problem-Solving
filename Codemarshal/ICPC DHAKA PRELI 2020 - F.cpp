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
#define   MAX1 5000006
#define   pb     push_back
#define   mp     make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))

vector<ll>prime;
bool mark[MAX1];
ll N = 2e6 + 100;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


ll  a, b, m;
vector<ll> getpfs(ll n){
    vector<ll> pf;
    for(int i = 0; prime[i] * 1LL * prime[i] <= n; i++){
        if(n % prime[i])continue;
        pf.pb(prime[i]);
        while(n % prime[i] == 0)n /= prime[i];
    }
    if(n != 1LL)pf.pb(n);
    return pf;
}

ll getAns(vector<ll> pf, ll n){
    
    int m = pf.size(); ll sum, ans = 0;
    for(int i = 1; i < (1 << m); i++){
        int cntr = 0; sum = 0; ll mult = 1LL;
        for(int j = 0; j < m; j++){
            if(i & (1 << j))cntr++;
            if(i & (1 << j)){
                mult *= pf[j];
            }
        }
        sum = n / mult;
        if(cntr % 2)ans += sum;
        else ans -= sum;
    }
    return n - ans;
}

int main(){
    int test; seive();
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        printf("Case %d: ",cs);
        scanf("%lld %lld %lld", &a, &b, &m);
        if(a == b){
            if(a != 1)printf("0\n");
            else printf("1\n");
            continue;
        }
        if(a > b)swap(a, b); 
        if(a == b - 1){
            printf("%lld\n", m + 1); continue;
        }
        ll gap = b - a;
        vector<ll> pf = getpfs(b - a);
        ll ans = getAns(pf, a + m) - getAns(pf, a - 1);
        printf("%lld\n", ans);
    }
    return 0;
}