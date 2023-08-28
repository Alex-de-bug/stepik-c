void list_add_front( struct list** old, int64_t value );

// создать перевернутую копию списка
struct list* list_reverse( const struct list * list ) {
    if ( list_length( list ) <= 0 ){
        return NULL;
    }
    struct list* new = malloc(sizeof(struct list));
    new -> value = list -> value;
    new -> next = NULL;
    list = list -> next;
    while(list){
        list_add_front(&new, list -> value);
        list = list -> next;
    }
    return new;
  
}
