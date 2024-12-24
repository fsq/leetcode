class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int,char>, vector<pair<int,char>>, std::greater<pair<int,char>>> q;
        vector<int> m(26);
        for (auto c : s) 
            if (c != '?') 
                ++m[c-'a'];
        for (int i=0; i<26; ++i) q.push({m[i], 'a'+i});
        string t;
        for (auto c: s)
            if (c == '?') {
                auto pr = q.top();
                q.pop();
                c = pr.second;
                ++pr.first;
                q.push(pr);
                t.push_back(c);
            }
        sort(t.begin(), t.end());
        int i =0;
        for (auto& c: s)
            if (c == '?')
                c = t[i++];
        return s;
    }
};