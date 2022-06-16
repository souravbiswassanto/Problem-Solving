/* A C++ program to answer queries to check whether
the substrings are palindrome or not efficiently */
#include<bits/stdc++.h>
using namespace std;

#define p 101
#define MOD 1000000007
#define MAX  1000006
#define ll unsigned long long

ll prefix[MAX];
ll suffix[MAX];
ll power[MAX];

ll modPow(ll base,ll exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    ll temp = modPow(base, exponent/2);

    if (exponent %2 ==0)
        return (temp%MOD * temp%MOD) % MOD;
    else
        return ((( temp%MOD * temp%MOD)%MOD) * base%MOD) % MOD;
}

ll findMMI(ll n)
{
    return modPow(n, MOD-2);
}

void computePrefixHash(string str, int n)
{
    prefix[0] = 0;
    prefix[1] = str[0];

    for (int i=2; i<=n; i++)
        prefix[i] = (prefix[i-1]%MOD +
                     (str[i-1]%MOD * power[i-1]%MOD)%MOD)%MOD;

    return;
}

void computeSuffixHash(string str, int n)
{
    suffix[0] = 0;
    suffix[1] = str[n-1];

    for (int i=n-2, j=2; i>=0 && j<=n; i--,j++)
        suffix[j] = (suffix[j-1]%MOD +
                     (str[i]%MOD * power[j-1]%MOD)%MOD)%MOD;
    return;
}

int queryResults(string str,int n)
{
    for (int i=0; i<str.size(); i++)
    {
        int L = 0;
        int R = str.size()-i-1;

        ll hash_LR =((prefix[R+1]-prefix[L]+MOD)%MOD *findMMI(power[L])%MOD)%MOD;

        ll reverse_hash_LR =
            ((suffix[n-L]-suffix[n-R-1]+MOD)%MOD *findMMI(power[n-R-1])%MOD)%MOD;

        if (hash_LR == reverse_hash_LR )
        {
            return R;
        }
    }

    return -1;
}

int queryResults1(string str, int n)
{
    for (int i=0; i<str.size(); i++)
    {
        int L = i;
        int R = str.size()-1;

        ll hash_LR =((prefix[R+1]-prefix[L]+MOD)%MOD *findMMI(power[L])%MOD)%MOD;

        ll reverse_hash_LR =
            ((suffix[n-L]-suffix[n-R-1]+MOD)%MOD *findMMI(power[n-R-1])%MOD)%MOD;

        if (hash_LR == reverse_hash_LR )
        {
            return i;
        }
    }

    return -1;
}

void computePowers()
{
    power[0] = 1;

    for(int i=1; i<=MAX; i++)
        power[i] = (power[i-1]%MOD * p%MOD)%MOD;

    return;
}

int main()
{
    int q;
    cin>>q;

    while(q--){
        string str ;
        cin>>str;
        int n = str.length();

        computePowers();
        computePrefixHash(str, n);
        computeSuffixHash(str, n);
        int idx1=queryResults1(str,n);
        int idx=queryResults(str,n);

        int l=0,r=n-1,cntr=0;
        while(l<r){
            if(str[l]==str[r]){
                l++,r--;cntr+=2;
            }
            else {
                break;
            }
        }
        int b=l;
        int Ll=l;int Rr=r;
        ll gap=0;
        while(l<r){
            if(str[l]==str[r]){
                l++,r--;gap+=2;
            }
            else {
                l=b;
                gap=0;
            }
        }
        if(l==r)gap+=1;

        ll gap1=0;
         b=Rr;
        while(Ll<Rr){
            if(str[Ll]==str[Rr]){
                Ll++,Rr--;gap1+=2;
            }
            else {
                Rr=b;
                gap1=0;
            }
        }
        if(Ll==Rr)gap1+=1;

        cntr+=max(gap1,gap);
        idx1=n-idx1;
        cout<<cntr<<" "<<idx<<" "<<idx1<<endl;
        }
    return (0);
}
