/*########  IN THE NAME OF ALLAH   ##########*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 999999999999999999
#define nl cout<<endl
#define  r0 return 0
#define  r1 return 1
#define sf1(x)  scanf("%lld",&x)
#define sf2(x,y)  scanf("%lld %lld",&x,&y)
#define sf3(x,y,z)  scanf("%lld %lld %lld",&x,&y,&z)
#define pf1(x)  printf("%lld\n",x)
#define pf2(x,y)  printf("%lld %lld\n",x,y)
#define pf3(x,y,z)  printf("%lld %lld %lld\n",x,y,z)
#define yes  printf("YES\n")
#define no  printf("NO\n")
#define pc(x)  printf("Case %lld:",x)
#define pb push_back
#define mp make_pair
#define pa pair<ll,ll>
#define mem(a,b) memset(a,b,sizeof(a))
#define MIN  -99999999999999999
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define sp printf(" ")
#define vs(v) (v.begin(),v.end())
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll power(ll B,ll P){ if(P==0) return 1; ll X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
ll fx[]={1,-1,0,0}; ll fy[]={0,0,1,-1};

ll A[300005],B[300005],C[300005],visited[300005],level[300005];

char CH[1000][1000],ch;

vector<ll>V;

vector<ll>G;
ll M[102][102];
int main()
{
   ll T,N,E,u,v,i,j,k,sum=0,ck=0,x,y;

   string S,S1;

   double d1,d2,d3;

   cin>>N>>E;
   swap(N,E);
   for(i=1;i<=N;i++)
   {
       for(j=1;j<=E;j++)cin>>M[i][j];
   }

   for(i=1;i<=E;i++)
   {
       ck=0;
       for(j=1;j<=N;j++)
       {
           ck+=M[j][i];
       }
       V.pb(ck);
   }

   for(i=0;i<V.size()-1;i++)
   {
       V[i]=V[E-1]-V[i];
       if(V[i]<=0) {cout<<"0"<<endl;r0;}
   }

   vector<pair<ll,ll> >V1[106];
   for(i=1;i<=N;i++)
   {
       for(j=1;j<E;j++)
       {
           ll a=M[i][E]-M[i][j];
           V1[j].pb(mp(a,i));

       }
   }

   for(i=1;i<E;i++)
   {
       sort(V1[i].begin(),V1[i].end(),greater<pair<ll,ll>>());
   }

   ll Maxx=0,idx,ans=9999999999,mn=9999999999,cntr=0;
   for(i=1;i<E;i++)
   {
       ll b=V[i-1];
       sum=0;
       for(j=0;j<V1[i].size();j++)
       {
           sum+=V1[i][j].first;
           if(sum>=b)
           {
               cntr=1;
               ans=j+1;
               break;
           }
       }
       if(ans<mn)
       {
           idx=i;
           mn=ans;
       }
   }
   if(cntr==0)
   {
       cout<<N<<endl;
       for(i=1;i<=N;i++) cout<<i<<" ";
       r0;
   }
   cout<<mn<<endl;

   for(i=0;i<V1[idx].size();i++)
   {
       if(i==mn) break;
       cout<<V1[idx][i].second<<" ";
   }
   nl;
 /************ALEYA YOUSUF ************/


 /************ALLAH IS ALMIGHTY ************/
return 0;

}
