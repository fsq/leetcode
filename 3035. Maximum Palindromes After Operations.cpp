class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<char, int> cnt;
        int odd=0, even=0;
        vector<int> len;
        for (auto& s : words) {
            len.push_back(s.size());
            for (auto c : s) ++cnt[c];
        }
        for (auto& pr: cnt) {
            if (pr.second & 1) {
                ++odd;
                --pr.second;
            }
            even += pr.second;
        }
        sort(len.begin(), len.end());
        int ans = 0;
        for (auto l : len) {
            if (l & 1) {
                if (odd) {
                    --odd;
                } else {
                    even -= 2;
                    ++odd;
                }
                --l;
            }
            if (even >= l) {
                ++ans;
                even -= l;
            } else
                break;
        }
        return ans;
    }
};