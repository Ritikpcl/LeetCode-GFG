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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int numOfNodes = 0;
        ListNode* temp = head;
        vector<ListNode*> v(k);

        while(temp){
            temp = temp->next;
            numOfNodes++;
        }

        int x = numOfNodes / k;
        int extra = numOfNodes % k;
        temp = head;
        int i = 0;
        while(i<k){
            int a = x + (extra > 0);
            extra--;
            ListNode* start = temp, *prev = start;
            while(temp && a--){
                prev = temp;
                temp = temp->next;
            }
            if(prev) prev->next = NULL;
            v[i++] = start;
        }
        
        return v;
    }
};