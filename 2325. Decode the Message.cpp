class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> f(26, -1);
        for (int i=0, ind=0; i<key.size(); ++i)
            if (isalpha(key[i]) && f[key[i]-'a'] == -1) {
                f[key[i]-'a'] = ind;
                ++ind;
            }
                
        for (auto& c : message)
            if (isalpha(c))
                c = f[c-'a'] + 'a';
        return message;
    }
};