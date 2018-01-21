class Solution {
public:
    
    // https://leetcode.com/problems/top-k-frequent-words/description/
    // priority_queue O(n+klogn) time O(n) space 
    // building a heap only uses O(n) time
    
    struct cmp {
        bool operator ()(const pair<int,string>& a, const pair<int,string>& b) {
            return a.first < b.first || a.first==b.first && a.second>b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto& word : words) ++count[word];
        
        vector<pair<int,string>> freq;
        for (auto& kv : count)
            freq.push_back({kv.second, kv.first});
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> q(freq.begin(), freq.end());
        
        vector<string> ans;
        while (ans.size()<k) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};