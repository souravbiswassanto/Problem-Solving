#include<bits/stdc++.h>
using namespace std;

vector<int>createlps(string pattern){
    vector<int>lps(pattern.size());
    int index=0;
    for(int i=1;i<pattern.size();){
        if(pattern[i]==pattern[index])
        {
            lps[i]=index+1;
            i++,index++;
        }
        else {
            if(index!=0){index=lps[index-1];}
            else {lps[i]=0;i++;}
        }
    }
    return lps;
}

int kmp(string text,string pattern){

    vector<int>lps=createlps(pattern);
    int i=0,j=0,Counter=0;
    for(auto it:lps)cout<<it<<" ";cout<<endl;

    while(i<text.size()){
        if(text[i]==pattern[j]){
            i++,j++;
        }
        else {
            if(j!=0)j=lps[j-1];
            else j=0,i++;
        }
        if(j==pattern.size())Counter++;
    }
    return Counter;
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char s[1000006];
        char s1[1000006];

        scanf("%s %s",s,s1);
        string text,pattern;
        text=s;pattern=s1;
        int ans=kmp(text,pattern);
        printf("Case %d: %d\n",i,ans);

    }

    return 0;
}
