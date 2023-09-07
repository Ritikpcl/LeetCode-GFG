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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* h1 = head;
        ListNode* h2 = head;
        
        ListNode* prev = head;
        ListNode* temp = head;
        ListNode* end  = head;
        
        int n = right - left;
        
        if(n == 0) return head;
        
        while(--left)
        {
            h1 = prev;
            if(prev) prev = prev->next;
        }
        
        h2 = prev;
        if(prev) temp = prev->next;
        if(temp) end  = temp->next;
        
        while(n--)
        {
            if(temp) temp->next = prev;
            prev = temp;
            temp = end;
            if(end) end = end->next;
        }
        
        if(h2 == head)
        head = prev;
        else h1->next = prev;
        
        h2->next = temp;
        
        return head;
    }
};