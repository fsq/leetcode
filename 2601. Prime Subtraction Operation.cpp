class Solution {
public:

    bool primeSubOperation(vector<int>& nums) {
        vector<int> p={0}, vis(1001, true);
        for (int x=2; x*x<vis.size(); ++x) {
            if (vis[x]) {
                for (int i=x*x; i<vis.size(); i+=x) vis[i] = false;
            }
        }
        for (int x=2; x<vis.size(); ++x)
            if (vis[x]) {
                p.push_back(x);
            }

        int pre = 0;
        for (auto x : nums) {
            // x - p > pre ==> p < x-pre
            auto it = lower_bound(p.begin(), p.end(), x-pre);
            if (it != p.begin()) {
                  pre = x - *prev(it);
            } else {
                return false;
            }     
        }
        return true;
    }
};