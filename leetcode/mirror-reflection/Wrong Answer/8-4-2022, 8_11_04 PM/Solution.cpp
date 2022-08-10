// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int a = p + q;
        int lcm = (a * p) / __gcd(a, p);
        cout << lcm << endl;
        int b = p * 4;
        
        if(lcm % b == p)return 0;
        if(lcm % b == 2 * p) return 1;
        if(lcm % b == 3 * p) return 2;
        return 1;
    }
};