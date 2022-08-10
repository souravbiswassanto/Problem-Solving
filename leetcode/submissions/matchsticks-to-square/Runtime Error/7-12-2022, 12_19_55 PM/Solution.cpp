// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), maxElement = 0;
        vector<int> oneSide, twoSide;
        int sumOfFourSide = 0;
        for(int i = 0; i < n; i++){
            sumOfFourSide += matchsticks[i];
            maxElement = max(maxElement, matchsticks[i]);
        }
        if(sumOfFourSide % 4)return false;
        int oneSideLen = sumOfFourSide / 4;
        if(maxElement > oneSideLen)return false;
        for(int i = 1; i < (1 << n); i++){
            int bitSum = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j))bitSum += matchsticks[j];
            }
            if(bitSum == oneSideLen)oneSide.push_back(i);
        }
        for(int i = 0; i < oneSide.size(); i++){
            for(int j = i + 1; j < oneSide.size(); j++){
                if((oneSide[i] & oneSide[j]) == 0)twoSide.push_back(oneSide[i] | oneSide[j]);
            }
        }
        sort(twoSide.begin(), twoSide.end());
        bool hashMap[(1 << n) + 5];
        for(auto it: twoSide)hashMap[it] = true;
        for(int i = 0; i < twoSide.size(); i++){
            int restTwoSide = (1 << n) - twoSide[i] - 1;
            if(hashMap[restTwoSide])return true;
            //if(binary_search(twoSide.begin(), twoSide.end(), restTwoSide))return true;
        }
        return false;
    }
};