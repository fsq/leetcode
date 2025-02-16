class Solution {
public:
    int numberOfSubstrings(string s) {
        deque<int> q;

        for (int i=0; i<s.size(); ++i)
            if (s[i] == '0')
                q.push_back(i);
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            while (q.size() && q.front() < i) q.pop_front();
            if (s[i]=='1') {
                if (q.empty()) {
                    ans += s.size() - i;
                } else {
                    ans += q[0] - i;
                }
            }
            for (int j=0; j<q.size(); ++j) {
                int num_zero = j + 1;
                int need_one = num_zero * num_zero;
                if (i + num_zero + need_one > s.size()) break;

                need_one -= (q[j] - i + 1 - num_zero);
                int dist_to_next_zero = j+1<q.size() ? q[j+1]-q[j] : s.size()-q[j];
                if (need_one <= 0) {
                    ans += dist_to_next_zero;
                } else {
                    ans += max(0, dist_to_next_zero - need_one);
                }
            }
        }
        return ans;
    }
};