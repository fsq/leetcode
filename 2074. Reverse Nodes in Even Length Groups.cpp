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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<ListNode*> a;
        for (auto p=head; p; p=p->next) a.push_back(p);
        for (int len=1, i=0; i<a.size(); ++len) {
            int j = min<int>(a.size(), i+len);
            if (!((j-i) & 1)) {
                reverse(a.begin()+i, a.begin()+j);
            }
            i = j;
        }
        for (int i=0; i+1<a.size(); ++i) a[i]->next = a[i+1];
        a.back()->next = nullptr;
        return a[0];
    }
};