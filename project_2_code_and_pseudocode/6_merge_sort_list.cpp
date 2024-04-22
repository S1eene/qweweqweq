/*

Merge Function
- merge LIST1 and LIST2 into LIST

void merge(LIST1, LIST2, LIST, boolean COMPARATOR) 
{
    iterator1 -> LIST1.head                    
    iterator2 -> LIST2.head  

    iterator1 = LIST1.begin();
    iterator2 = LIST2.begin()

    loop while LIST1 and LIST2 have more nodes
        if COMPARE(LIST1 value, LIST2 value, COMPARATOR):    NOTE: (translates to LIST1 value < LIST2 value if COMPARATOR true or LIST1 value > LIST2 value if COMPARATOR false)
            copy LIST1 value to LIST2
            advance iterator1
        otherwise:
            copy LIST2 value to end of LIST
            advance iterator2
    end loop
    while () {}
    while (iterator1.hasNext()) {}
    while LIST1 has more nodes
        copy LIST1 value to end of LIST
        advance iterator1
    end loop

    while LIST2 has more nodes
        copy LIST2 value to end of LIST
        advance iterator2
    end loop

    while (iterator2.hasNext()) {}
}

MergeSort Function
- Recursively separate LIST into two sublists, then merge sublists back into LIST

void mergeSort(LIST, boolean COMPARATOR) 
{
    if LIST is empty: exit function

    create two sublists: LIST1, LIST2
    iterator -> LIST.head

    loop through first half of LIST (use LIST size to determine half)
        copy values from LIST to end of LIST1
        advance iterator
    end loop

    loop through second half of LIST (use LIST size to determine half)
        copy values from LIST to end of LIST2
        advance iterator 
    end loop

    clear LIST

    recurse on LIST1
    recurse on LIST2

    MERGE(LIST1, LIST2, LIST, COMPARATOR)
}

*/