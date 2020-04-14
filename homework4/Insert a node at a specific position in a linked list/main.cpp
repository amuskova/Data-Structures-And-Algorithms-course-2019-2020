SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
     SinglyLinkedListNode *newnode = new SinglyLinkedListNode(data);
     newnode->data=data;
     SinglyLinkedListNode *help = head;
    SinglyLinkedListNode *prev;
    for(int i=0;i<position ;i++)
    {
        prev=help;
        help=help->next;
    }

    prev->next=newnode;
    newnode->next=help;
    return head;
}
