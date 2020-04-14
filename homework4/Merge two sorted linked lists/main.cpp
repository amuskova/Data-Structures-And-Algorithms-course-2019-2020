SinglyLinkedListNode* merge(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode* newnode;
    if(head1==NULL)
    {
        return head2;
    }
    else if(head2 ==NULL)
    {
        return head1;
    }
    if(head1->data < head2->data){
        newnode = head1;
        newnode->next = merge(head1->next,head2);
    }
    else{
        newnode = head2;
        newnode->next = merge(head1,head2->next);
    }

    return newnode;
}
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *merged=new SinglyLinkedListNode(100);
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }
    if(head1->data < head2->data){
        merged = head1;
        merged->next = merge(head1->next,head2);
    }
    else{
        merged = head2;
        merged->next = merge(head1,head2->next);
    }

    return merged;


}
