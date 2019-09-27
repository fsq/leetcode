# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, p: ListNode) -> bool:
        a = []
        while p: 
            a.append(p.val)
            p = p.next
        return a[::-1] == a