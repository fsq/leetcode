class Solution {
public:
    
    // https://leetcode.com/problems/2-keys-keyboard/description/
    // O(sqrt(n)) time solution
    // f[i] = min(f[i/j]+j), gives O(n^1.5)
    // we want the smallest j, give O(sqrt(n))
    
    int minSteps(int n) {
        if (n==1) return 0;
        int j = 2, ans = 0;
        while (n>1) {
            if (n%j==0) {
                ans += j;
                n /= j;
            } else 
                ++j;
            // when n is a prime we won't loop j to n
            if (n>1 && j>sqrt(n)) {
                ans += n;
                break;
            }
        }
        
        
        return ans;
    }
};