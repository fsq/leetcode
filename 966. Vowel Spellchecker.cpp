class Solution {
public:
    vector<string> spellchecker(vector<string>& list, vector<string>& q) {
        vector<string> ans;
        unordered_set<string> words(list.begin(), list.end());
        string vowel = "aeiou";
        
        unordered_map<string, string> cap;
        unordered_map<string, string> vow;
        for (auto& s : list) {
            string low = s;
            for (auto& c : low) c = tolower(c);
            if (!cap.count(low)) cap[low] = s;
            string v = low;
            for (auto& c : v) 
                if (vowel.find(c)!=string::npos)
                    c = '#';
            if (!vow.count(v)) vow[v] = s;
        }
        
        
        for (auto& s : q) 
            if (words.count(s))
                ans.push_back(s);
            else {
                for (auto& c : s) c = tolower(c);
                if (cap.count(s)) 
                    ans.push_back(cap[s]);
                else {
                    for (auto& c : s) 
                        if (vowel.find(c)!=string::npos)
                            c = '#';
                    if (vow.count(s))
                        ans.push_back(vow[s]);
                    else 
                        ans.push_back("");
                }
            }
            
        return ans;
        
    }
};