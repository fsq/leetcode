class Solution {
public:

    int f(vector<int>& a, int cap) {
        int cnt = 0;
        bool pre = false;
        for (auto x : a) {
            if (x <= cap && !pre) {
                ++cnt;
                pre = true;
            } else {
                pre = false;
            }
        }
        return cnt;
    }

    int minCapability(vector<int>& a, int k) {
        int l=1, r=*max_element(a.begin(), a.end());
        while (l < r) {
            auto mid = (l+r) >> 1;
            auto pk = f(a, mid);
            // cout << mid << ' ' << pk << endl;
            if (pk < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};