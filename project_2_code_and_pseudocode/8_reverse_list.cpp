/*

Reverse Function

void List::reverse() 
{
    create CURRENT, PREV and TEMP node pointers: 
    CURRENT -> head, PREV = nullptr, TEMP = nullptr
    Node *current = head;
    Node *PREV = nullptr;
    Node *TEMP;

    loop while CURRENT != nullptr
        TEMP = CURRENT.next

        CURRENT.next = PREV
        CURRENT.prev = TEMP (doubly linked list only)

        PREV = CURRENT
        CURRENT = TEMP
    end loop

    while (CURRENT != nullptr) {
         TEMP = CURRENT->next;
         CURRENT->next = PREV;
         CURRENT->prev = TEMP;

         PREV = CURRENT;
         CURRENT = TEMP;

    }

    tail = head
    head = PREV
}

*/