struct list* list_read() {
    struct list* answer = node_create(0);
    struct maybe_int64 x = maybe_read_int64();
    if(x.valid){
        answer -> value = x.value;
    }else{
        return answer;
    }
    struct list* old = answer;
    while(x.valid){
        x = maybe_read_int64();
        if(x.valid){
            struct list* new = node_create(x.value);
            old -> next = new;
            old = new;
        }  
    }
    return answer;
}
