class Solution {
public:
    int minOperations(vector<vector<int>>& a, int x) {
        int ans = 0, sum = 0;
        vector<int> b;
        for (auto& r : a) 
            for (auto x : r) {
                b.push_back(x);
                sum += x;
            }
        sort(b.begin(), b.end());
        for (int i=0; i+1<b.size(); ++i)
            if ((b[i+1]-b[i]) % x != 0)
                return -1;
        

        int val = b[b.size()/2];
        for (auto c : b) ans += abs(val - c) / x;
        return ans;
    }
};