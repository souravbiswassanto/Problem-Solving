    #include <bits/stdc++.h>
    using namespace std ;

    #define  ll   unsigned long long
    #define  pb  push_back
    #define  mp  make_pair
    #define  MAX  600006
    #define  MAX1  10000008
    #define  mem(a,v)   memset(a,v,sizeof(a))

    void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

    ll power[MAX];
    ll hashvalue;
    ll Ans[MAX];
    ll mod=1e9+7;
    ll prime=137;
    vector<ll>V;
    map<ll,ll>M;
    ll Counter;

    void prepowersave(){
        power[0]=1;
        for(int i=1;i<=600006;i++){
            power[i]=((power[i-1])*prime)%mod;
        }
    }

    ll prehash_calc(string s){
        hashvalue=0;
        for(int i=0;i<s.size();i++){
            hashvalue+=(s[i]*power[i]);
        }
        return hashvalue;
    }

    bool checkhash(string s){
        ll Hash=prehash_calc(s);
        for(int i=0;i<s.size();i++){
            ll Newhash=Hash-s[i]*power[i];
            for(char ch='a';ch<='c';ch++){
                if(ch==s[i])continue;
                ll newhash=Newhash+ch*power[i];
                if(binary_search(V.begin(),V.end(),newhash))return true;
            }
        }
        return false;
    }

    int main ()
    {
        fastIO();
        ll a,b,c,n,m,k,p,q,r;
        ll cnt=0,cntr=0,sum=0,ans=0,check=0;
        float x,y,z;
        ll Max= 0,Max1=-1e18+1;
        ll Min = 1e18;

        prepowersave();

        cin>>n>>m;
        string s,query,s3,s4;

        for(int i=0;i<n;i++){
            cin>>s;
            V.pb(prehash_calc(s));
        }
        sort(V.begin(),V.end());
        for(int i=0;i<m;i++){
            cin>>query;
            if(checkhash(query))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


        return 0;
    }
