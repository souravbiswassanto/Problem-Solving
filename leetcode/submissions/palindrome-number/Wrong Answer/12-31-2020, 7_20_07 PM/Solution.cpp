// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long long ans = 1, rev = 0; 
        while (n){
            int rem = n % 10;
            if(x < 0) rem += 10;
            rem %= 10;
            n /=  10;
            rev = rev * ans + rem;
            ans *= 10LL;
        }
        if(rev == x){
            return "true";
        }
        else return "false";
    }
};