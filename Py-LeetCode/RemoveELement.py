#!/urs/bin/env python
import showlink
class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        if not head:
            return None
        nnode = head
        while nnode.val == val:
            nnode = nnode.next
            if not nnode:
                return None
        nhead = nnode
        next = nnode.next
        while next:
            if next.val == val:
                next = next.next
                nnode.next = next
            else:
                nnode = next
                next = next.next
        return nhead
        
if __name__ == "__main__":
    arr = [1]
    link = showlink.ListLink(arr)
    print "link "
    link.show()
    s = Solution()
    link.head = s.removeElements(link.head, 1)
    print "remove"
    link.show()

