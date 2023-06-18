class Solution {
public:
    int countSubarrays(vector<int>& a, int k) {
        unordered_map<int, int> odd, even;
        odd[0] = 1;
        int ans = 0;
        bool meet = false;
        for (int i=0,s=0; i<a.size(); ++i) {
            if (a[i]==k) {
                meet = true;
            }
            if (a[i] > k) ++s; else if (a[i] < k) --s;
            if (meet) {
                if (i & 1) {
                    ans += odd[s-1] + even[s];
                } else {
                    ans += odd[s] + even[s-1];
                }
            }
            if (i & 1) {
                ++odd[s];
            } else {
                ++even[s];
            }
        }
        return ans;
    }
};