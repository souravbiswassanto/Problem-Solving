#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root; 

char input[5005];
int dp[5003], Len;
const int mod = 1000000007;

struct Trie{
    string s;
    
    void insert(char str[], int len){
        node* curr = root;
        //printf("%s\n", str);
        for (int i = 0; i < len; i++) {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL){
                curr->next[id] = new node();
                //cout <<i <<" New node created"<< endl;
            }
            curr = curr->next[id];
        }
        curr->endmark = true;
    }
    
    void search(int len){
        node* curr = root;
        //cout <<len <<" len " <<Len << endl;
        for (int i = len; i < Len; i++) {
            int id = input[i] - 'a';
            //cout << id <<" "<< bool(curr->next[id] == NULL) << endl;
            if (curr->next[id] == NULL)
                return ;
            curr = curr->next[id];
            if(curr->endmark == true){
                dp[len] += dp[i + 1] ;
                dp[len] %= mod;
                //cout << len <<" "<<dp[i + 1] << endl;
            }
            //cout << "Here" << endl;
            
        }
    }  
    
    void solve(){
        int k;
        scanf("%d", &k);
        root = new node();
        for(int i = 0; i < k; i++){
            
            char ch[100006];
            scanf("%s", ch);
            int Size = strlen(ch);
            insert(ch, Size);
        }
        dp[Len] = 1;
        for(int i = Len - 1; i >= 0; i--){
            search(i);
        }
        printf("%d\n", dp[0]);
    }

};

int main (){
    scanf("%s", input);
    Len = strlen(input);
    Trie trie;
    trie.solve();
}