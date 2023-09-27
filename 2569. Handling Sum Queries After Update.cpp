class Solution {
public:
    static const int N = 100005;
    vector<long long> handleQuery(vector<int>& a, vector<int>& b, vector<vector<int>>& queries) {
        vector<long long> ans;
        bitset<N> st;
        long long sum = 0;
        for (int i=0; i<a.size(); ++i) {
            sum += b[i];
            if (a[i]) st[i] = true;
        }
        for (auto& q : queries)
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                bitset<N> cur;
                cur.flip();
                cur >>= l;
                cur <<= l + (N-1-r);
                cur >>= N-1-r;
                st ^= cur;
            } else if (q[0] == 2) {
                sum += (long long)st.count() * q[1];
            } else {
                ans.push_back(sum);
            }
        return ans;
    }
};