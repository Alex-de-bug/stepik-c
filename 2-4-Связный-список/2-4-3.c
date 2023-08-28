size_t list_length( const struct list * alist ) {
    size_t count = 0;
    while(alist){
        count++;
        alist = (*alist).next;
    }
    return count;
}
