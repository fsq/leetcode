class Solution {
public:
    int numOfStrings(vector<string>& s, string word) {
        return count_if(s.begin(), s.end(), [&](const string& t){
            return word.find(t) != string::npos;
        });
    }
};