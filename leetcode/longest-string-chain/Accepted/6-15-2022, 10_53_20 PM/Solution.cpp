// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    bool static compare(string A, string B){
        if(A.size() == B.size()){
            return A > B;
        }
        return A.size() < B.size();
    }
    int longestStrChain(vector<string>& words) {
        short int dp[words.size()];
        sort(words.begin(), words.end(), compare);
        for(int i = 0; i < words.size(); i++){
            dp[i] = 1;
        }
        for(int i = 0; i < words.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                int cntr = 0, cnt = 0;
                if(words[i].size() - words[j].size() > 1)break;
                if(words[i].size() - 1 != words[j].size())continue;
                for(int k = 0; k < words[i].size(); k++){
                    if(words[i][k] != words[j][cnt++]){
                        cntr++;
                        cnt--;
                    }
                }
                if(cntr == 1){
                    if(dp[i] < dp[j] + 1)dp[i] = dp[j] + 1;
                }
                
            }
        }
        short int Max = 0;
        for(int i = 0; i < words.size(); i++){
            Max = max(dp[i], Max);
        }
        return Max;
    }
};