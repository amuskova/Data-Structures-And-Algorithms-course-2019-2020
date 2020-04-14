SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode *curent = head;
    SinglyLinkedListNode *prev;
    if(head==NULL)
    {
        return head;
    }
    if(position == 0)
    {
        prev=curent;
        curent=curent->next;
        delete prev;
        return curent;
    }
    for(int i = 0 ; i < position  ; i++)
    {
        prev=curent;
        curent=curent->next;
    }
    if(curent == NULL)
    {
        prev->next= NULL;
        return head;
    }
    prev->next= curent->next;
    delete curent;
    return head;

}
