class Solution {
public:
    
    vector<int> pathInZigZagTree(int n) {
        int d = ceil(log(n+1) / log(2));
        if (!(d & 1))
            n = (1<<d) - n + (1<<(d-1)) - 1;
        vector<int> ans;
        while (n > 0) {
            int ac = n;
            if (!(d & 1))
                ac = (1<<d) - ac + (1<<(d-1)) - 1;
            ans.push_back(ac);
            n >>= 1;
            --d;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};