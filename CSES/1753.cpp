
// Problem: String Matching
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1753
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
int autom[1000006][27];
int kmp(string text,string pattern){
       
     for(int i=0;i<26;i++)
        autom[0][i] = 0;
     for(int i=0;i<pattern.size();i++) {
        int nx = autom[i][pattern[i]-'a'];
        autom[i][pattern[i]-'a'] = i+1;
        for(int j=0;j<26;j++) {
          autom[i+1][j] = autom[nx][j];
        }
      }
    int i=0,j=0,Counter=0;

    while(i<text.size()){
        j = autom[j][text[i] - 'a'];
        if(j==pattern.size()){
            j = autom[j - 1][text[i]-'a'];
            Counter++;   
        }
        i++;
    }
    return Counter;
}

int main(){

    int n;
    n = 1;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        char s[1000006];
        char s1[1000006];

        scanf("%s %s",s,s1);
        string text,pattern;
        text=s;pattern=s1;
        
        int ans=kmp(text,pattern);
        printf("%d\n",ans);

    }

    return 0;
}
