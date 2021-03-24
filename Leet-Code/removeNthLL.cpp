
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEndSF(ListNode* head, int n){
    
    
    ListNode *main = new ListNode(-1,head);
    ListNode* slow = main;
    ListNode* fast = main;
    int count = 0;
    
    while(fast->next != NULL){
        
        if(count!= n){
            fast = fast->next;
            count++;
        }
        else{
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    slow->next = slow->next->next;
    
    return main->next;
    
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    
    
    int length = 0;
    
    ListNode* temp = head;
    
    while (temp!= NULL) {
        length++;
        temp = temp->next;
    }
    
    if(length == 1){
        return NULL;
    }
    
    temp = head;
    int index = 0;
    int removeIndex = length - n;
    
    if(removeIndex == 0){
        head = head->next;
        return head;
    }
    
    while ((index + 1) != removeIndex && temp!= NULL) {
        temp = temp->next;
        index++;
    }
    
    temp->next = temp->next->next;
    return head;
    
}



void printLL(ListNode *head){
    while (head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
