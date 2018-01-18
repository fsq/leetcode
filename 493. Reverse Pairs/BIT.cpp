class Solution {
public:
    
    // BIT solution
    // O(nlogn) time 
    // O(n) space
    
    inline int lowbit(int x) {
        return x & -x;
    }
    
    void add(vector<int>& s, int i, int delta) {
        for (++i; i<s.size(); i+=lowbit(i))
            s[i] += delta;
    }
    
    int sum(const vector<int>& s, int i) {
        int ret = 0;
        for (++i; i>0; i-=lowbit(i))
            ret += s[i];
        return ret;
    }
    
    int reversePairs(vector<int>& nums) {
        vector<pair<long long,int>> a;
        int n = nums.size();
        
        for (int i=0; i<n; ++i) 
            a.push_back({nums[i], i});
        
        sort(a.begin(), a.end(), greater<pair<int,int>>());
        
        vector<int> s(n+1, 0);
        
        int ans = 0, ptr = 0;
        for (int i=0; i<n; ++i) {
            // add all indices to BIT where a[index]>a[i]*2
            while (ptr<n && a[ptr].first>(a[i].first<<1)) 
                add(s, a[ptr++].second, 1);
            
            // count # indices <i
            ans += sum(s, a[i].second-1);
        }
        
        return ans;
    }
};