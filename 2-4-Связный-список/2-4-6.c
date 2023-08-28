void list_add_back( struct list** old, int64_t value ) {
    if(!(*old)){
        list_add_front(old, value);
    }else{
        //list_last(*old) -> next = malloc(sizeof(struct list));
        list_last(*old) -> next = node_create(value);
    }
}
