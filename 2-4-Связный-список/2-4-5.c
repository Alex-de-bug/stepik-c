struct list* list_last( struct list * list ) {
    if(list == NULL){
        return NULL;
    }
  while(true){
      if((*list).next == NULL){
          return list;
      }
      list = list -> next;
  }
}
