#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  1000006

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

int a[MAX];
int b[MAX];
int c[MAX];

int main ()
{

    ///freopen("output.txt","w",stdout);

    fastIO();
    int n;
    int m;
    int cnt=0;
    int p=0,q=0,r=0,s=0;
    int cntr=0;
    int v=0;
    int check=0;
    int x,y,z;

    cin>>n;

    for (int i=0;i<n;i++){
        cin>>m;
        if (m==1)p++;
        if (m==2)q++;
        if (m==3)r++;
        if (m==4)s++;
    }

    cntr+=s;
    x=min(p,r);
    p-=x;
    r-=x;
    cntr+=x;
    cntr+=(q/2);
    if (q%2!=0)q=2;
    else q=0;
    cntr+=r;
    y=q+(p*1);
    z=y/4;
    cntr+=z;
    if (y%4!=0)cntr++;
    cout<<cntr<<endl;

    return 0;
}



