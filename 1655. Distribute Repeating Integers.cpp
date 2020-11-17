class Solution {
public:
    
    bool dfs(vector<int>& a, vector<int>& q, int i) {
        if (i==q.size()) return true;
        
        for (int j=0; j<a.size(); ++j) 
            if (a[j] >= q[i]) {
                a[j] -= q[i];
                if (dfs(a, q, i+1)) return true;
                a[j] += q[i];
            }
        return false;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& q) {
        sort(q.begin(), q.end(), std::greater<int>());
        unordered_map<int, int> freq;
        for (auto x : nums) ++freq[x];
        vector<int> a;
        for (auto& pr : freq) a.push_back(pr.second);
        sort(a.begin(), a.end(), std::greater<int>());
        
        return dfs(a, q, 0);
    }
};