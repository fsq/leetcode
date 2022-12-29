/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> a(n, vector<int>(m, -1));
        int i=0, j=0, rm = n*m, d = 0;
        for (auto p=head; p && rm; --rm, p=p->next) {
            a[i][j] = p->val;
            int ti=i+dx[d], tj=j+dy[d];
            if (!(ti>=0 && ti<n && tj>=0 && tj<m &&a[ti][tj]==-1)) {
                d = (d+1) % 4;
                ti=i+dx[d], tj=j+dy[d];
            }
            i = ti;
            j = tj;
        }
        return a;

    }
};