//Only works with random access iterators
template <class Iterator, class Element>
Iterator my_binary_search (Iterator begin, Iterator end, const Element& key){
    Iterator not_found = end;
    while (begin <= end){
        Iterator mid = begin + (end - begin)/2;
        if (*mid == key)
            return mid;
        
        else if (key > *mid){ //search the right half
            begin = mid+1;
        }
        
        else{ //search the left half
            end = mid-1;
        }
    }
    return not_found;
}
