// class MyHashMap {
// public:

//     class List{
//         public:
//         int key;
//         int val;
//         List* next;

//         List(int key, int val){
//             this->key = key;
//             this->val = val;
//             this->next = NULL;
//         }
//     };

//     vector<List*> v;
//     int size = 15000;

//     MyHashMap() {
//         v.resize(size);
//     }
    
//     void put(int key, int value) {
        
//         int idx = key % size;

//         if(v[idx] == NULL){
//             List* newNode = new List(key,value);
//             v[idx] = newNode;
//             return;
//         }

//         List *itr = v[idx], *prev = itr;
        
//         while(itr && itr->key != key) {
//             prev = itr;
//             itr = itr->next;
//         }

//         if(itr == NULL){
//             List *newNode = new List(key,value);
//             prev->next = newNode;
//             return;
//         }else{
//             itr->val = value;
//         }
//     }
    
//     int get(int key) {
//         int idx = key % size;
//         List* itr = v[idx];
//         while(itr && itr->key != key){
//             itr = itr->next;
//         }

//         if(itr == NULL) return -1;
//         else return itr->val;
//     }
    
//     void remove(int key) {
//         int idx = key % size;
//         if(v[idx] == NULL) return;
        
//         List *itr = v[idx], *prev = NULL, *end = itr->next;
//         while(end && itr->key != key){
//             prev = itr;
//             itr = end;
//             end = end->next;
//         }

//         if(itr->key == key){
//             if(prev == NULL) v[idx] = NULL;
//             else prev->next = end;
//         }
//     }
// };

// /**
//  * Your MyHashMap object will be instantiated and called as such:
//  * MyHashMap* obj = new MyHashMap();
//  * obj->put(key,value);
//  * int param_2 = obj->get(key);
//  * obj->remove(key);
//  */

struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};
class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size] = {};
    int hash(int key) {
        return (int)((long)key * mult % size);
    }
    void put(int key, int val) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) return;
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        } else for (; node->next != NULL; node = node->next)
            if (node->next->key == key) {
                Node* temp = node->next;
                node->next = temp->next;
                delete temp;
                return;
            }
    }
};