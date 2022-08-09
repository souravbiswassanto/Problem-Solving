#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Max;

class trie{
    public:
    trie* children[5];
    int prefix;
    trie(){
        prefix=0;
        for(int i=0;i<5;i++)children[i]=NULL;
    }
};

ll Insert(trie* head,string S){
    trie* cur=head;ll ans;

    for(int i=0;i<S.size();i++){
        int id;
        if(S[i]=='A')id=1;
        if(S[i]=='T')id=2;
        if(S[i]=='G')id=3;
        if(S[i]=='C')id=0;
        trie* node=cur->children[id];
        if(!node){
            trie* child=new trie();
            cur->children[id]=child;
        }
        cur=cur->children[id];
        cur->prefix++;
        ans=(i+1)*cur->prefix;
        Max=max(ans,Max);
    }
    return Max;
}

void del(trie* cur)
{
    for (int i = 0; i < 5; i++)
        if (cur->children[i])
            del(cur->children[i]);
    delete (cur);
}

int main(){

    ll T;
    //cin>>T;
    scanf("%lld",&T);

    for(int k=1;k<=T;k++){

        string S;
        char s[56];
        ll n,res=0;
        Max=0;
        trie* root=new trie();
        scanf("%lld",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            S=s;
            res=max(res,Insert(root,S));
        }
        printf("Case %d: %lld\n",k,res);
        del(root);
    }

}
