#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  100006
#define  Max(a,b,c) max(a,max(b,c))
#define  Min(a,b,c) min(a,min(b,c))
#define  mem(a,v)   memset(a,v,sizeof(a))
#define  rep        for (int i=0;i<n;i++)
#define  Rep        for (int i=0;i<m;i++)

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];

ll rev (ll a,ll b){

    return a>b;
}

int main ()
{

    fastIO();
    vector<ll> V;
    set<ll>S;
    set<ll>::iterator it;
    map<string,ll> M;
    map<string,ll>::iterator it1;

    ll a,b,c;
    ll n,m;
    ll cnt=0,cntr=0,sum=0,ans=1;
    ll p,q,r;
    ll v=1;
    ll check=0;
    ll x,y,z;
    ll Max=0,Min=INT_MAX;
    string s,s1[MAX],s2[MAX],s3,s4;

    cin>>n>>a>>b;

    cin>>s;
    ll i=0;

    while (a>0||b>0){

        if (s[i]!='.'&&s[i]!='*')break;

        if (s[i]=='*'){
            i++;
            continue;
        }
        if (s[i]=='.'&&check==0)cnt++,a--,check=1,s3+='A';
        else if (s[i]=='.'&&check==1)cnt++,b--,check=0,s3+='B';

        if (a==0)check=2;
        if (b==0)check=3;

        if (check==2){
            if (s[i+1]=='*')cnt++,b--,s3+='d';
            else if (s[i+2]=='.')cnt++,b--,i++,s3+='d1';
        }
        else if (check==3){
            if (s[i+1]=='*')cnt++,a--,s3+='c';
            else if (s[i+2]=='.')cnt++,a--,i++,s3+='c1';
        }
        i++;
    }
    cout<<s3<<endl;
    cout<<cnt<<endl;

    return 0;
}
