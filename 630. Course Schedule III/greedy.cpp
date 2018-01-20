class Solution {
public:
    
    // https://leetcode.com/problems/course-schedule-iii/description/
    // O(nlogn) greedy algorithm
    // sort ascendingly ordered by close day
    // add each course to the set if possible
    // else swap with the course which has longest duration
    
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        
        int end=0;
        priority_queue<int> durations;
        for (auto &course : courses)
            if (end+course[0]<=course[1]) {
                end += course[0];
                durations.push(course[0]);
            } else if (!durations.empty() && course[0]<durations.top()) {
                end += course[0];
                durations.push(course[0]);
                end -= durations.top();
                durations.pop();
            }
        return durations.size();
    }
};