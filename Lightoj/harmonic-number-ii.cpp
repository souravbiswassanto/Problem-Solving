
// Problem: Harmonic Number (II)
// Contest: LightOJ
// URL: https://lightoj.com/problem/harmonic-number-ii
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sumofnbyi(ll n){
    ll ans = 0, minVal; // use 1LL * i * i if necessary
    for (int i = 1; i *1LL* i <= n; i++) {
        ll lf = n / (i + 1), rg = n / i;
        if (lf >= rg) continue;
        minVal = lf; // interval (lf, rg]
        ans += (i * (rg - lf));
    }
    for(int i = 1; i < minVal + 1; i++) {
        ans += n / i;
    }
    cout << ans << endl;

}

int main(){
    int n;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        cout <<"Case "<<i<<": ";
        sumofnbyi(n);
    }
    return 0;
}