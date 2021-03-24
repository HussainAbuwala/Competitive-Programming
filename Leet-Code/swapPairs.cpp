class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        else if(head->next == NULL) return head;
        
        ListNode *a = NULL;
        ListNode *b = NULL;
        ListNode *c = NULL;
        head = new ListNode(-1,head);
        
        a = head;
        b = a->next;
        c = b->next;
        
        
        while (true) {
            b->next = c->next;
            c->next = b;
            a->next = c;
            
            a = b;
            if(a->next == NULL)
                break;
            
            b = a->next;
            if(b->next == NULL) 
                break;
            
            c = b->next;
        }
        
        head = head->next;
        return head;
    } 
        
};