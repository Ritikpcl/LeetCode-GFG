/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        Node* head = NULL, *tail = NULL, *mainRoot = root;
        
        while(root){
            if(root->left){
                if(tail){
                    tail->next = root->left;
                    tail = tail->next;
                }else head = root->left, tail = root->left;
            }

            if(root->right){
                if(tail){
                    tail->next = root->right;
                    tail = tail->next;
                }else head = root->right, tail = root->right;
            }

            root = root->next;
            if(!root){
                root = head;
                head = NULL;
                tail = NULL;
            }
        }

        return mainRoot;
    }
};