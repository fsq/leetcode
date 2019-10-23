class Solution {
public:
    vector<string> removeSubfolders(vector<string>& a) {
        sort(a.begin(), a.end());
        vector<string> ans;
        for (int now=0, i; now<a.size(); ) {
            string s = a[now];
            ans.push_back(s);
            s += '/';
            for (i=now+1; i<a.size(); ++i) 
                if (!(s.size()<=a[i].size() && equal(s.begin(), s.end(), a[i].begin()))) 
                    break;
            now = i;
        }
        return ans;
    }
};