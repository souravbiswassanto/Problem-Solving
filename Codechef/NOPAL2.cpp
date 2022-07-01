// Problem: Palindromes Not Allowed
// Contest: CodeChef - Starters 44 Division 2
// URL: https://www.codechef.com/START44B/problems/NOPAL2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define   MAX    500006
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
ll A[MAX], B[MAX], C[MAX];
char ch(int n){
	return char(97 + n);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >>  n;
        cin >> s;
        if(n == 1){
        	yes; cout << s << endl; continue;
        }
        if(n == 2){
        	if(s[0] == s[1])no;
        	else {
        		yes; cout << s << endl;
        	}
        	continue;
        }
        for(int i = 0; i < 26; i++){
        	A[i] = 0;
        }
        for(int i = 0; i < n; i++){
        	A[s[i] - 97]++;
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < 26; i++){
        	if(!A[i])continue;
        	pq.push({A[i], i});
        }
        if(pq.size() == 1){
        	no;
        	continue;
        }
        s1 = "";
        pair<int, int> pr, pr1, pr2;
        pr = pq.top(); pq.pop();
        pr1 = pq.top(); pq.pop();
        s1 += ch(pr.second);
        s1 += ch(pr1.second);
        pr.first--;
        pr1.first--;
        if(pr.first)pq.push(pr);
        if(pr1.first)pq.push(pr1);
        check = 0;
        for(int i = 2; i < n; i++){
        	pr = pq.top(); pq.pop();
        	if((ch(pr.second) != s1[i - 2]) and(ch(pr.second) != s1[i - 1])){
        		s1 += ch(pr.second); pr.first--;
        		if(pr.first)pq.push(pr);
        	}
        	else {
        		if(pq.size() == 0){
        			check = 1; break;
        		}
        		pr1 = pq.top(); pq.pop();
        		if((ch(pr1.second) != s1[i - 2]) and(ch(pr1.second) != s1[i - 1])){
        			s1 += ch(pr1.second); pr1.first--;
        			pq.push(pr); if(pr1.first)pq.push(pr1);
        		}
        		else {
        			if(pq.size() == 0){
        				check = 1; 
        				break;
        			}
        			else{
        				pr2 = pq.top();
        				pq.pop();
        				s1 += ch(pr2.second);
        				pr2.first--;
        				if(pr2.first)pq.push(pr2);
        				pq.push(pr1);
        				pq.push(pr);
        			}
        		}
        	}

        }
		if(check)no;
		else {
			yes;
			cout << s1 << endl;
		}        

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
