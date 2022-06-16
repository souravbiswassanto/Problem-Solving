#include<bits/stdc++.h>
using namespace std;

int main (){

    int t;
    int n;
    int check;

    cin>>t;

    for (int i=1;i<=t;i++){
        cin>>n;
        check=0;
        printf("Case %d: ",i);
        for (int j=1;j<=n;j++){
            int a;
            cin>>a;
            if(a%2==0)check=1;

            if (check){
                if(a%2)cout<<0;
                else cout<<1;
            }

        }
        cout<<endl;
    }
    return 0;
}
