class Solution {
public:
    int countOperations(int a, int b) {
        int ans = 0;
        while (a && b) {
            if (a > b) 
                a -= b;
            else 
                b -= a;
            ++ans;
        }
        return ans;
    }
};