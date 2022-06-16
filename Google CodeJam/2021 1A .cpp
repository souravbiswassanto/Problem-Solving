
// Problem: Append Sort
// Contest: Google Coding Competitions - Round 1A 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007549e5
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

string intst(ll n){
    string s ="";
    while(n){
        int rem = n % 10;
        n /= 10;
        s += char(48 + rem);
    }
    reverse(s.begin(), s.end());
    return s;
}

ll sti(string a, int base = 10){
	ll k = 0;
	for (int i = 0; i < (int)a.size(); ++i){
		k *= base;
		k += a[i]-'0';
	}
	return k;
}
int Equal(string s, string prv){
    bool isequal = true, isg = false, isl = false;
    for(int j = 0; j < s.size(); j++){
        if(s[j] != prv[j]){
            if(s[j] > prv[j])return 2;
            else return 3;
        }
    }
    return 1;
}

int compare(string s, string prv){
    bool isequal = true, isg = false, isl = false;
    int a = max(s.size(), prv.size());
    string z = "";
    //cout << s <<" "<<prv<< endl;
    for(int i = 0; i < a - s.size(); i++){
        z += '0';
    }
    s = z + s;
    z = "";
    for(int i = 0; i < a - prv.size(); i++)z += '0';
    prv = z + prv;
    //cout << s <<" "<< prv << endl;
    for(int j = 0; j < s.size(); j++){
        if(s[j] != prv[j]){
            if(s[j] > prv[j])return 2;
            else return 3;
            
            break;
        }
    }
    return 1;
}



int main ()
{
    ll a, b, c, d,  m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    int test;
    scanf("%d", &test);

    while(test--){
        int n; string S[105];
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            cin >> S[i];
        }
        cntr = 0; printf("Case #%d: ", ++cnt);
        for(int i = 1; i < n; i++){
            if(compare(S[i], S[i - 1]) == 2)continue;
            s = S[i];
            string prv = S[i - 1];
            int iseq1 = Equal(s, prv);
            prv = findSum(prv, "1");
            int iseq2 = Equal(s, prv);
            //cout << iseq2 <<" "<<iseq1<<endl;
            if(iseq1== 1 and iseq2 == 1){
                //cout << iseq2 <<" "<<iseq1<<endl;
                cntr += (prv.size() - s.size());
                S[i] = prv;
            }
            else{
                
                a = Equal(S[i], S[i - 1]);
                if(a == 1 or a == 3){
                    b = S[i - 1].size() - S[i].size() + 1;
                    for(int j = 1; j <= b; j++){
                        cntr++; S[i] += '0';
                    }
                }
                else if(a == 2){
                    b = S[i - 1].size() - S[i].size();
                    for(int j = 1; j <= b; j++){
                        cntr++; S[i] += '0';
                    }
                }
                
            }
        }
        
        printf("%d\n", cntr);
        //for(int i = 0; i < n; i++)cout << S[i]<<" "; cout << endl;

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
