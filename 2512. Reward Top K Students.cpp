class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        vector<pair<int,int>> s;
        for (int i=0; i<student_id.size(); ++i) {
            int id = student_id[i];
            istringstream sin(report[i]);
            string w;
            int score = 0;
            while (sin >> w)
                if (pos.count(w))
                    score += 3;
                else if (neg.count(w))
                    score -= 1;
            s.push_back({-score, id});
        }
        sort(s.begin(), s.end());
        vector<int> ans;
        for (auto& pr : s) ans.push_back(pr.second);
        ans.resize(k);
        return ans;
    }
};