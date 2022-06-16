#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<int> g[100005];
vector<int> st;
int cnt[100005];
int stree[400040];
int ans[100005];
int value;
void dfs(int u,int par){
    cnt[u]=1;
    for(int v:g[u]){
        if(v==par) continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
    st.pb(u);
}

void build(int node,int b,int e){
    if(b==e){
        stree[node]=1;return;
    }
    int mid=(b+e)/2;

    int left=node*2;
    int right=node*2+1;

    build(left,b,mid);
    build(right,mid+1,e);
    stree[node]=stree[left]+stree[right];
}

void update (int node, int b,int e,int l,int r){

    if(!stree[node])return;
    if(value<=0)return;
    if(r<b||l>e)return;
    if(b==e){
        stree[node]=0;
        value--;
        ans[st[b-1]]=1;
        return;
    }
    int mid=(b+e)/2;

    int left=node*2;
    int right=node*2+1;
    update(left,b,mid,l,r);
    update(right,mid+1,e,l,r);
    stree[node]=stree[left]+stree[right];
}

int main(){
    int t,n,x,y;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){

        scanf("%d",&n);
        for(int i=1;i<n;i++){

            scanf("%d %d",&x,&y);
            g[x].pb(y);
            g[y].pb(x);
        }

        for(int i=1;i<=n;i++){
            sort(g[i].begin(),g[i].end());
        }

        dfs(1,-1);

        int idx[n+4]={0},idx1[n+4]={0};

        for(int i=0;i<st.size();i++){
            idx[st[i]]=i+1;
            idx1[i+1]=st[i];
        }

        int q;

        scanf("%d",&q);
        printf("Case %d:\n",cs);

        build(1,1,n);

        while(q--){
            int c;
            scanf("%d",&c);
            if(c==1){

                scanf("%d %d",&x,&value);
                int id=idx[x]-cnt[x]+1;
                update(1,1,n,id,idx[x]);
            }
            else{

                scanf("%d",&x);
                printf("%lld\n",ans[x]);
            }
        }
        for(int i=1;i<=n;i++){
            g[i].clear();
            cnt[i]=0;
            ans[i]=0;
        }
        st.clear();
    }
    return 0;
}
