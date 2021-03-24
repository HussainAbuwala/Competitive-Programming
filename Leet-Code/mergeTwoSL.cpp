
class Solution {
public:
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        
        ListNode* head = NULL;
        ListNode* temp = NULL;
        
        if(l1->val <= l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        temp = head;
        
        while(l1 != NULL && l2!= NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        
        if(l1 != NULL){
            while (l1 != NULL) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
        }
        
        if(l2 != NULL){
            while (l2 != NULL) {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        
        return head;
        
    }
    
    
    /*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        head = new ListNode;
        tail = head;
        while(l1 != NULL && l2!= NULL){
            if(l1->val == l2->val){
                tail->next = new ListNode(l1->val,new ListNode(l2->val, NULL));
                tail = tail->next->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1->val < l2->val){
                tail->next = new ListNode(l1->val,NULL);
                tail = tail->next;
                l1 = l1->next;
            }
            else{
                tail->next = new ListNode(l2->val,NULL);
                tail = tail->next;
                l2 = l2->next;
            }
        }
        
        if(l1 != NULL){
            while (l1 != NULL) {
                tail->next = new ListNode(l1->val,NULL);
                tail = tail->next;
                l1 = l1->next;
            }
        }
        
        if(l2 != NULL){
            while (l2 != NULL) {
                tail->next = new ListNode(l2->val,NULL);
                tail = tail->next;
                l2 = l2->next;
            }
        }
        
        head = head->next;
        return head;
    }*/
};