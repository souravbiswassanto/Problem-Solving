
// Problem: B. Jumping Gollum
// Contest: CodeMarshal - DUET IUPC 2019
// URL: https://algo.codemarshal.org/contests/duet-iupc-19/problems/B
// Memory Limit: 1500 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<62
#define   ll     long long
#define   ull    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl


vector<ll>prime;
//bool mark[MAX1];
ll N =1e6 + 5;
ll spf[2000004];
void seive ()
{
    for(int i = 2; i <= N; i++)spf[i] = i;
    int limit = sqrt(N*1.0)+2; spf[1] = 1; spf[2] = 2;
    for (int i=4; i<=N; i += 2)spf[i]=2;
    prime.push_back(2);
    //i*i <=N kora jave
    for (int i=3; i<=N; i+=2)
    {
        if(spf[i]==i)
        {
            prime.push_back(i);
            if(i<=limit)
            {
                for (int j=i*i; j<=N; j+=i*2){
                    if(spf[j]==j)spf[j] = i;
                }
            }
        }
    }
}


int main ()
{
    seive();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        int n, k;
        scanf("%d %d", &n, &k);
        int A[n + 5];
        int dp[n + 5];
        mem(dp, -1);
        vector<int> V[n + 3];
        for(int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
        }
        for(int i = 1; i <= n; i++){
            int m = A[i];
            while(m != 1){
                
                V[i].pb(spf[m]);
                m /= spf[m];
            }
        }
        for(int i = 1; i <= n; i++){
            sort(V[i].begin(), V[i].end());
            V[i].resize(unique(V[i].begin(), V[i].end())- V[i].begin());
        }
        //for()
        dp [0] = -1;
        //cout << 1 << endl;
        vector<deque< pair<int, int>>> dq(1000);
        unordered_map<int, deque< pair<int, int>> > D;
        for(int i = 1; i <= n; i++){
            int Min = INT_MAX - 2;
            //cout << i << " i " << endl;
            for(auto j: V[i]){
                if(j > 1000){
                    int res = INT_MAX - 12;
                    while (!D[j].empty() and D[j].back().second < (i - k )){
                        D[j].pop_back();
                    }
                    //D.push_front(make_pair(A[i],i));
                    if(!D[j].empty()){
                        res = D[j].back().first;
                    }
                    res = min(res + 1, dp[i - 1] + 1);
                    Min = min(Min, res);
                }
                else {
                    int res = INT_MAX - 12;
                    
                    while (!dq[j].empty() and dq[j].back().second < (i - k)){
                        //cout << dq[j].back().second <<" de"<< endl;
                        dq[j].pop_back();
                    }
                    //D.push_front(make_pair(A[i],i));
                    if(!dq[j].empty()){
                        res = dq[j].back().first;
                        //cout << res << "idx " <<dq[j].back().second << endl;
                    }
                    res = min(res + 1, dp[i - 1] + 1);
                    

                    Min = min(Min, res);
                    //cout <<i <<" "<<j<<" "<< res <<" "<< Min <<"\n";
                }
                
            }
            for(auto j: V[i]){
                if(j > 1000){
                    while (!D[j].empty() and D[j].front().first >= Min){
                        D[j].pop_front();
                    }
                    D[j].push_front({Min, i});
                }
                else {
                    while (!dq[j].empty() and dq[j].front().first >= Min){
                        dq[j].pop_front();
                    }
                    dq[j].push_front({Min, i});
                }
            }
            //cout << endl;
            dp[i] = min(dp[i - 1] + 1, Min);
            //cout <<dp[i] <<"\n";
        }
        //cout << endl;
        printf("Case %d: %d\n", cs, dp[n]);
    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return 0;
}
