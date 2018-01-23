/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    // https://leetcode.com/problems/delete-node-in-a-linked-list/description/
    
    void deleteNode(ListNode* node) {
        auto nxt = node->next;
        *node = *nxt;
        delete nxt;
    }
};