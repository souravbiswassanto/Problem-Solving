#include<bits/stdc++.h>
using namespace std;
#define MAX 300006
typedef long long ll;
int A[MAX];
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}
int check = 0;
int idxx = 0;

struct SegmentTree{
	vector<ll> tree;
	int n;
	SegmentTree(int _n){
	    n = _n;
	    tree.clear();
	    tree.resize(n * 4);
	}
	void build(int node, int tb, int te){
	    if(tb > te) return;
		if(tb == te){
			tree[node]  = A[tb];//value goes here
			return;
		}
		int mid=(tb + te) >> 1; 
		int left = (node * 2);
		int right = node * 2 + 1;
		build(left, tb, mid);
		build(right, mid + 1, te);
		tree[node] = max(tree[left], tree[right]);
	}
	// point update
	void update(int node, int tb, int te,int idx, int newval){
        if(te < idx || idx < tb)return; 
        if(tb == te){
            tree[node] -= newval;
            //cout << tree[node] << endl;
            return;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        update(left, tb, mid, idx, newval);
        update(right, mid + 1, te, idx, newval);
        tree[node] = max(tree[left],tree[right]);
    }
    // range update
	// Range query
	int query(int node, int tb, int te,int val){
	    if(check)return 0;
        if(tb > te) return 0;
        if(tree[node] < val)return 0;
        if(tb == te){
            check = 1;
            idxx = tb;
            return tb;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        int L = query(left, tb, mid, val);
        int R = query(right, mid + 1, te, val);
        return max(L,R);
    }

}; 
int main(){
    fastIO();
    int n; int q;
    cin>> n;cin >> q;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }
    
    SegmentTree st(n);
    st.build(1, 1, n);
    
    for (int i = 1; i <= q ; i++){
        int a;
        cin >> a;
        check = 0;
        idxx = 0;
        int ans = st.query(1, 1, n, a); 
        cout << ans << " ";
        if(idxx)st.update(1,1,n, idxx, a);
    }
    //for (auto it: st.tree) cout << it << endl;
}