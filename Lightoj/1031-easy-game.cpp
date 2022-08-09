
// Problem: Easy Game
// Contest: LightOJ
// URL: https://lightoj.com/problem/easy-game
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
int dp[102][102], A[102], n;
int calc(int i, int j){
    if(i > j)return 0;
    int &ret = dp[i][j];
    if(ret != INT_MAX)return ret;
    int ret1 = -INT_MAX; int sum = 0;
    int ret2 = -INT_MAX;
    for(int k = i; k <= j; k++){
        sum += A[k];
        ret1 = max(ret1, sum - calc(k + 1, j));
    }
    sum = 0;
    for(int k = j; k >= i; k--){
        sum += A[k];
        ret2 = max(ret2, sum- calc(i, k - 1));
    }
    ret = max(ret1, ret2);
    return ret;
    
}

int main(){
    int test;
    cin >> test;
    for(int cs = 1; cs <= test; cs++){
        cin >> n;
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        int ans = calc(0, n - 1);
        cout << "Case "<<cs<<": "<<ans<<endl;
    }
}