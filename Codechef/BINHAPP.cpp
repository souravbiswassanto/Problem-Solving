
// Problem: Binary String Happiness
// Contest: CodeChef - July Lunchtime 2022 Division 1 (Rated)
// URL: https://www.codechef.com/LTIME110A/problems/BINHAPP
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    1000006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll tot[MAX], Left[MAX], Right[MAX], len[MAX], md[MAX], presum[MAX];
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
ll Max = 0, Min = 2e18;
string s[MAX], s1, s2;

const int N = 1000006;

struct Tuple{
	int  Lmax, Lsmax, Rmax, Rsmax, Midmax, maxidL, maxidR;
	int maxsidL, maxsidR;
	Tuple(){}
	Tuple(int a, int g, int h, int i, int b, int c, int d, int e, int f){
		maxidL = a;
		maxidR = g;
		Lmax = b;
		Lsmax = c;
		Rmax = d;
		Rsmax = e;
		Midmax = f;
		maxsidL = h;
		maxsidR = i;
	}
}st[N][21 + 1];

int Log[N+1];
void computeLog(){
	Log[1] = 0;
	for (int i = 2; i <= N; i++)
		Log[i] = Log[i/2] + 1;
}

void print(Tuple t){
	cout << t.maxidL <<" " << t.Lmax << " " << t.Lsmax << endl;
	cout << t.maxidR <<" " << t.Rmax << " " << t.Rsmax << endl;
	cout << t.Midmax << endl;
}

Tuple getTuple(Tuple a, Tuple b){
	Tuple Max;
	cout <<"a b" << endl;
	print(a);
	print(b);
	cout << endl;
	if(a.Lmax > b.Lmax){
		Max.maxidL = a.maxidL;
		Max.Lmax = a.Lmax;
		if(b.Lmax >= a.Lsmax and b.maxidL != a.maxidL){
			Max.Lsmax = b.Lmax;
			Max.maxsidL = b.maxidL;
		}
		if(a.Lsmax >= )
		Max.Lsmax = max(b.Lmax, a.Lsmax);
	}
	else{
		Max.maxidL = b.maxidL;
		Max.Lmax = b.Lmax;
		Max.Lsmax = max(a.Lmax, b.Lsmax);
	}
	
	if(a.Rmax > b.Rmax){
		Max.maxidR = a.maxidR;
		Max.Rmax = a.Rmax;
		Max.Rsmax = max(b.Rmax, a.Rsmax);
	}
	else{
		Max.maxidR = b.maxidR;
		Max.Rmax = b.Rmax;
		Max.Rsmax = max(a.Rmax, b.Rsmax);
	}
	
	Max.Midmax = max(a.Midmax, b.Midmax);
	return Max;
	
}

void initRMQ(){
	// jhamela hoile eitare clear kore neya jaite pare.
	for (int i = 0; i < n; i++){
	  st[i][0] = Tuple(i + 1, i + 1, -2, -2, Left[i + 1], 0, Right[i + 1], 0, md[i + 1]);
	}
	int K = log2(n) + 1;
	for (int j = 1; j <= K; j++){
	  for (int i = 0; i + (1 << j) <= n; i++){
	      //st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	      st[i][j] = getTuple(st[i][j -1], st[i + (1 << (j - 1))][j - 1]);
	  }
	}
}

Tuple askRMQ(int L, int R){
        // amar mone hoi L + 1 kore query korte hobe
        // jemon 1 theke 3 er modde lcp lagle 2 theke 3 query korte hobe
        int j = Log[R - L + 1];
        Tuple minimum = getTuple(st[L][j], st[R - (1 << j) + 1][j]);
        return minimum;
    }
    

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    

    
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> len[i];
        cin >> s[i];
        cntr = 0; Max = 0; check = 0; cnt = 0; ll mn = INT_MAX, mx  = 0;
        for(int j = 0; j < len[i]; j++){
            if(s[i][j] == '1'){
                cntr++; check = 1;
            }
            else cntr--;
            Max = max(Max, cntr);
            mn = min(cntr, mn);
            mx = max(mx, cntr - mn);
        }
        md[i] = mx;
        tot[i] = cntr;
        Left[i] = Max - max(0LL, cntr);
        cntr = 0; Max = 0; mn = INT_MAX; mx = 0;
        for(int j = len[i] - 1; j >= 0; j--){
            if(s[i][j] == '1')cntr++;
            else cntr--;
            Max = max(Max, cntr);
            mn = min(cntr, mn);
            mx = max(mx, cntr - mn);
        }
        md[i] = max(md[i], mx);
        Right[i] = Max - max(0LL, cntr);
        presum[i] = presum[i - 1] + max(0LL, tot[i]);
    }
    initRMQ();
    
    for(int i = 1; i <= q; i++){
        cin >> l >> r; ans = 0;
        sum = 0; sum = presum[r] - presum[l - 1];
        Tuple mxq = askRMQ(l - 1, r - 1);
       print(mxq);
        if(mxq.maxidL == mxq.maxidR){
            sum += max(mxq.Lmax + mxq.Rsmax, mxq.Rmax + mxq.Lsmax);
        }
        else sum += mxq.Lmax + mxq.Rmax;
        cout << max(sum, (ll)mxq.Midmax) << endl;
        
    }
    
    /* 
        precedence : ! * / % + - << >> 
        < > <= >= == != & ^ | && ||
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
