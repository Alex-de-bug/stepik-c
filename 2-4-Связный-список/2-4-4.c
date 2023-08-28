void list_destroy( struct list* list ) {
    if(list == NULL){
        return;
    }
    list_destroy((*list).next);
    //printf("% " PRId64, (*list).value);
    free(list);
    return;
}
