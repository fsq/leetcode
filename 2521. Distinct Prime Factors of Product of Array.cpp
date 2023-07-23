class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        for (auto x : nums) {
            int d = 2;
            while (x > 1)
                if (x % d == 0) {
                    st.insert(d);
                    while (x % d == 0) x /= d;
                } else 
                    ++d;

        }
        return st.size();
    }
};