class Solution {
public:
    int busyStudent(vector<int>& st, vector<int>& ed, int qt) {
        int ans = 0;
        for (int i=0; i<st.size(); ++i)
            if (st[i]<=qt && qt<=ed[i])
                ++ans;
        return ans;
    }
};