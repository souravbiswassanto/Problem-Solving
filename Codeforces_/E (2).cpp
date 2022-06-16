#include<bits/stdc++.h>
using namespace std;

struct comp{

    int a;
    int b;
    comp(int c,int d){
        a=c;
        b=d;
    }

};
struct check{
    int a;
    int b;
    check(int c,int d){
        a=c;
        b=d;
    }
};
bool compare (comp A,comp B){
    if(A.a==B.a){
        return A.b>B.b;
    }
    else return A.a>B.a;
}
vector<comp>V;
vector<check>V1;
int main()
{
    int n;
    int a,b;
    int lp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cin>>a>>b;
       int temp;
       temp=min(a,b);
       a=max(a,b);
       b=temp;
       V.push_back(comp(a,b));
    }
    sort(V.begin(),V.end(),compare);

//    for(int i=0;i<n;i++){
//        cout<<V[i].a<<" "<<V[i].b<<endl;
//    }
    int cntr=1;
    int key1,key2;
    int c,d;
    for(int i=0;i<n;i++){
        key1=V[i].a;
        key2=V[i].b;
        for(int j=i+1;j<n;j++){
            lp=V[j].a;
            if (key2>lp){
                cntr++;
                c=V[j].a;
                d=V[j].b;
                V1.push_back(check(key1,key2));
                cout<<key1<<" "<<key2<<endl;
                i=j-1;break;
            }
            if(key2<V[j].b){
                key1=V[j].a;
                key2=V[j].b;
            }
        }
    }
    V1.pb(check(key1,key2));
    int m=V1.size();

    for(int i)
    cout<<cntr<<endl;
    return 0;
}
