#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  300006
#define  mem(a,v)   memset(a,v,sizeof(a))

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll parent[MAX];

void make_parent(int n){
    for (int i=1;i<=n;i++){
        parent[i]=i;
    }
}

int Find (int r){

    if (parent[r]==r){
        return parent[r];
    }
    return parent[r]=Find(parent[r]);

}

void unionthem(int a,int b){
    int a1=Find(a); int b1=Find(b);

    if (a1!=b1){
        parent[b1]=a1;
    }

}



int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;
    set<int>S;
    set<int>::iterator it;

    cin>>n;

    make_parent(n);

    for (int i=1;i<=n;i++){
        cin>>A[i];
        unionthem(i,A[i]);
    }

    for (int i=1;i<=n;i++){
        int parentt=Find(i);
        S.insert(parentt);
    }

    cout<<S.size()<<endl;

    return 0;
}
