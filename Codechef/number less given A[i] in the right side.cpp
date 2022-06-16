#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"
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

/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/
struct sourav{
    int val, pos;
    sourav(int a, int b){
        val = a;
        pos = b;
    }
    bool operator <(sourav other) const{
        if(val == other.val) return val < other.val;
        return other.val < val;
    }
};
int B[100];
vector <sourav> V;
int main()
{
    int t,a,n,m,x,y,w,k,q,r,p,cs;

    oset<int> S;
    cin >> n;
    
    for (int i = 0; i < n;i++){
        cin >> a;
        V.pb(sourav(a,i));
    }
    sort(V.begin(), V.end());
    for (auto i: V)cout <<i.val <<" " << i.pos<< endl;
    
    for (int i = 0; i < V.size(); i++){
        S.insert(V[i].pos);
        auto it = S.order_of_key(V[i].pos) ;
        B[V[i].pos] = V[i].pos - it;
    }
    for (int i = 0; i < n; i++)cout << B[i] <<" ";
    cout << endl;

    return 0;
}
