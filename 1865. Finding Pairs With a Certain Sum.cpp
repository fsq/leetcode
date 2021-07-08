class FindSumPairs {
public:
    unordered_map<int, int> m;
    vector<int> a, b;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for (auto x : b) ++m[x];
    }
    
    void add(int index, int val) {
        --m[b[index]];
        b[index] += val;
        ++m[b[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto x : a) 
            if (m.count(tot-x))
                ans += m[tot-x];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */