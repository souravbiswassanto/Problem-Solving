#include<bits/stdc++.h>
using namespace std;

int main(){

    string s,s1;
    string CSE="CSE";
    string EEE="EEE";
    string SWE="SWE";
    int T;

    cin>>T;
    cin.ignore();

    for (int i=1;i<=T;i++){
        getline(cin,s);

        int check1=0;
        int check=0;
        int check2=0;
        int cntr=0;
        int check3=0;

        for (int j=0;j<s.length();j++){
            s1=s.substr(j,3);

            if (s1==CSE){
                if (check)continue;
                if ((s[j-1]=='.'||s[j-1]==','||s[j-1]==' '||j==0)&&(s[j+3]=='.'||s[j+3]==','||s[j+3]==' '||j+2==s.length()-1)){
                    cntr++;
                        check=1;
                }
                continue;
            }
            if (s1==EEE){
                if (check1)continue;
                if ((s[j-1]=='.'||s[j-1]==','||s[j-1]==' '||j==0)&&(s[j+3]=='.'||s[j+3]==','||s[j+3]==' '||j+2==s.length()-1)){
                    cntr++;
                        check1=1;
                }
                continue;
            }
            if (s1==SWE){
                if (check2)continue;
                if ((s[j-1]=='.'||s[j-1]==','||s[j-1]==' '||j==0)&&(s[j+3]=='.'||s[j+3]==','||s[j+3]==' '||j+2==s.length()-1)){
                    cntr++;
                        check2=1;
                }
                continue;
            }

            if (((int)s1[0]>=65&&(int)s1[0]<=90)&&((int)s1[1]>=65&&(int)s1[1]<=90)&&((int)s1[2]>=65&&(int)s1[2]<=90)){
                if (check3)continue;
                if ((s[j-1]=='.'||s[j-1]==','||s[j-1]==' '||j==0)&&(s[j+3]=='.'||s[j+3]==','||s[j+3]==' '||j+2==s.length()-1)){
                        check3=1;
                }
            }
        }

        if(cntr>=3){
            printf("Case %d: SUST Tech Fest\n",i);
        }
        else if (cntr==1&&!check3&&check){
            printf("Case %d: SUST CSE Carnival\n",i);
        }
        else {
            printf("Case %d: Festival of SUST\n",i);
        }
    }

    return 0;
}
