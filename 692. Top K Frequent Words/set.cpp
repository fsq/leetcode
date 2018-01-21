class Solution {
public:
    
    // https://leetcode.com/problems/top-k-frequent-words/description/
    // set O(n+nlogk) time O(k) space solution
    
    struct cmp {
        bool operator() (const pair<int,string>&a, const pair<int,string>& b)   {
            return a.first<b.first || a.first==b.first&&a.second>b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto & s : words) ++freq[s];
        
        set<pair<int, string>, cmp> st;
        
        for (auto& kv : freq) 
            if (st.size()<k || st.size()==k && (kv.second>st.begin()->first || 
                kv.second==st.begin()->first && kv.first<st.begin()->second)) {
                if (st.size()==k) st.erase(st.begin());
                st.insert({kv.second, kv.first});
            }
        
        vector<string> ans;
        for (auto &pr : st)
            ans.push_back(pr.second);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};