class Solution {
public:
    // https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
    // O(nlogn+n^2*l) time, l is avg length of each string
    // O(n) space for map
    // sort & check
    
    static bool cmp(const string& s, const string& t) {
        return s.size() > t.size();
    }
    
    bool is_subseq(const string& s, const string& t) {
        if (t.empty()) return true;
        
        int p=0, q=0;
        while (p<s.size() && q<t.size())
            if (s[p]==t[q]) {
                ++p;
                ++q;
            } else 
                ++p;
        return q==t.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        // sort and check longer strings first
        sort(strs.begin(), strs.end(), cmp);
        
        // # occurrences of a string
        unordered_map<string, int> count;
        for (auto& s : strs) ++count[s];
        
        for (int i=0; i<strs.size(); ++i) 
            // string should appear only once 
            if (count[strs[i]]==1) {
                bool valid = true;
                for (int j=0; j<i; ++j) 
                    if (is_subseq(strs[j], strs[i])) {
                        valid = false;
                        break;
                    }
                // not a subseq of any strings
                if (valid) return strs[i].size();
            }
        return -1;
    }
};