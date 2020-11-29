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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto *front = list1, *back = front;
        int i;
        for (i=1; i<a; ++i) {
            front = front->next;
            back = back->next;
        }
        for (; i<=b+1; ++i) back = back->next;
        front->next = list2;
        
        auto last = list2;
        while (last->next) last = last->next;
        last->next = back;
        return list1;
        
    }
};