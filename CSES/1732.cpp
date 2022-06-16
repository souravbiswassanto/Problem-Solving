#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

struct KMP{
    
    string pattern;
    vector<int> lps;
    KMP(string _pattern){
        pattern = _pattern;
        lps.resize((int)pattern.size() + 3, 0);
    }
    vector <int> createlps(string pattern){
        int index = 0;
        for(int i = 1; i <  pattern.length(); ){
            if(pattern[i] == pattern[index]){
                lps[i] = index + 1;
                i++;
                index++;
            }
            else {
                if(index != 0){
                    index = lps[index - 1];
                }
                else lps[i] = 0, i++;
            }
        }
        return lps;
    }
};

int main(){
    
    string s, s1;
    cin >> s;
    KMP matcher(s);
    auto V = matcher.createlps(s);
    int n = s.size();
    int idx = V[n - 1];

    set<int> S;
    S.insert(idx);
    while(idx){
        S.insert(V[idx - 1]);
        idx = V[idx - 1];
    }
    for(auto it: S){
        if(it)cout <<it<<" ";
    }
}