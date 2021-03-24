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


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> nodeMap;
        Node *tempOld = head;
        Node *headNew = new Node(-1);
        Node *tempNew = headNew;
        
        while (tempOld != NULL){
            tempNew->next = new Node(tempOld->val);
            nodeMap[tempOld] = tempNew->next;
            tempNew = tempNew->next;
            tempOld = tempOld->next;
        }
        
        tempOld = head;
        headNew = headNew->next;
        tempNew = headNew;
        
        while (tempOld != NULL){
            if(tempOld->random != NULL){
                tempNew->random = nodeMap[tempOld->random];
            }
            tempNew = tempNew->next;
            tempOld = tempOld->next;
        }
        
        return headNew;
        
    }
};