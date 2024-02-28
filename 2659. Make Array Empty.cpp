class Solution {
public:
    vector<int> s;

    int lowbit(int x) {
        return x & (-x);
    }

    int sum(int x) {
        int tot = 0;
        for (++x; x>0; x-=lowbit(x)) tot += s[x];
        return tot;
    }

    void mark(int x) {
        for (++x; x<s.size(); x+=lowbit(x)) ++s[x];
    }

    long long countOperationsToEmptyArray(vector<int>& nums) {
        s.resize(nums.size() + 1);
        vector<vector<int>> a;
        for (int i=0; i<nums.size(); ++i)
            a.push_back({nums[i], i});
        sort(a.begin(), a.end());
        long long ans = 0;
        int cur = 0, put = 0;
        for (auto& pr : a) {
            int x = pr[1];
            if (cur <= x) {
                ans += x - cur - (sum(x-1) - sum(cur-1));
            } else {
                ans += x+a.size()-cur - (put-sum(cur-1) + sum(x-1));
            }
            cur = x;
            ++ans;
            mark(cur);
            ++put;
        }
        return ans;
    }
};