int64_t list_sum( const struct list* list ) {
    if(list == NULL){
        return 0;
    }
    return (*list).value + list_sum((*list).next);
}
