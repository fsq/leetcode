class Solution {
public:
    
    // https://leetcode.com/problems/next-greater-element-iii/description/
    // O(n) using std::next_permutation
    
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        next_permutation(s.begin(), s.end());
        auto x = stoll(s);

        return (x<=n || x>INT_MAX) ? -1 : x;
    }
};