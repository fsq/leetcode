class Solution {
public:
    int countCompleteSubstrings(string s, int k) {
        vector<int> d = {0};
        int ans = 0;
        for (int i=1; i<s.size(); ++i) d.push_back(abs(s[i]-s[i-1]));
        for (int len=k; len<=26*k && len<=s.size(); len+=k) {
            vector<int> cnt(128);
            deque<int> q; // mono queue, range max
            int numk = 0;
            for (int i=0; i<s.size(); ++i) {
                ++cnt[s[i]];
                while (q.size() && d[i]>=d[q.back()]) q.pop_back();
                q.push_back(i);

                if (cnt[s[i]] == k) 
                    ++numk;
                else if (cnt[s[i]] == k+1)
                    --numk;
                if (i-len>=0) {
                    --cnt[s[i-len]];
                    while (q.size() && q.front()<=i-len+1) q.pop_front();
                    if (cnt[s[i-len]] == k)
                        ++numk;
                    else if (cnt[s[i-len]] == k-1)
                        --numk;
                }
                if (numk*k == len && (q.empty() || d[q.front()]<=2)) ++ans;
            }
        }
        return ans;
    }
};