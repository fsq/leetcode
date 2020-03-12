class Solution {
public:
    string generateTheString(int n) {
        if (n & 1) {
            return string(n, 'a');
        } else {
            return string(1, 'a') + string(n-1, 'b');
        }
    }
};