class Solution {
public:
    int longestSubarray(vector<int>& a, int limit) {
        deque<int> mn, mx;
        int ans = 0;
        for (int l=0,r=0; r<a.size(); ++r) {
            while (mn.size() && a[r]<=a[mn.back()]) mn.pop_back();
            while (mx.size() && a[r]>=a[mx.back()]) mx.pop_back();
            mn.push_back(r);
            mx.push_back(r);
            
            while (abs(a[mx.front()]-a[mn.front()])>limit) {
                if (mx.front()==l) mx.pop_front();
                if (mn.front()==l) mn.pop_front();
                ++l;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};