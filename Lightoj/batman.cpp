
// Problem: Batman
// Contest: LightOJ
// URL: https://lightoj.com/problem/batman
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;

string s1, s2, s3;
int n, m, k;
int dp[51][51][51];

int calc(int i, int j, int l){
    if(i == n or j== m or l == k){
        return 0;
    }
    int &ret = dp[i][j][l];
    if(ret != -1)return ret;
    ret = 0;
    if(s1[i] == s2[j] and s2[j] == s3[l]){
        ret = calc(i + 1, j + 1, l + 1) + 1;
    }
    else{
        for(int mask = 1; mask < 8; mask++){
            int ii = i, jj = j, ll = l;
            if(mask & (1 << 0))ii++;
            if(mask & (1 << 1))jj++;
            if(mask & (1 << 2))ll++;
            ret = max(ret , calc(ii, jj, ll));
        }
    }
    return ret;
    
}

int main(){
    int test;
    cin >> test;
    for(int cs = 1; cs <= test; cs++){
        cin >> s1 >> s2 >> s3;
        memset(dp, -1, sizeof(dp));
        n = s1.size();
        m = s2.size();
        k = s3.size();
        int ans = calc(0, 0, 0);
        cout <<"Case "<<cs<<": "<< ans <<"\n";
    }
    return 0;
}