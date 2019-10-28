class Solution {
public:
    int numUniqueEmails(vector<string>& a) {
        unordered_set<string> st;
        
        for (const auto& s : a) {
            int p = s.find_last_of('@');
            string local = s.substr(0, p);
            local = local.substr(0, local.find('+'));
            string now;
            for (auto c : local) 
                if (c != '.')
                    now += c;
            now += s.substr(p);
            st.insert(now);
        }
        
        return st.size();
    }
};