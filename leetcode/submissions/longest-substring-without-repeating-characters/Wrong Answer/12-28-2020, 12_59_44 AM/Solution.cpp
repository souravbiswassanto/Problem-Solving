// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int A[260];
        for(int i = 0; i <= 257; i++)A[i] = 0;
        int l = 0, r = 0,Max = 0;
        for(int i = 0; i < s.size(); i++){
            if(A[(int)s[i]]){
                Max = max(Max,r-l);
                for(int j = l; j <= r;j++){
                    if(s[i]==s[j])l = j;
                    A[(int)s[i]] = 0;
                }

                r++;
            }
            else r++;
            A[(int)s[i]] = 1;
        }
        Max = max(Max,r-l);
        return {Max};
    }
};