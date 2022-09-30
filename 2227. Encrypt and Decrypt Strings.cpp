class Encrypter {
public:
    unordered_map<char, string> m;
    unordered_map<string, int> allow;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i=0; i<keys.size(); ++i)
            m[keys[i]] = values[i];
        for (auto& s : dictionary) {
            ++allow[encrypt(s)];
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for (auto c : word1)
            if (!m.count(c)) {
                return "";
            } else {
                ans += m[c];
            }
        return ans;
    }
    
    int decrypt(string word2) {
        return allow[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */