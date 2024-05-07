# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        values = []
        val = 0
        
        while head is not None:
            values.append(head.val)
            head = head.next
        
        new_tail = None
        while values or val != 0:
            new_tail = ListNode(0, new_tail)
            if values:
                val+= values.pop()*2
            new_tail.val = val%10
            val //=10
        
        return new_tail