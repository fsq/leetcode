class Solution {
public:
    int findMinFibonacciNumbers(int x) {
        vector<int> a = {1, 1};
        while (a.back()<x) {
            a.push_back(a.back() + a[a.size()-2]);
        }
        int ans = 0;
        for (int i = a.size()-1; x>0 && i>=0; --i)
            if (x>=a[i]) {
                x -= a[i];
                ++ans;
            }
        return ans;
    }
};