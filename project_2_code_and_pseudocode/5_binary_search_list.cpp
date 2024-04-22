/*

Binary Search Function
- Returns iterator -> node (value found) OR iterator -> nullptr (value not found or list empty)
- use the COMPARE function to determine DATA is < or > then a LIST value
- use the EQUIVALENT function to determine if DATA is == to a LIST value
- If COMPARATOR is true, searches LIST in small to large order.
- If COMPARATOR is false, searches LIST in large to small order.
- Slow/fast pointer method is used to locate the middle node of the current START/END search zone.

Iterator binarySearch(LIST, DATA, boolean COMPARATOR)
{
    if LIST is empty: return iterator = nullptr (list is empty, nothing to search)

    create START and END node pointers: START -> head, END = nullptr

    loop while END != START                                                             NOTE: (while nodes remain that have not been checked)

        create MID and LAST node pointers: MID -> START, LAST -> node after START
        loop while LAST != END                                                          NOTE: ( slow/fast pointer technique to locate middle node between START and END nodes )
            advance LAST
            if LAST != END
                advance MID
                advance LAST 

        end loop                                                                        NOTE: ( LAST will reach end of list while MID will point to middle node )
    
        if EQUIVALENT(MID, DATA): return Iterator -> MID ( DATA is found )            
        otherwise, COMPARE(MID, DATA, COMPARATOR):  START -> node after MID             NOTE: (this translates to MID < DATA if COMPARATOR true or MID > DATA if COMPARATOR false)
        otherwise, END -> MID

    end loop  
    
    return Iterator -> nullptr (DATA was not found)
}

*/