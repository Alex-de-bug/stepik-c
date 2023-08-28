struct maybe_int64 list_at(  const struct list* alist, size_t idx ) {
    size_t count = 0;
    while(alist){
        if(count == idx){
            return some_int64(alist -> value);
        }
        count++;
        alist = (*alist).next;
    }
    return none_int64;
}
