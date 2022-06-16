
// Problem: Conveyor Belt
// Contest: CodeChef - International Coding Challenge
// URL: https://www.codechef.com/ICOC2022/problems/CNVYBELT
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
using namespace std;
#define ll long long

char ch[1000006], ch1[1000006];
struct Manachar{
    
    int n;
    vector<int> P;
    Manachar(int _n){
        n = _n;
        P.resize(2 * n + 10, 0);
    }
    
    string convert(string s){
    	string nwS = "@";
        for (int i = 0; i < (int)s.size(); i++) {
            nwS += "#" + s.substr(i, 1);
        }
        nwS += "#$";
        return nwS;
    }
    
    void build(string s, int N){
    	int _n = s.size();
    	int l = 0, r = -1;
	    for(int i = 1; i < (int)s.size() - 1; i++){
    		int k;
    		if(i > r){
    			k = 0;
    		}
    		else {
    			int j = r - i + l;
    			k = min (P[j], r - i);
    		}
    		while(i + k < _n and i - k >= 0 and s[i+k] == s[i-k] and k < N)k++;
    		if(s[i-k] != s[i+k])k--;
    		P[i] = k;
    		if(i + k > r){
    			r = i + k;
    			l = i - k;
    		}
    	}
    }
    ll calculate(string s, string original, int N){
        int large = 0, small = 0, equal = 0;
    	for(int i = 1; i < s.size(); i++){
    	    //cout << s[i] <<" ";
    	}
    	//cout << endl;
    	for(int i = N + 1; i < s.size() - 1 - N -1; i+= 2){
    	    //cout << P[i] / 2<< " ";
    	    if(P[i] == N){
    	        equal++;
    	    }
    	    else if(s[i - P[i] - 1] > s[i + P[i] + 1])large++;
    	    else small++;
    		
    	}
    	printf("%d %d %d\n", large, small, equal);
    	
    }
    
    void solve(string s, int N){
        string original = s;
    	s = convert(s);
        build(s, N);
        calculate(s, original, N);
    }
};

int main(){
    
    int testCase;
    scanf("%d", &testCase);
    while (testCase--){
        scanf("%s %s", ch, ch1);
        string s = ch;
        string s1 = ch1;
        string revs = s;
        reverse(revs.begin(), revs.end());
        string S;
        S = revs + s1 + revs + s1;
        int n = S.size();
        Manachar mc(n);
        mc.solve(S, s. size() + s.size());
    }
}