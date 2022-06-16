// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        bool check = false;
        if(x < 0) {
            check = true;
            x *= -1;
        }
        string s = "";
        while(x){
            int rem = x % 10; x /= 10;
            s += rem + 48;
        }
        x = 0;int ans = 1;
        for(int i = s.size()-1; i >= 0; i--){
            x += (s[i] - 48) * ans ;
            ans *=  10;
        }
        if(check){
            return -1*x;
        }
        else return x;
        
    }
};