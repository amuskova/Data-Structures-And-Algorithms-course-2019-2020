SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *current= head;
    SinglyLinkedListNode *prev=NULL;
    //prev->next=NULL;
    SinglyLinkedListNode *next=NULL;
    //next->next=NULL;
    while(current != NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;

}
