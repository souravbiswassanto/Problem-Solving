#include<bits/stdc++.h>
using namespace std;

vector<int>createlps(string pattern){
    vector<int>lps(pattern.size());
    int index=0;

    for(int i=1;i<pattern.size();){
        if(pattern[i]==pattern[index]){
            lps[i]=index+1;
            index++;i++;
        }
        else {
            if(index!=0){
                 index=lps[index-1];
            }
            else {lps[i]=0;i++;}
        }
    }
    return lps;
}

int Count(string text,string pattern){
    int i=0,j=0;int cnt=0;
    vector<int>lps=createlps(pattern);
    while(i<text.size()){
        if(pattern[j]==text[i]){
            cnt++;i++;j++;
        }
        else {
            if(j==0){
                i++;
            }
            else {j=lps[j-1];cnt=0;}
        }
    }
    return j;
}

int main(){

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        char s[1000006];
        scanf("%s",s);
        int len=strlen(s);
        string S;S=s;
        string rev=s;
        reverse(rev.begin(),rev.end());
        int cnt=Count(S,rev);
        int ans=len+(len-cnt);
        printf("Case %d: %d\n",i,ans);
    }

}
