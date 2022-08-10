// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> v[27];
        for(int i = 0; i < s.size(); i ++){
            v[s[i] - 97].push_back(i);
        }
        for(int i = 0; i < 26; i++){
            v[i].push_back(INT_MAX);
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            string query = words[i];
            int Index = -1; bool check = false;
            for(int j = 0; j < query.size(); j++){
                int a = query[j] - 97;
                auto it = upper_bound(v[a].begin(), v[a].end(), Index);
                if(*it == INT_MAX){
                    check = true; break;
                }
                Index = *it;
            }
            if(!check)ans++;
        }
        return ans;
    }
};