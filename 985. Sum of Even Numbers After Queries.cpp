class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto x : a)
            sum += x * !(x & 1);
        
        vector<int> ans;
        for (auto& q : queries) {
            if (!(a[q[1]] & 1)) sum -= a[q[1]];
            a[q[1]] += q[0];
            if (!(a[q[1]] & 1)) sum += a[q[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};