
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)


template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

int main()
{
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul Haque/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    oset< int> s;

    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(4);
    s.insert(5);
    s.insert(7);

    ll ans=0;
    for(auto it:s){
        cout<<it<<endl;
    }
//    for(int i=2;i<=n;i++){
//        x=1-(a[i]-b[i]);
//        r=s.order_of_key();
//        //cout<<i<<" "<<x<<" "<<r<<" "<<i-r-1<<endl;
//        ans+=(i-r-1);
//        s.insert({a[i]-b[i],i});
//    }

    cout<<ans<<endl;

    return 0;
}
/*

// Problem: C. Journey
// Contest: Codeforces - Codeforces Round #428 (Div. 2)
// URL: https://codeforces.com/problemset/problem/839/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

using namespace __gnu_pbds;


template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<63
#define   ll     long long
#define   ull    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}


int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
     oset<pair<int,int> > S;
     S.insert(mp(4,1));
     S.insert(mp(4,2));
     S.insert(mp(4,3));S.insert(mp(1,1));S.insert(mp(2,5));S.insert(mp(8,1));
     for(auto it:S)cout<<it.first<<" "<<it.second<<endl;
    cout<<S.order_of_key({3,0})<<endl;
    cout<<S.order_of_key({8,1})<<endl;;    

    return 0;
}
*/