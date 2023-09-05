/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if(!head) return NULL;
        // unordered_map<Node*, int> mp;
        // Node* temp = head;
        // Node* new_head, *new_temp;
        // int i = 1;

        // while(temp){
        //     mp[temp] = i;
        //     Node* node = new Node(temp->val);
        //     if(i==1) {
        //         new_head = node;
        //         new_temp = new_head;
        //     }
        //     new_temp->next = node;
        //     new_temp = node;
        //     node->next = NULL;
        //     temp = temp->next;
        //     i++;
        // }

        // temp = head;
        // new_temp = new_head;
        // while(temp){
        //     int idx = mp[temp->random];
        //     Node* itr = new_head;
        //     while(--idx && itr){
        //         itr = itr->next;
        //     }

        //     new_temp->random = itr;
        //     temp = temp->next;
        //     new_temp = new_temp->next;
        // }

        // return new_head;


        if(!head) return NULL;
        Node* temp=head;
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        
        temp = head;
        Node* itr = temp->next, *new_head = itr;
        while(temp){
            if(temp->random)itr->random = temp->random->next;
            else itr->random = NULL;
            temp = itr->next;
            if(temp)itr = temp->next;
        }

        temp = head;
        itr = temp->next;
        // Node* prev = itr->next;
        while(itr){
            temp->next = itr->next;
            temp = temp->next;
            if(temp) itr->next = temp->next;
            itr = itr->next;
        }
        return new_head;
    }
};














