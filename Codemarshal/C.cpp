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

template<class T>
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}
const int MOD = 1e9 + 7;
const int mod = 1e9 + 7;

ll A[MAX];
ll B[MAX];
ll C[MAX];
int n;
int BIT[32][100006];
struct FT{
    void update(int x, int delta, int i){
          //cout << i << " "<<x << endl;
          for(; x <= n; x += x&-x) BIT[i][x] += delta;
    }
    int query(int x,  int i){
        int sum = 0;
         for(; x > 0; x -= x&-x) sum += BIT[i][x];
         return sum;
    }
}Bit;

int main ()
{
    ll a,b,c,d,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;
    
    n = in<int>(); q = in<int> ();
    for(int i = 1; i <= n; i++){
        A[i] = in<int>();
    }
    
    for(int i = 0; i <= 30; i++){
        for(int j = 1; j <= n; j++){
            if((1 << i) & (A[j])){
                Bit.update(j, 1, i);
            }
        }
    }
    
    ll re = 1;
    for(int i = 0; i <= 200006; i++){
        B[i] = re;
        re = (re * 2LL) % mod;
    }
    while(q--){
        a = in<int> ();
        b = in<int> ();
        ll res = 0;
        for(int i = 0; i <= 30; i++){
            l = 0; r = 0;
            if(a != 1) l = Bit.query(a - 1, i); 
            if(b == 1) r = (A[1] &(1 << i));
            else  r = Bit.query(b, i);
            sum = r - l;
            if(sum <= 0)continue;
            
            res = (res + ((B[sum - 1 + i]) * (B[(b-a + 1) - sum])) % mod)% mod;
         }
         printf("%lld\n", res);
    }

  
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return 0;
}
