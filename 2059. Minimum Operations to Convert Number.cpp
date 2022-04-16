class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        vector<int> vis(1001);
        queue<int> q;
        q.push(start);
        for (int step=1; q.size(); ++step)
            for (int _t=q.size(); _t; --_t) {
                int x = q.front(); q.pop();
                for (auto y : nums) 
                    for (auto z : vector<int>{x+y, x-y, x^y}) {
                        if (z == goal) return step;
                        if (z>=0 && z<=1000 && !vis[z]) {
                            vis[z] = true;
                            q.push(z);
                        }
                    }
            }
        return -1;
    }
};