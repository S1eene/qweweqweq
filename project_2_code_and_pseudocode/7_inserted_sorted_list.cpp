/*

Insert Sorted Function
- use the COMPARE function to determine if DATA is < or > then a LIST value
- If COMPARATOR is true, sorts LIST from small to large
- If COMPARATOR is false, sorts LIST from large to small

void insertSorted(LIST, DATA, boolean COMPARATOR) 
{
    Create CURRENT node pointer: CURRENT -> head

    if list is empty or compare(DATA, CURRENT, COMPARATOR)                                          NOTE: (this translates to DATA < CURRENT if COMPARATOR true or DATA > CURRENT if COMPARATOR false)
        add DATA to the front of the list
        exit function

    loop while CURRENT.next is not the end of list and compare(CURRENT.next, DATA, COMPARATOR)      NOTE: (this translates to CURRENT.next < DATA and COMPARATOR true or CURRENT.next > DATA and COMPARATOR false)
        advance CURRENT to next node
    end loop

    create TEMP node pointer to store DATA
    insert TEMP node after CURRENT (update all required pointers)
    if CURRENT was tail, TEMP becomes new tail
    increment list size
}

*/