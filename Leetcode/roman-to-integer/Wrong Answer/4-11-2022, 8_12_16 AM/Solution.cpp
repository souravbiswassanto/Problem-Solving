// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> M;
        M['M'] = 1000;
        M['D'] = 500;
        M['C'] = 100;
        M['L'] = 50;
        M['X'] = 10;
        M['V'] = 5;
        M['I'] = 1;
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum += M[s[i]];
        }
        return sum;
    }
};