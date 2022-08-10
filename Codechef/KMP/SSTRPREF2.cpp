
// Problem: Prefix as a Substring 2
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/SSTRPREF2
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
struct KMP{
    string text, pattern;
    vector<int> lps;
    KMP(string _text, string _pattern){
        text = _text;
        pattern = _pattern;
        lps.resize((int)pattern.size() + 1, 0);
        
    }
    vector <int> createlps(string pattern){
        int index = 0;
        for(int i = 1; i <  pattern.length(); ){
            if(pattern[i] == pattern[index]){
                lps[i] = index + 1;
                i++;
                index++;
            }
            else {
                if(index != 0){
                    index = lps[index - 1];
                }
                else lps[i] = 0, i++;
            }
        }
        return lps;
    }
    
};

vector<int> z_function(string s)
{
    int n = (int) s.length();
    vector < int > Z(n);
    Z[0] = 0; // Z[0] = 0 ধরে নিলাম
    for (int i = 1, L = 0, R = 0; i < n; ++i)
    {
        if (i <= R) // i সিগমেন্টের ভিতরে তা প্রথমেই চেক করে নিলাম
            Z[i] = min (R - i + 1, Z[i - L]); // সিগমেন্টে z[i] = z[i-L] থেকে কম বা সমান হতে পারে *শর্ত চেক
        else
            Z[i] = 0; // i সিগমেন্টের অংশ না হলে Z[i] এর মান শুন্য, মানে আমাদের Z[i] এর মান হিসাব করতে হবে।
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) // সিগমেন্টের বাহিরেও যদি অতিরিক্ত ক্যারেক্টার মিলে যায় তাহলে Z[i] এর মান বাড়াবো
            ++Z[i]; // মান বাড়ালাম
        if (i + Z[i] - 1 > R) // নতুন সিগমেন্ট পেলে সিগমেন্ট রেঞ্জ আপডেট করবো ।
            L = i, R = i + Z[i] - 1;
    }
    vector<int> newZ;
    int idx;
    for(int i = 0; i < n; i++){
        if(s[i] == '#'){
            idx = i + 1; break;
        }
    }
    for(int i = idx; i < n; i++)newZ.pb(Z[i]);
    return newZ;
    //Z[0] =  n; প্রবলেমের উপর ভিত্তি করে Z[0]=n হতে পারে
}
int arr1[1000006];
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
        cin >> s >> s1 >> s2;
        
        for(int i = 0; i <= s.size() + 10; i++)arr1[i] = 0;
        string s3 = s1 + '#' + s2;
        vector<int> Z2 = z_function(s3);
        KMP kmp(s1, s);
        Z2.pb(0);
        vector<int> lps = kmp.createlps(s);
        //for(auto it: lps)cout <<it <<" "; cout << endl;
        int i = 0, j = 0;
        while(i < s2.length()){
            if(s[j] == s2[i]){
                i++; j++;
                arr1[j] = max(arr1[j], Z2[i] + 1);
                //cout << i <<" "<< j <<" d "<< arr1[j] << endl;
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else ++i;
            }
            if(j == s.length()){
                j = lps[j - 1];
            }
        }
        lps[0] = -1;
        for(int i = s.size() - 1; i >= 0; i--){
            a = lps[i] - 1;
            //cout << i <<" "; 
            while(a >= 0 and arr1[i + 1] > arr1[a + 1]){
                //cout << a << " ";
                arr1[a + 1] = arr1[i + 1];
                a = lps[a] - 1;
            }
            //cout << endl;
        }
        sum = *max_element(Z2.begin(), Z2.end()) + 1;
        for(int i = 1; i <= s.size(); i++){
            if(arr1[i]){
                //cout << i <<" "<< arr1[i] << endl;
                sum += arr1[i];
            }
        }
        cout << sum << endl;
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
